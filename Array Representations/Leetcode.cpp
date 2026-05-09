#include <iostream>
#include <unordered_set>
#include <vector>
#include <algorithm>
using namespace std;



//Leetcode-217

// unordered_set → hash set

//unordered_set<int> s;  // creates an empty hash set
// Common operations
// s.insert(x); → add element x
// s.find(x) != s.end(); → check if x exists
// s.erase(x); → remove x
// s.size(); → number of elements

// unordered_map → hash map

// unordered_map<int,int> mp;  // key=int, value=int
// Common operations
// mp[key] → access value for key (creates it with 0 if not present)
// mp[key] = val; → assign value
// mp[key]++; → increment (great for frequency)
// mp.find(key) != mp.end(); → check if key exists
// mp.erase(key); → remove key
// mp.size(); → number of entries

// unordered_set → use when you only need to know if something is present.

// unordered_map → use when you need to store or update extra information (like counts).

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        
        unordered_set<int> Hash;
        for(int i=0; i<nums.size(); i++)
        {
            if(Hash.find(nums[i]) != Hash.end()) // Checking if value is already there.
            {
                return true;
            }
            Hash.insert(nums[i]); // Keeping a record of values encountered before
        }
        return false; 
    }
};


//Leetcode-2824

// Count Pairs Whose Sum is Less than Target

// Brute Force O(n^2)

class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        int count = 0;
        for(int i=0; i<nums.size(); i++)
        {
            for(int j=i+1; j<nums.size(); j++) 
            {
                if(nums[i]+nums[j]<target) count++;
            }
        }
        return count;
    }
};


// Two-Pointer Optimized (O(n log n))

class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int left=0, right=nums.size()-1;
        int count=0;

        while(left < right) {
            if(nums[left] + nums[right] < target) {
                count += (right-left);
                left++;
            } else {
                right--;
            }
        }
        return count;
    }
};