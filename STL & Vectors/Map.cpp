#include <iostream>
#include <map>
#include <string>
using namespace std;

// Map is an associative array

// For vector methods you can refer to c++.com or geeks for geeks.

int main()
{
    map<string, int> marksMap;
    marksMap["Abdullah"] = 90;
    marksMap["Abc"] =  80;
    marksMap["Xyz"] = 70;

    map<string, int> :: iterator iter;
    marksMap.insert({{"Pqrst", 50}, {"Uvw", 75}});
    for(iter=marksMap.begin(); iter!=marksMap.end(); iter++)
    {
        cout<<(*iter).first<<" "<<(*iter).second<<endl;
    }

    cout<<"The size is: "<<marksMap.size()<<endl;
    cout<<"The size is: "<<marksMap.max_size()<<endl;
    cout<<"The size is: "<<marksMap.empty()<<endl;

    return 0;
}