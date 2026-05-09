#include <iostream>
using namespace std;

// h(i) = (h(key) + i²) % size

class HashQuadratic{
public:
    int size;
    int* table;

    HashQuadratic(int s){
        size = s;
        table = new int[size];
        for(int i=0; i<size; i++) table[i] = -1;
    }

    int hash(int key) { return key % size; }

    void insert(int key) {
        int idx = hash(key);
        for(int i=0; i<size; i++) {
            int newIdx = (idx + i*i) % size;
            if(table[newIdx] == -1) {
                table[newIdx] = key;
                return;
            }
        }
    }

    bool search(int key) {
        int idx = hash(key);

        for(int i=0; i<size; i++) {
            int newIdx = (idx + i*i) % size;
            if(table[newIdx] == key) return true;
            if(table[newIdx] == -1) return false;
        }
        return false;
    }
};