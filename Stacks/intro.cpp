#include <iostream>
#include <vector>
#include <list>
using namespace std;

// Stack using Arrays/Vector 
class Stack1
{
    vector<int> v; 

    public:
    //O(1)
    void push(int val){
        v.push_back(val);
    }
    void pop(){
        v.pop_back();
    }

    int top(){
        return v[v.size()-1];
    }

    bool empty(){
        return v.size() == 0; // returns 1 if empty.
    }

};


// Stack using Linked List
class Stack_LL
{
    list<int> ll;

    public:
    //O(1)
    void push(int val){
        ll.push_front(val);
    }
    void pop(){
        ll.pop_front();
    }

    int top(){
        return ll.front();
    }

    bool empty(){
        return ll.size() == 0; // returns 1 if empty.
    }

};

int main()
{
    Stack1 S; 
    
    // Can also use C++ STL #include <stack> , and then in main make a stack like stack<int> S; This will work and the function will be all usually the same

    S.push(10);
    S.push(20);
    S.push(30);

    while(!S.empty()){
        cout<<S.top()<<" ";
        S.pop();
    }
    
    return 0;
}