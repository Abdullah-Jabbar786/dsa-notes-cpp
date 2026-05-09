#include <iostream>
#include <vector>
#include <queue>
#include <deque>
using namespace std;

class CircularQueue{
    int* arr;
    int currSize, cap;
    int f=0, r=-1;
    
    public:
    CircularQueue(int size){
        cap = size;
        arr = new int[cap];
        currSize=0;
        f=0;
        r=-1;
    }

    void push(int val){
        if(currSize==cap){
            cout<<"Cicular Queue is FULL"<<endl;
            return;
        }
        r=(r+1)%cap;
        arr[r] = val;
        currSize++;
    }

    void pop(){
        if(empty()){
            cout<<"Circular Queue is FULL"<<endl;
            return;
        }
        f=(f+1)%cap;
        currSize--;

    }

    int front(){
        if(empty()){
            cout<<"Circular Queue is FULL"<<endl;
            return -1;
        }
        return arr[f];
    }
     
    bool empty(){
        return currSize==0;
    }

    void display(){
        for (int i=0; i<cap; i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};

// Constant time complexity in all functions, O(1)


int main(){
    CircularQueue cq(3);

    cq.push(1);
    cq.push(2);
    cq.push(3);
    cq.pop();
    cq.push(4);

    cq.display();
   
    return 0;
}