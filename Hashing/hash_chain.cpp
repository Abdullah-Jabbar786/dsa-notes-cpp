#include <iostream>
using namespace std;

class Node{
    public:
    int key;
    Node* next;

    public:
    Node(int val){
        key = val;
        next = NULL;
    }
};

class HashTable {
    Node** table;   //array of nodes
    int size;

    int hashFunction(int key){
        return key % size;
    }
    public:
    HashTable(int s){
        size = s;
        table = new Node*[size];
        for(int i=0; i<size; i++) table[i] = NULL;
    }

    void insertKey(int key){
        int index = hashFunction(key);
        Node* newNode = new Node(key);
        newNode->next = table[index];
        table[index] = newNode;
        cout << key << " inserted at chain " << index << endl;
    }

    void print(){
        cout << "Hash Table:-\n";
        for(int i=0; i<size; i++) {
            Node* curr = table[i];
            cout << i << ": ";
            while(curr){
                cout << curr->key << " -> ";
                curr = curr->next; 
            }
            cout << "NULL\n";
        }
    }

    void deleteKey(int key) {
        int index = hashFunction(key);
        Node* curr = table[index];
        Node* prev = NULL;

        while (curr != NULL) {
            if (curr->key == key) {
                if (prev == NULL) {
                    table[index] = curr->next;  // deleted node was head
                } else {
                    prev->next = curr->next;
                }
                delete curr;
                cout << key << " deleted from chain " << index << endl;
                return;
            }
            prev = curr;
            curr = curr->next;
        }
    }

    ~HashTable(){
        for(int i=0; i<size; i++) {
            Node* curr = table[i];
            while(curr) {
                Node* temp = curr;
                curr = curr->next;
                delete temp;
            }
        }
        delete[] table;
    }
};