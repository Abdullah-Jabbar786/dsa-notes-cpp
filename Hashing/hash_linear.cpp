#include <iostream>
using namespace std;

// h(i) = (h(key) + i) % size

class HashLinear {
public:
    int size;
    int* table;

    HashLinear(int s) {
        size = s;
        table = new int[size];
        for(int i=0; i<size; i++) table[i] = -1;
    }

    int hash(int key) { return key % size; }

    void insert(int key) {
        int idx = hash(key);

        while(table[idx] != -1) {
            idx = (idx + 1) % size;
        }
        table[idx] = key;
    }

    bool search(int key) {
        int idx = hash(key);

        int start = idx;
        while(table[idx] != -1) {
            if(table[idx] == key) return true;
            idx = (idx + 1) % size;
            if(idx == start) break;  
        }
        return false;
    }
};