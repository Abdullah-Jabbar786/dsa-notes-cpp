#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <unordered_map>
using namespace std;

// Stock Spanner
//O(n)

void span(vector<int> &prices, vector<int> &ans, stack<int> &st)
{
    for(int i=0; i<prices.size(); i++)
    {
        while(st.size()>0 && prices[st.top()]<=prices[i]) st.pop();

        if(st.empty()) ans[i] = i+1;
        else ans[i] = i-st.top();

        st.push(i);
    }

    //Displaying ans values. Span of each price.

    for(int val : ans)
    {
        cout<<val<<" ";
    }
    cout<<endl;
}


//Next Greater Element

void next_greater(vector<int> &arr, vector<int> &ans)
{
    stack<int> st;
    for(int i=arr.size()-1; i>=0; i--)
    {
        while(st.size()>0 && st.top()<=arr[i])
        {
            st.pop();
        }
        
        if(st.empty()) ans[i] = -1;
        else ans[i] = st.top();
        st.push(arr[i]);
    }

    // Displaying
    for(int val : ans)
    {
        cout<<val<<" ";
    }
    cout<<endl;
}

//Previous Smaller Element

void prev_smaller(vector<int> &arr, vector<int> &ans)
{
    stack<int> st;
    for(int i=0; i<arr.size(); i++)
    {
        while(st.size()>0 && st.top()>=arr[i])
        {
            st.pop();
        }
        
        if(st.empty()) ans[i] = -1;
        else ans[i] = st.top();
        st.push(arr[i]);
    }

    // Displaying
    for(int val : ans)
    {
        cout<<val<<" ";
    }
    cout<<endl;
}



// Leetcode - 20
// Valid Parenthese 

class Solution {
public:
    bool isValid(string s){
        stack<char> st;
        for(int i=0; i<s.size(); i++)
        {
            if(s[i] == '(' || s[i] == '[' || s[i] == '{') st.push(s[i]);
            else{
                if(st.size()==0) return false;
                char top = st.top();
                if((s[i] == ')' && top == '(') ||
                    (s[i] == ']' && top == '[') ||
                    (s[i] == '}' && top == '{'))
                {
                    st.pop();
                } 
                else return false;
            }
        }
        return st.size()==0; // if 0 then true else false
    }
};


// Leetcode - 496
//Next Greater Element I, using the stack + hashmap approach.


class Solution{
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        stack<int> st;
        unordered_map<int,int>mp;

        for(int i=nums2.size()-1; i>=0; i--)
        {
            while(st.size()>0 && st.top()<=nums2[i]) st.pop();

            if(st.empty()) mp[nums2[i]] = -1;
            else mp[nums2[i]] = st.top();

            st.push(nums2[i]);
        }

        for(int i=0; i<nums1.size(); i++)
        {
            ans.push_back(mp[nums1[i]]);
        }
        return ans;
    }
};



int main()
{
    vector<int> prices = {100, 80, 60, 70, 60, 75, 85};
    vector<int> ans(prices.size(),0); // means initialized with the same size as prices and all values are equal to 0.
    stack<int> st;

    span(prices, ans, st); // Span function

    return 0;
}