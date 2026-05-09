#include <iostream>
using namespace std;


class Node
{
    public:
    int data;
    Node* next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }

};


class List
{
    Node* head;
    Node* tail;

    public:
    List()
    {
        head = NULL;
        tail = NULL;
    }


    void push_front(int val)
    {
        Node* newNode = new Node(val); //Creating New Node first syntax

        // Node newNode(val); //static, second syntax, Creates a static object so whenever you come out of push front function it will delete.

        if(head==NULL)
        {
            head = newNode;
            tail = newNode;
            return;
        }
        else
        {
            newNode->next = head; // same as (*newNode).next = head;
            head = newNode;
        }
    }

    void push_back(int val)
    {
        Node* newNode = new Node(val); //Creating New Node first syntax
        
        // Node newNode(val); //static, second syntax, Creates a static object so whenever you come out of push front function it will delete.
        
        if(head==NULL)
        {
            head = newNode;
            tail = newNode;
            return;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }
    
    void pop_front()
    {
        if(head==NULL)
        {
            cout<<"Empty Linked List"<<endl;
            return;
        }
        
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }
    
    void pop_back()
    {
        if(head==NULL)
        {
            cout<<"Empty Linked List"<<endl;
            return;
        }
        
        else if(head == tail) // Only one node.
        {
            delete head;
            head = NULL;
            tail = NULL;
            return;
        }
        
        Node* temp = head;
        while(temp->next != tail)
        {
            temp = temp->next;
        }
        delete tail;
        tail = temp;
        temp->next = NULL;
    }
    
    void insert(int val, int pos)
    {
        if(pos<0)
        {
            cout<<"Invalid position"<<endl;
            return;
        }
        
        if(pos==0)
        {
            push_front(val);
            return;
        }
        
        Node* temp = head;
        for(int i=0; i<pos-1; i++)
        {
            if(temp == NULL)
            {
                cout<<"Invalid position."<<endl;
                return;
            }
            temp = temp->next;
        }
        
        Node* newNode = new Node(val); //Creating New Node.
        newNode->next = temp->next;
        temp->next = newNode;
    }

    int search(int key)
    {
        Node* temp = head;
        int index=0;

        while(temp != NULL)
        {
            if(temp->data == key)
            {
                return index;
            }

            temp = temp->next;
            index++;
        }
        return -1;
    }

    Node* Reverse()
    {
        Node* prev = NULL;
        Node* curr = head;
        Node* next = NULL;

        while(curr!=NULL)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev; // new head.
    }

    void display()
    {
        Node* temp = head;
        while(temp != NULL)
        {
            cout<<temp->data<<"->";
            temp = temp->next;
        }
        cout<<"NULL";
    }
};

int main()
{
    List li;

    li.push_front(1);
    li.push_front(2);
    li.push_front(3);
    li.push_back(4);
    li.pop_front();
    li.pop_back();
    li.insert(4,1);
    cout<<li.search(4)<<endl;;

    li.display();
}