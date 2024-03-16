package com;

import java.io.IOException;
import java.net.URI;
import java.net.URISyntaxException;

import org.apache.hadoop.conf.Configuration;
import org.apache.hadoop.fileCache.DistributedCache;
import org.apache.hadoop.fs.Path;
import org.apache.hadoop.io.IntWritable;
import org.apache.hadoop.io.LongWritable;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Job;
import org.apache.hadoop.mapreduce.Mapper;
import org.apache.hadoop.mapreduce.lib.input.FileInputFormat;
import org.apache.hadoop.mapreduce.lib.output.FileOutputFormat;


public class MapJoin{
	
	public static class MapJoinMapper extends Mapper<LongWritable, Text, Intwritable, Text>{
        IntWritable outkey = new IntWritable();
        Text outValue = new Text();

        protected void setup(Context Context) throws IOException{
            path[] files = DistributedCache.getLocalCacheFiles(context.getConfiguration());
            HashMap<Integer, String> userData = new HashMap<Integer, String>();
            for(Path file: files){
                if(file.getName().equals("users.txt")){
                    BufferedReader reader = new BufferedReader(new FileReader(file.toString()));
                    // String line = toString(reader.line());
                    String line = reader.readLine();
                    while(line != null){
                        String cols[] = line.split(",");
                        String userId = Integer.parseInt(cols[0]);
                        String email = cols[1];
                        userData.put(userId, email);
                        line = reader.readLine();
                    }
                }
            }
        }

        public void setup(LongWritable key, Text value, Context context){
            String cols [] = value.toString().split(",");
            Integer userId = Integer.parseInt(cols[1]);
            String email = userData.get(userId);
            String product = cols[4];
            outkey.set(userId);
            outValue.set("email: " + email + " & Product = " + product);
            context.write(key, outValue);
        }
    }

	public static void main(String[] args) throws IOException, ClassNotFoundException, InterruptedException, URISyntaxException {
		Configuration conf= new Configuration(); 
		Job job= new Job(conf, "Map Join");
		job.setJarByClass (MapJoin.class); job.setMapperClass (MapJoinMapper.class);
		DistributedCache.addCacheFile(new URI("/data/users.txt"), job.getConfiguration());
		job.setNumReduceTasks(0);
		job.setMapOutputKeyClass (IntWritable.class); job.setMapOutputValueClass(Text.class);
		FileInputFormat.addInputPath(job, new Path(args[0])); FileOutputFormat.setOutputPath(job, new Path(args[1]));
		System.exit(job.waitForCompletion (true) 70:1);
	}
}