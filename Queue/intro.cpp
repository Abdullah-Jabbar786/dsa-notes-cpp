#include <iostream>
#include <vector>
#include <queue>
#include <deque>
using namespace std;

//Implementing Queue using Linked List
// We can also use STL for Queue and Deque implementation.
// Refer to int main() to see STL syntax.
class Node{
    public:
    int data;
    Node* next;

    Node(){}
    Node(int val){
        data = val;
        next = nullptr;
    }
};


class Queue{
    Node* head;
    Node* tail;
    
    public:
    Queue(){
        head = tail = nullptr;
    }

    void push(int data){
        Node* newNode = new Node(data);
        if(empty()) head = tail = newNode;
        else{
            tail->next = newNode;
            tail = newNode;
        }
    }
    
    void pop(){
        if(empty()){
            cout<<"Queue is empty."<<endl;
            return;
        }

        Node* temp = head;
        head = temp->next;
        if(!head) tail = nullptr;
        delete temp;
    }
    
    int front(){
        if(empty()){
            cout<<"Queue is empty."<<endl;
            return -1;
        }
    
        return head->data;
    }

    bool empty(){
        return head == nullptr;
    }

};

// Constant time complexity in all functions, O(1)


//push -> back , front
//pop -> front, back
//front -> back
// This type of Queue is called Double Ended or Deque, remember this is Deque and not Dequeue which means to pop. Simply keep in mind whenever we can manipulate queue from back side too then it is Double Ended.



//A Priority Queue is like a queue where each element has a priority —
// the element with highest priority is removed first.


int main(){
    Queue q;
    // queue<int> q;  
    // Queue STL, all functions remain the same as they are built in.
    
    q.push(1);
    q.push(2);
    q.push(3);
    
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    
    cout<<endl;
    
    // Deque STL, all functions remain the same as they are built in.
    deque<int> dq;  
    dq.push_back(4);
    dq.push_back(5);
    dq.push_back(6);
    
    dq.push_front(2); // 2,4,5,6


    cout<<dq.front()<<" "<<dq.back()<<endl;
    dq.pop_back();
    cout<<dq.front()<<" "<<dq.back()<<endl;

    return 0;
}