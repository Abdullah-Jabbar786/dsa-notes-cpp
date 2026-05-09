#include <iostream>
using namespace std;

/*
h1 = key % size
h2 = prime - (key % prime)
newIndex = (h1 + i*h2) % size
*/

class HashDouble {
public:
    int size;
    int* table;
    int prime;

    HashDouble(int s) {
        size = s;
        table = new int[size];
        for(int i=0; i<size; i++) table[i] = -1;
        prime = s - 1;  // choose prime smaller than size
    }

    int hash1(int key) { return key % size; }
    int hash2(int key) { return prime - (key % prime); }

    void insert(int key) {
        int idx1 = hash1(key);
        int idx2 = hash2(key);

        int i = 0;
        while(table[(idx1 + i*idx2) % size] != -1) {
            i++;
        }
        table[(idx1 + i*idx2) % size] = key;
    }

    bool search(int key) {
        int idx1 = hash1(key);
        int idx2 = hash2(key);

        int i = 0;
        while(table[(idx1 + i*idx2) % size] != -1) {
            if(table[(idx1 + i*idx2) % size] == key)
                return true;
            i++;
        }
        return false;
    }
};