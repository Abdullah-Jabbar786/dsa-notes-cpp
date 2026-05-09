#include <iostream>
using namespace std;


class Node
{
    public:
    int data;
    Node* next;
    Node* prev;

    Node(int val)
    {
        data = val;
        next=NULL;
        prev=NULL;
    }
};

class DoublyList
{
    public:
    Node* head;
    Node* tail;

    DoublyList()
    {
        head = NULL;
        tail = NULL;
    }

    void push_front(int val)
    {
        Node* newNode = new Node(val);
        if(head==NULL)
        {
            head=newNode;
            tail=newNode;
        }
        else{
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }
    
    void push_back(int val)
    {
        Node* newNode = new Node(val);
        if(head==NULL)
        {
            head=newNode;
            tail=newNode;
        }
        else{
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }

    void pop_front()
    {
        if(head==NULL)
        {
            cout<<"Doubly LL is empty."<<endl;
            return;
        }

        Node* temp = head;

        head = head->next;
        if(head!=NULL)
        {
            head->prev = NULL;
        }
        temp->next = NULL;
        delete temp;
    }

    void pop_back()
    {
        if(head==NULL)
        {
            cout<<"Doubly LL is empty."<<endl;
            return;
        }

        Node* temp = tail;

        tail = tail->prev;
        if(tail!=NULL)
        {
            tail->next = NULL;
        }
        temp->prev = NULL;
        delete temp;
    }

    void display()
    {
        Node* temp = head;
        while(temp!=NULL)
        {
            cout<<temp->data<<" <=> ";
            temp = temp->next;
        }
        cout<<"Null"<<endl;
    }
};


int main()
{
    DoublyList dl;

    dl.push_front(1);
    dl.push_front(2);
    dl.push_front(3);

    dl.push_back(4);
    dl.push_back(5);
    dl.push_back(6);

    dl.pop_front();
    dl.pop_back();

    dl.display();

    return 0;
}