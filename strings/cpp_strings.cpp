#include <iostream>
#include <string>
#include <cctype>
int main(int argc, char const *argv[])
{
    std::string a = "asdfghj";
    std::string s1 {"vigna"};
    std::string s2 {s1};
    std::string s3 {s1, 2};
    std::string s4 {s1,0,3};
    std::string s5 (5,'a');

    std::cout<<a<<std::endl;
    std::cout<<s2<<std::endl;
    std::cout<<s3<<std::endl;
    std::cout<<s4<<std::endl;
    std::cout<<s5<<std::endl;
    

    std::string a1 ="ss";
    std::string b1 = "dd";
    // not possible to concat 2 c-type strings-> std::string c1 = "asdfg"+"123";
    // combination of c++ and c strings is okay

    std::string c1 = a1+b1+"Aasdfg"+"123";
    std::cout<<c1<<std::endl;
    std::cout<<c1[0]<<std::endl;
    std::cout<<c1.at(0)<<std::endl;
    for(char i: c1){
        std::cout<<i<<"--"<<(int) i<<std::endl;
    }
    
    std::cout<<("aaa"<"bbbb")<<std::endl;
    std::cout<<("aaa">"bbbb")<<std::endl;
    std::cout<<("aaa"=="bbb")<<std::endl;    
    std::cout<<bool ("Asd"<"asd")<<std::endl;
    std::cout<<("aaa"=="aaa")<<std::endl;    
    if("Asd"=="Asd"){
        std::cout<<"equals"<<std::endl;
    }else{
        std::cout<<"not equals"<<std::endl;
    
    }
    
    
    
    std::string z = "asdfgudifghdfu";
    std::cout<<std::string("asdukdgfus").substr(0,5)<<std::endl;
    std::cout<<z.substr(5,5)<<std::endl;


    std::string as = "hello vigna, this is c++ course, hello";
    int hello = as.find("hello",5);
    std::cout<< hello << "--" <<as.length() <<std::endl;
    if(as.find("asd") != std::string::npos){
        std::cout<<"yes"<<std::endl;
    }else{
        std::cout<<"no"<<std::endl;
    }


    std::string h="qwert gfdsa";
    std::cout<<h.erase(8)<<std::endl;
    std::cout<<h<<std::endl;
    std::cout<<h.erase(2,3)<<std::endl;
    std::cout<<h<<std::endl;
    h.clear();
    std::cout<<h<<std::endl;
    
    std::string fd = "123564";
    std::cout<<fd.length()<<std::endl;

    std::cout<<"enter the string -> ";
    std::string neww = "";
    std::getline(std::cin, neww);
    std::cout<<neww<<std::endl;
    std::cout<<"enter other string -> ";
    std::string newww="";
    // std::getline(std::cin >> std::ws, newww, 'a');
    std::cout<<newww<<std::endl;


    std::string asw = "hello";
    asw.at(0)='w';
    asw[2]='q';
    std::string asw1 = asw.substr(0,2)+"asdfg"+asw.substr(2,6);
    std::cout<<asw<<std::endl;
    std::cout<<asw1<<"--"<<asw1.length()<<std::endl;
    
    std::string qwert = "jhkxgkusgdfk";
    for(size_t i {0};i<qwert.length();i++){
        std::cout<<qwert[i];
    }
    
    //chiper
    std::cout<<std::endl<<"enter string";
    std::string entered;
    std::getline(std::cin, entered);
    std::string encrypted;
    std::cout<<entered<<std::endl;
    int n = 5;
    for (char i:entered){
        if(isdigit(i)){
            encrypted += (char) ((((int) i + n - (int) '0') % 9) + (int) '0');
        }else if(isupper(i)){
            encrypted += (char) ((((int) i + n - (int) 'A') % 26) + (int) 'A');
        }else if(islower(i)){
            encrypted += (char) ((((int) i + n - (int) 'a') % 26) + (int) 'a');
        }
    }
    std::cout<<"encrypted"<<encrypted<<std::endl;
    
    
    
    std::cout<<"completed execution"<<std::endl;
    return 0;





}
