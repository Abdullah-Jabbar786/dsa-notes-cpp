#include <iostream>
#include <unordered_map>
using namespace std;

// Definition for singly-linked list.
class ListNode{
    public:
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {} 
};

//Leetcode - 141

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast!= NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast) return true;
        }
        return false;
    }
};






//Leetcode - 142 

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        bool cycle = false;

        while(fast!=NULL && fast->next!=NULL)
        {
            slow = slow->next;
            fast = fast->next->next;

            if(slow==fast)
            {
                cycle = true;
                break;
            }
        }

        if(cycle==false)
        {
            return NULL;
        }

        slow = head;
        // same concept but if you have to remove cycle then make prev pointer and then store it in loop and when loop ends then assign it's next to NULL

        // ListNode* prev = NULL;

        while(slow!=fast)
        {
            slow = slow->next;
            // prev = fast;
            fast = fast->next;
        }

        // prev->next = NULL; // Removes Cycle.

        return slow;
    }
};




//Leetcode - 234
// Palindrome Linked List

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        
        ListNode* temp = head;
        ListNode* slow=head;
        ListNode* fast=head;
        if(temp->next==nullptr) return true;
        if(temp->next->next==nullptr)
        {
            if(temp->val==temp->next->val) return true;
            else return false;
        }

        while(fast->next && fast->next->next) // when the condition is (fast && fast->next) then you have to include mid in 2nd half while reversing but when the condition is this which is written then you can ignore mid and start reversing from exactly the first node of second half as it is show below, I have used slow->next means *Node after Mid*.
        {
            slow=slow->next;
            fast=fast->next->next;
        }

        ListNode* prev = NULL;
        ListNode* curr = slow->next; // Node after Mid.
        ListNode* next = NULL;

        while(curr!=NULL)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        // new head or reversed part = prev

        while(prev!=nullptr)
        {
            if(temp->val!=prev->val) return false;
            temp=temp->next;
            prev=prev->next;
        }
        return true;
    }
};



// Leetcode - 21
// Merge Two Sorted Linked Lists using Recursive aproach.

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==NULL)
        {
            return list2;
        }
        if(list2==NULL)
        {
            return list1;
        }

        if(list1->val <= list2->val)
        {
            list1->next = mergeTwoLists(list1->next,list2);
            return list1;
        }
        else if(list1->val > list2->val)  // Here I can just use else but for concept I wrote the condition. Use Else!
        {
            list1->next = mergeTwoLists(list1->next,list2);
            return list1;
        }
    }
};





// Definition for a Node.
class Node {
    public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

// Leetcode-138
// Copy List with Random Pointer.

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL) return NULL;

        unordered_map<Node*,Node*> map;
        Node* newHead = new Node(head->val);
        Node* oldTemp = head->next;
        Node* newTemp = newHead;
        map[head] = newHead;

        while(oldTemp != NULL)
        {
            Node* copyNode = new Node(oldTemp->val);
            map[oldTemp] = copyNode;

            newTemp->next = copyNode;
            oldTemp = oldTemp->next;
            newTemp = newTemp->next; 
        }

        oldTemp = head;
        newTemp = newHead;

        while(oldTemp != NULL)
        {
            newTemp->random = map[oldTemp->random];
            oldTemp = oldTemp->next;
            newTemp = newTemp->next; 
        }
        return newHead;
    }
};


//Leetcode-24
//Recursive approach to swap nodes in pairs in a singly linked list.

ListNode* swapPairs(ListNode* head) {
    if(head==NULL || head->next==NULL) {
        return head;
    }

    ListNode* curr = head;
    ListNode* next = curr->next;

    curr->next = swapPairs(next->next);
    next->next = curr;

    return next;
}


// Leetcode - 203
// Remove Linked List Elements


class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* curr=head;
        ListNode* copy = new ListNode(0);  // Learned this. I can make a new node like dummy node just to point to head.
        copy->next=head;
        ListNode* prev=copy;

        while(curr){
            if(curr->val==val){
                prev->next=curr->next;
                delete curr;
                curr=prev->next;
            }
            else{
            prev=prev->next;
            curr=curr->next;
            }
        }
        return copy->next; //Always pointing to updated Head.
    }
};


// Leetcode - 1290 
// Convert Binary Number in a Linked List to Integer

class Solution {
public:
    int getDecimalValue(ListNode* head) {
        vector<int> arr;
        int decimal=0;
        ListNode* temp = head;
        while(temp)
        {
            arr.push_back(temp->val);
            temp=temp->next;
        }

        for (int bit : arr)  // Binary conversion concept.
        {
            decimal = decimal*2 + bit;  
        }
        return decimal;
    }
};


// Leetcode - 237
// Delete Node in a Linked List.

// In this problem we are given a pointer to the node we have to delete, what we do is copy the next node value of node to be deleted in the node to be deleted and then just skip the node.

//sample
// 4 → 5 → 1 → 9
// 4 → 1 → 1 → 9
// 4 → 1 → 9

