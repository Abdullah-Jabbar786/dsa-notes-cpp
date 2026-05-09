#include <iostream>
#include <vector>
#include <map>
using namespace std;


// Definition for a binary tree node.
class TreeNode{
    public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr){}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//  Definition for singly-linked list.
class ListNode{
    public:
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
}; 

// Leetcode - 100
// 100. Same Tree

class Solution{
    public:
    bool isSameTree(TreeNode* p, TreeNode* q){
        if(!p && !q) return true;
        if(!p || !q) return false;
        if(p->val!=q->val) return false;
        
        // Recursive
        return isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
    }
};


// Leetcode - 450
// 450. Delete a Node in a BST 

class Solution{
    public:
    TreeNode* find_min(TreeNode* node){
        if(!node) return nullptr;
        while(node->left) node = node->left;
        return node;
    }
    
    TreeNode* deleteNode(TreeNode* root, int key){
        if(!root) return nullptr;
        
        if(key<root->val){
            root->left = deleteNode(root->left,key);
        }
        else if(key>root->val){
            root->right = deleteNode(root->right,key);
        }
        else{
            if(!root->left && !root->right) return nullptr; // no children
            
            if(!root->left) return root->right; // 1 children
            else if(!root->right) return root->left; // 1 children
            
            TreeNode* successor = find_min(root->right);
            root->val = successor->val;
            root->right = deleteNode(root->right, successor->val);
        }
        return root;
    }
};


// Leetcode - 98
// Validate Binary Search Tree
class Solution{
    public:
    void inorder(TreeNode* node, vector<int>& val){
        if(!node) return;
        inorder(node->left, val);
        val.push_back(node->val);
        inorder(node->right, val);
    }
    bool isValidBST(TreeNode* root){
        vector<int> res;
        inorder(root, res);
        
        for(int i=0; i<res.size()-1; i++){
            if(res[i]>=res[i+1]) return false;
        }
        return true;
    }
};

// Leetcode - 110
// Balanced Binary Tree

class Solution{
    public:
    int Height(TreeNode* node){
        if(!node) return 0;
        int left = Height(node->left);
        if(left==-1) return -1;
        int right = Height(node->right);
        if (right==-1) return -1;
        if (abs(left - right) > 1) return -1;
        return 1 + max(Height(node->left), Height(node->right));
    }
    bool isBalanced(TreeNode* root){
        return Height(root) != -1;
    }
};

// Leetcode - 104
// Maximum Depth of Binary Tree


class Solution{
    public:
    int maxDepth(TreeNode* root){
        if(!root) return 0;
        
        int left_depth = maxDepth(root->left);
        int right_depth = maxDepth(root->right);
        return 1 + max(left_depth,right_depth);
    }
};

// Leetcode - 108
// Convert Sorted Array to Binary Search Tree

class Solution{
    public:
    TreeNode* helper(vector<int> nums, int start, int end){
        if(start>end) return nullptr;
        
        int mid =start + (end-start)/2;
        TreeNode* root = new TreeNode(nums[mid]);
        
        root->left = helper(nums, start, mid-1);
        root->right = helper(nums, mid+1, end);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums){
        return helper(nums, 0, nums.size()-1);
    }
};


// Leetcode - 1382
// Balance a Binary Search Tree

// In constructing function there mid concept like in inorder
// we divide and conquer and then contruct the BST

class Solution{
    public:
    void inorder(TreeNode* root, vector<int>& res){
        if(!root) return;
        
        inorder(root->left,res);
        res.push_back(root->val);
        inorder(root->right,res);
    }
    
    TreeNode* ConstructBST(vector<int>& arr, int l, int r){
        if(l>r) return nullptr;
        
        int mid = (l+r)/2;
        TreeNode* root = new TreeNode(arr[mid]);
        root->left = ConstructBST(arr, l, mid-1);
        root->right = ConstructBST(arr, mid+1, r);
        return root;
    }
    
    TreeNode* balanceBST(TreeNode* root){
        if(!root) return root;
        vector<int> res;
        inorder(root,res);
        
        return ConstructBST(res, 0, res.size()-1);
    }
};


// Leetcode - 114
// Flatten Binary Tree to Linked List
// 1
class Solution{
    public:
    void flatten(TreeNode* root){
        if (!root) return;
        
        flatten(root->left);
        flatten(root->right);
        
        TreeNode* left_tree = root->left;
        TreeNode* right_tree = root->right;
        root->left = nullptr;
        root->right = left_tree;

        TreeNode* curr = root;
        while(curr->right) curr = curr->right;
        
        curr->right = right_tree;
    }
};

// 2nd approach is like pre order but in reverse 
// watch the video of apna college if you wanna understand again
// much simpler to dry run
class Solution{
    public:
    TreeNode* nextRight = NULL;
    void flatten(TreeNode* root){
        if(!root) return;
        
        flatten(root->right);
        flatten(root->left);
        
        root->left = NULL;
        root->right = nextRight;
        nextRight = root; // also last visited node
    }
};

// Leetcode - 109
// Convert Sorted List to Binary Search Tree

class Solution{
    public:
    ListNode* Middle(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;
        
        while(fast && fast->next){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        if(prev) prev->next = nullptr; // cutting the list
        
        return slow;
    }
    TreeNode* sortedListToBST(ListNode* head){
        if(!head) return nullptr;
        
        if(!head->next) return new TreeNode(head->val);  // Base Case
        
        ListNode* mid = Middle(head);
        TreeNode* root = new TreeNode(mid->val);
        
        root->left = sortedListToBST(head);  // left side of list
        root->right = sortedListToBST(mid->next);  // right side of list
        
        return root;
    }
};



// Leetcode - 1008
// Construct Binary Search Tree from Preorder Traversal

class Solution{
public:
TreeNode* solve(vector<int>& arr, int& i, int limit ){
    if(i==arr.size() || arr[i]>limit) return nullptr;
    TreeNode* root = new TreeNode(arr[i++]);
    root->left = solve(arr, i, root->val);
    root->right = solve(arr, i, limit);
    return root; 
}
TreeNode* bstFromPreorder(vector<int>& preorder){
    int i = 0;
    return solve(preorder, i, INT_MAX);
}
};


// Leetcode - 106
// Construct Binary Tree from Inorder and Postorder Traversal

class Solution{
public:
    TreeNode* solve(vector<int>& inorder, int in_start, int in_end, vector<int>& postorder, int p_start, int p_end, map<int,int> mp){
        if(p_start>p_end || in_start>in_end) return nullptr;

        TreeNode* root = new TreeNode(postorder[p_end]);

        int inRoot = mp[postorder[p_end]];
        int NumsLeft = inRoot - in_start;

        root->left = solve(inorder, in_start, inRoot-1, postorder, p_start, p_start + NumsLeft-1, mp);
        root->right = solve(inorder, inRoot+1, in_end, postorder, p_start+NumsLeft, p_end-1, mp);
        
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder){
        map<int,int> mp; 
        for(int i=0; i<inorder.size(); i++) mp[inorder[i]] = i;  // Mapping Concept.
        
        return solve(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1, mp);
    }
};

int main(){
    
    return 0;
}