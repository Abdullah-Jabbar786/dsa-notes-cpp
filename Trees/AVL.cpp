#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;
    int height;
};

int height(Node* n){
    if (n==NULL) return 0;
    return n->height;
}

int max(int a, int b){
    return (a > b) ? a : b;
}

Node* createNode(int key){
    Node* node = new Node();
    node->data = key;
    node->left = node->right = NULL;
    node->height = 1;
    return node;
}

int getBalance(Node* n){
    if(n==NULL) return 0;
    return height(n->left) - height(n->right);
}

// --------------- Rotations ---------------

Node* rightRotate(Node* y){
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

Node* leftRotate(Node* x){
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

// --------------- Insertion ---------------
Node* insert(Node* root, int key){
    if(root == NULL) return createNode(key);

    if(key < root->data) root->left = insert(root->left, key);
    else if(key > root->data) root->right = insert(root->right, key);

    else return root; // duplicate not allowed

    root->height = 1 + max(height(root->left), height(root->right));

    int balance = getBalance(root);

    // LL
    if(balance > 1 && key < root->left->data) return rightRotate(root);

    // RR
    if (balance < -1 && key > root->right->data) return leftRotate(root);

    // LR
    if (balance > 1 && key > root->left->data){
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // RL
    if(balance < -1 && key < root->right->data){
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

// --------------- Find Min/Max ---------------

Node* findMin(Node* node){
    while (node->left != NULL) node = node->left;
    return node;
}

Node* findMax(Node* node){
    while(node->right != NULL) node = node->right;
    return node;
}

// --------------- Deletion ---------------

Node* deleteNode(Node* root, int key){
    if (!root) return root;

    if (key < root->data) root->left = deleteNode(root->left, key);
    else if (key > root->data) root->right = deleteNode(root->right, key);

    else{
        // Node with one or no child
        if(root->left == NULL || root->right == NULL){
            Node* temp = (root->left) ? root->left : root->right;
            if(temp == NULL){
                temp = root;
                root = NULL;
            } 
            else *root = *temp;
            delete temp;
        }
        // Node with two children
        else{
            Node* temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }

    if(root == NULL) return root;

    root->height = 1 + max(height(root->left), height(root->right));

    int balance = getBalance(root);

    // LL
    if(balance > 1 && getBalance(root->left) >= 0) return rightRotate(root);

    // LR
    if(balance > 1 && getBalance(root->left) < 0){
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // RR
    if (balance < -1 && getBalance(root->right) <= 0) return leftRotate(root);

    // RL
    if(balance < -1 && getBalance(root->right) > 0){
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

// --------------- DFS Traversals ---------------

void inOrder(Node* root){
    if(root != NULL){
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }
}

void preOrder(Node* root){
    if(root != NULL){
        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder(Node* root){
    if(root != NULL){
        postOrder(root->left);
        postOrder(root->right);
        cout << root->data << " ";
    }
}

// --------------- BFS (Level Order Traversal) ---------------

void printLevel(Node* root, int level){
    if(root == NULL) return;
    if(level == 1)
        cout << root->data << " ";
    else if(level > 1){
        printLevel(root->left, level - 1);
        printLevel(root->right, level - 1);
    }
}

int treeHeight(Node* root){
    if (root == NULL) return 0;
    int lh = treeHeight(root->left);
    int rh = treeHeight(root->right);
    return 1 + ((lh > rh) ? lh : rh);
}

void BFS(Node* root){
    int h = treeHeight(root);
    for (int i = 1; i <= h; i++) printLevel(root, i);
}

// --------------- MAIN ---------------

int main(){
    Node* root = NULL;

    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

    cout << "Preorder (DFS): ";
    preOrder(root);
    cout << "\nInorder (DFS): ";
    inOrder(root);
    cout << "\nPostorder (DFS): ";
    postOrder(root);
    cout << "\nLevel Order (BFS): ";
    BFS(root);

    cout << "\n\nMin: " << findMin(root)->data;
    cout << "\nMax: " << findMax(root)->data;
    cout << "\nHeight: " << treeHeight(root);

    root = deleteNode(root, 40);
    cout << "\n\nAfter deleting 40, Inorder: ";
    inOrder(root);
}