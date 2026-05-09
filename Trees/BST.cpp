#include <iostream>
#include <climits>
using namespace std;

// Operations On BST - General
/*
Insert
Update
Search
Delete
Traversal
BFT
DFS
In-order, post-order, and
pre-order
Finding minimum
Finding maximum
Finding predecessor
Finding Successor
Finding height
*/

class Node{
public:
    int data;
    Node *right;
    Node *left;
};

Node* createNode(int value){
    Node* newNode = new Node();
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}


Node *insert1(int data, Node *head) // one way to insert
{

    if(head == NULL){
        head = new Node;
        head->data = data;
        head->left = NULL;
        head->right = NULL;
    }

    else if (data < head->data) head->left = insert1(data, head->left);
    else if (data > head->data) head->right = insert1(data, head->right);

    return head;
}

Node* insert2(Node* root, int value){ // 2nd way to insert
    if(root == NULL) return createNode(value);
    if(value<root->data) root->left = insert2(root->left, value);
    else if(value > root->data) root->right = insert2(root->right, value);
    return root;
}


Node* search(Node* root, int value){
    if(root == NULL || root->data == value) return root;
    if(value < root->data) return search(root->left, value);
    else return search(root->right, value);
}


// Traversals (DFS types)

// Inorder
void inorder(Node* root){
    if(root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Preorder
void preorder(Node* root){
    if(root == NULL) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

// Postorder
void postorder(Node* root){
    if(root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}


// Iterative
// ---------- PREORDER (Root → Left → Right) ----------
void preorderIterative(Node* root){
    if (root == NULL) return;

    Node* stack[100];
    int top = -1;

    stack[++top] = root;

    while(top >= 0){
        Node* curr = stack[top--];
        cout << curr->data << " ";

        if (curr->right != NULL)
            stack[++top] = curr->right;
        if (curr->left != NULL)
            stack[++top] = curr->left;
    }
}

// ---------- INORDER (Left → Root → Right) ----------
void inorderIterative(Node* root){
    Node* stack[100];
    int top = -1;
    Node* curr = root;

    while(curr != NULL || top >= 0){
        while(curr != NULL){
            stack[++top] = curr;
            curr = curr->left;
        }

        curr = stack[top--];
        cout << curr->data << " ";
        curr = curr->right;
    }
}

// ---------- POSTORDER (Left → Right → Root) ----------
void postorderIterative(Node* root){
    if (root == NULL) return;

    Node* stack1[100];
    Node* stack2[100];
    int top1 = -1, top2 = -1;

    stack1[++top1] = root;

    while(top1 >= 0){
        Node* curr = stack1[top1--];
        stack2[++top2] = curr;

        if(curr->left != NULL) stack1[++top1] = curr->left;
        if(curr->right != NULL) stack1[++top1] = curr->right;
    }

    while(top2 >= 0){
        cout << stack2[top2--]->data << " ";
    }
}


// ---------- BFS / Level Order Traversal (BFT) ----------
struct Queue{
    Node* arr[100];
    int front = 0, rear = 0;

    void enqueue(Node* n) {arr[rear++] = n;}
    Node* dequeue() {return arr[front++];}
    bool empty() {return front == rear;}
};

void bfs(Node* root){
    if(root == NULL) return;
    Queue q;
    q.enqueue(root);
    while(!q.empty()){
        Node* current = q.dequeue();
        cout << current->data << " ";
        if(current->left) q.enqueue(current->left);
        if(current->right) q.enqueue(current->right);
    }
}


// Max
Node* findMin(Node* root){
    while(root && root->left) root = root->left;
    return root;
}

// Min
Node* findMax(Node* root){
    while(root && root->right) root = root->right;
    return root;
}

// Predecessor: Largest node in left subtree.
Node* findPredecessor(Node* root) {
    if(root->left) return findMax(root->left);
    return NULL;
}

// Successor: Smallest node in right subtree.
Node* findSuccessor(Node* root){
    if(root->right) return findMin(root->right);
    return NULL;
}


// Delete a node
/*
    Three cases:
    Node has no child → just delete
    Node has one child → replace by child
    Node has two children → replace by inorder successor
*/

Node* deleteNode(Node* root, int value){
    if(root == NULL) return root;

    if(value < root->data) root->left = deleteNode(root->left, value);
    else if(value > root->data) root->right = deleteNode(root->right, value);
    else{
        // Case 1 & 2
        if(root->left == NULL){
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if(root->right == NULL){
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // Case 3
        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}


// Update a Value
Node* update(Node* root, int oldValue, int newValue){
    root = deleteNode(root, oldValue);
    root = insert2(root, newValue);
    return root;
}

// Height 
int height(Node* root){
    if(root == NULL) return -1;
    int leftH = height(root->left);
    int rightH = height(root->right);
    return (leftH > rightH ? leftH : rightH) + 1;
}

// Counting Nodes
int countNodes(Node* root){
    if(root == NULL) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// Check if BST is valid
bool isBST(Node* root, int minVal, int maxVal){
    if(root == NULL) return true;
    if(root->data <= minVal || root->data >= maxVal) return false;
    return isBST(root->left, minVal, root->data) && isBST(root->right, root->data, maxVal);
}


int main(){
    Node* root = NULL;
    root = insert2(root, 8);
    root = insert2(root, 3);
    root = insert2(root, 10);
    root = insert2(root, 1);
    root = insert2(root, 6);
    root = insert2(root, 14);
    root = insert2(root, 4);
    root = insert2(root, 7);
    root = insert2(root, 13);

    cout << "Inorder: "; inorder(root); cout << endl;
    cout << "Preorder: "; preorder(root); cout << endl;
    cout << "Postorder: "; postorder(root); cout << endl;

    cout << "Level Order: "; bfs(root); cout << endl;

    cout << "Min: " << findMin(root)->data << endl;
    cout << "Max: " << findMax(root)->data << endl;
    cout << "Height: " << height(root) << endl;

    root = deleteNode(root, 3);
    cout << "After Deletion (3): "; inorder(root); cout << endl;

    root = update(root, 6, 9);
    cout << "After Update (6→9): "; inorder(root); cout << endl;

    return 0;
}
