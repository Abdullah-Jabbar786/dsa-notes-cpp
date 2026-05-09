#include "iostream"
#include <string>
using namespace std;

// Leetcode - 389
// Find the Difference
class Solution{
public:
    char findTheDifference(string s, string t){
        // char ans = 0;
        // for(char c : s) ans ^= c; // XOR
        // for(char c : t) ans ^= c; // XOR
        // return ans;

        for(int i=0; i<t.size(); i++){
            size_t pos = s.find(t[i]);
            if(pos == string::npos) return t[i];
            s.erase(pos, 1);
        }
        return ' ';
    }
};