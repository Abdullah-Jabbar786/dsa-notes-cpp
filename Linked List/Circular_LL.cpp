#include <iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;

    Node(int val){
        data = val;
        next=NULL;
    }
};

class CircularList
{
    public:
    Node* head;
    Node* tail;

    CircularList(){
        head = NULL;
        tail = NULL;
    }

    void insert_at_Head(int val){
        Node* newNode = new Node(val);
        if(head==NULL){
            head=newNode;
            tail=newNode;
            tail->next=head;
        }
        else{
            newNode->next = head;
            head = newNode;
            tail->next = head;
        }
    }
    
    void insert_at_Tail(int val)
    {
        Node* newNode = new Node(val);
        if(head==NULL)
        {
            head=newNode;
            tail=newNode;
            tail->next=head;
        }
        else{
            newNode->next = head;
            tail->next = newNode;
            tail = newNode;
        }
    }

    void delete_at_Head()
    {
        if(head==NULL)
        {
            cout<<"Circular LL is empty."<<endl;
            return;
        }
        else if(head==tail)
        {
            delete head;
            head = NULL;
            tail = NULL;
        }
        else
        {
            Node* temp = head;
    
            head = head->next;
            tail->next = head;
            temp->next = NULL;
            delete temp;
        }
    }
    void delete_at_Tail()
    {
        if(head==NULL)
        {
            cout<<"Circular LL is empty."<<endl;
            return;
        }
        else if(head==tail)
        {
            delete tail;
            head = NULL;
            tail = NULL;
        }
        else
        {
            Node* temp = tail;
            Node* prev = head;
    
            while(prev->next!=tail)
            {
                prev = prev->next;
            }
            tail = prev;
            tail->next = head;
            temp->next = NULL; 
            delete temp;
        }
    }

    void display()
    {
        if(head==NULL) return;
        
        Node* temp = head;
        do
        {
            cout << temp->data << "->";
            temp = temp->next;
        } while(temp!=head);

        cout<<temp->data<<endl;
    }
};


int main()
{
    CircularList Cl;

    Cl.insert_at_Head(1);
    Cl.insert_at_Head(2);
    Cl.insert_at_Head(3);

    Cl.insert_at_Tail(4);
    Cl.insert_at_Tail(5);
    Cl.insert_at_Tail(6);

    Cl.delete_at_Head();
    Cl.delete_at_Tail();

    Cl.display();
    return 0;
}