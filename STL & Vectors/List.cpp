#include <iostream>
#include <vector>
#include <list>
using namespace std;


void display(list<int> &l)
{
    list<int> :: iterator it;
    for (it = l.begin(); it != l.end(); it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
}

// For vector methods you can refer to c++.com or geeks for geeks.

int main()
{
    list<int> list1; // List of 0 Length
    
    list1.push_back(5);
    list1.push_back(3);
    list1.push_back(9);
    list1.push_back(7);
    
    // list<int> :: iterator iter;
    // iter = list1.begin();
    // cout<<*iter<<" ";
    // iter++;
    // cout<<*iter<<" ";
    // iter++;
    // cout<<*iter<<" ";
    // iter++;
    // cout<<*iter<<" ";
    // iter++;
    
    //instead of this
    
    display(list1);
    list1.remove(3); // To remove from middle, removes multiple 3's too.
    display(list1);
    // sorting the list
    list1.sort();
    display(list1);
    


    list<int> list2(7); // Empty list of size 7
    list<int> :: iterator Iter;
    Iter = list2.begin();
    *Iter = 45;
    Iter++;
    *Iter = 15;
    Iter++;
    *Iter = 35;
    Iter++;


    display(list2);
    list1.merge(list2);
    list1.reverse();

    display(list1);


    return 0;
}