// The problem guarantees that the node to delete will never be the last node, so this code is always safe.
// Tail node → impossible without access to the head or previous node.

class Solution {
    public:
    void deleteNode(ListNode* node){
        node->val = node->next->val;
        node->next = node->next->next;
    }
};



// Leetcode - 2487
// Remove Nodes From Linked List

// learned that first reverse then track max val and also just skipping nodes. Medium Problem
// There was another approach too but that I did not understand,
// in that unordered sets or unordered maps were used and also Monotonic Stack approach.
// Recursive Approach is also below refer to it and dry to understand the problem whenever you wanna revisit it.

class Solution{
public:
ListNode* reverseList(ListNode* head){
    ListNode* prev = NULL;
        ListNode* next = NULL;
        ListNode* curr = head;
        
        while(curr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    
    ListNode* removeNodes(ListNode* head){
        head =  reverseList(head); // reversing
        
        ListNode* curr = head;
        int curr_max = curr->val;
        while(curr->next){
            if(curr->next->val < curr_max) curr->next = curr->next->next;
            else{
                curr_max = curr->next->val; // keeping a track of max val
                curr = curr->next;
            }
        }
        return reverseList(head); 
    }
};

// Recursuve Approach of above problem

class Solution{
public:
ListNode* removeNodes(ListNode* head){
        // Base case — empty or single node
        if (!head || !head->next) return head;

        // Recursively process the rest of the list
        head->next = removeNodes(head->next);

        // Now decide whether to keep or remove current node
        if (head->val < head->next->val)
        return head->next; // remove current node
        else
        return head; // keep current node
    }
};

// dry run
/*

Input : 5 → 2 → 13 → 3 → 8

Step-by-step:
Start recursion at 5

Go deep until last node 8

Base case returns 8

Backtrack:

Compare 3 < 8 → remove 3

Compare 13 > 8 → keep 13

Compare 2 < 13 → remove 2

Compare 5 < 13 → remove 5

*/


// Leetcode - 2
// Add Two Numbers

// conceptual explaination is like when we add for exp 342 + 465 we add from the right hand side like 7+5 then carry and so on

/*
3¹ 4  2
4  6  5
---------
8  0  7
*/

/// Iterative approach
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2){
        int carry=0 , sum;
        ListNode* dummy = new ListNode(0);
        ListNode* Sum = dummy;

        while(l1 || l2 || carry){
            sum=0;
            if(l1) sum += l1->val;
            if(l2) sum += l2->val;
            sum += carry;

            carry=sum/10;
            Sum->next = new ListNode(sum%10);
            Sum = Sum->next;

            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }
        return dummy->next;
    }
};

// Recursive approach

class Solution{
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2, int carry=0){
        if(!l1 && !l2 && carry==0) return NULL;

        int sum = carry;
        if (l1) sum += l1->val;
        if (l2) sum += l2->val;

        ListNode* node = new ListNode(sum%10);

        ListNode* next1 = nullptr;
        ListNode* next2 = nullptr;

        if (l1) next1 = l1->next;
        if (l2) next2 = l2->next;

        node->next = addTwoNumbers(next1, next2, sum / 10);
        return node; // returns answer in reversed form
    }
};




// Leetcode - 147
// Insertion Sort List

class Solution{
public:
    ListNode* insertionSortList(ListNode* head){
        if(!head || !head->next) return head;

        ListNode* dummy = head; // sorted part
        ListNode* curr = head->next;
 
        while(curr){
            if(curr->val >= dummy->val){
                dummy = curr;
                curr = curr->next;
            }
            else{
                dummy->next = curr->next;

                ListNode* prev = NULL;
                ListNode* temp = head;
                while(temp && temp->val<curr->val){
                    prev = temp;
                    temp = temp->next;
                }

                if(prev==nullptr){
                    curr->next = head;
                    head = curr;
                } 
                else{
                    curr->next = prev->next;
                    prev->next = curr;
                }
            }
            curr = dummy->next;
        }
        return head;
    }
};


// Leetcode - 2181
// Merge Nodes in Between Zeros

class Solution{
public:
ListNode* mergeNodes(ListNode* head){
    ListNode* temp = head->next;
    int sum = 0;
    
    while(temp && temp->val!=0){
        sum += temp->val;
        temp = temp->next;
        }
        
        ListNode* newNode = new ListNode(sum); // Making new LL node.
        
        if(!temp->next) newNode->next = nullptr;
        else newNode->next = mergeNodes(temp); // Recursive Call
        
        return newNode;
    }
};



// Leetcode - 92
// Reverse Linked List II

class Solution{
public:
    ListNode* reverseBetween(ListNode* head, int left, int right){
        if(!head || left==right) return head;

        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;

        for(int i=1; i<left; i++) prev = prev->next;
        ListNode* curr = prev->next; // Node from which we have to reverse;
       
        ListNode* next = NULL;
        for(int i=0; i<right-left; i++){ // Reverse Loop
            ListNode* forward = curr->next;
            curr->next = forward->next;
            forward->next = prev->next;
            prev->next = forward;
        }
        return dummy->next;
    }
};