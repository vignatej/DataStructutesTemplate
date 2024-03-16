#include <iostream>
#include <vector>

using namespace std;

int main()
{

    vector<int> a(5);
    vector<double> b(5, 20.32);
    vector<char> c{'a', 'e'};
    cout << b[4] << endl;
    a.push_back(55);
    int z = a.at(5);
    cout << z << endl;
    cout << a.at(5) << endl;
    vector<int> sco(8, 50);
    cout << sco.at(5) << endl;
    sco.at(5) = 55;
    cout << sco.at(5) << endl;
    cout << sco.size() << endl;
    sco.push_back(422);
    cout << sco.size() << endl;

    // 2d vectors
    vector<vector<int>> asdfg = {
        {1,5,6,3},
        {8,9,6,22,0,33,55}
    };
    cout << asdfg.at(0).at(2)<<endl;



    vector<int> v1; 
    vector<int> v2;
    v1.push_back(10);v1.push_back(20);
    cout<<v1.at(0)<<"--"<<v1.at(1)<<endl;
    cout<<v1.size()<<endl;

    v2.push_back(100);v2.push_back(200);
    cout<<v2.at(0)<<"--"<<v2.at(1)<<endl;
    cout<<v2.size()<<endl;
    vector<vector<int>> vec2d;
    vec2d.push_back(v1);
    vec2d.push_back(v2); 

    cout<<vec2d.at(0).at(0)<<endl;
    cout<<vec2d.at(0).at(1)<<endl;
    cout<<vec2d.at(1).at(0)<<endl;
    cout<<vec2d.at(1).at(1)<<endl;

    v1.at(0) = 1000;
    cout<<vec2d.at(0).at(0)<<endl;
    cout<<vec2d.at(0).at(1)<<endl;
    cout<<vec2d.at(1).at(0)<<endl;
    cout<<vec2d.at(1).at(1)<<endl;
    cout<<v1.at(0)<<"--"<<v1.at(1)<<endl;


}
