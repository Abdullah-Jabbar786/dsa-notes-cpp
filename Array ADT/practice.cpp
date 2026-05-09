#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

// Leetcode - 268
// Missing Number 

// using unordered set - 1st aproach.
class Solution {
    public:
    int missingNumber(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        
        for(int i=0; i<=nums.size(); i++)
        {
            if(s.find(i)==s.end()) return i;
        }
        return -1;
    }
};

// using maths - 2nd approach, space = O(1).
int missingNumber(vector<int>& nums) {
    int n = nums.size();
    int expected = n * (n + 1) / 2;
    int actual = 0;
    for (int x : nums) actual += x;
    return expected - actual;
}

// using xor - 3rd approach.
class Solution {
    public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int xor_all = 0;
        int xor_nums = 0;
        
        // XOR of all numbers from 0 to n
        for (int i = 0; i <= n; i++) {
            xor_all ^= i;
        }
        
        // XOR of all numbers in the array
        for (int num : nums) {
            xor_nums ^= num;
        }
        
        // Missing number is the difference
        return xor_all ^ xor_nums;
    }
};


// Leetcode - 3005
// Count Elements With Maximum Frequency

class Solution{
    public:
    int maxFrequencyElements(vector<int>& nums){
        unordered_map<int,int> mp;
        int maxFreq = 0 , total = 0;
        for(int x : nums){
            mp[x]++;
            maxFreq = max(maxFreq, mp[x]);
        }
        for(auto const& [num, count] : mp){
            if(count==maxFreq) total += count;
        }
        return total;
    }
};



// Leetcode - 189
// Rotate Array

class Solution{
public:
    void rotate(vector<int>& nums, int k){
        int n = nums.size();
        k = k%n; 
        if(k==0) return; // k cannot be > size of nums.
        reverse(nums.begin(), nums.end()); // [7,6,5,4,3,2,1]
        reverse(nums.begin(), nums.begin()+k); // [5,6,7,4,3,2,1]
        reverse(nums.begin() + k, nums.end()); // // [5,6,7,1,2,3,4]
    }
};