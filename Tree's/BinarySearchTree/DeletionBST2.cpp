
#include<iostream>
#include<vector>

using namespace std;

class Node{

    public:
        int data;
        Node * left;
        Node * right;

    // constructor

    Node (int x){
        data = x;
        left = NULL;
        right = NULL;
    }

};

// Insertion Time Complexity is O(log2N) as similar to binary search

Node * insertIntoBST(Node * root , int d){

    // base case
    if(root == NULL){

        root = new Node(d);
    
        return root;

    }

    // insert towards right
    if(root->data < d){
        root->right = insertIntoBST(root->right,d);
    }


    else{
        root->left = insertIntoBST(root->left , d);
    }

    return root;


}




void inputData(Node * &root){

    int data;
    cin >> data;

    while(data != -1){

        root = insertIntoBST(root,data);
        cin >> data;

    }


}



Node * findMax(Node * root){
    
    while(root->right){
        root = root->right;
    }
    return root;
    
}




Node *deleteNode(Node *root, int X) {
    
    
    if(root == NULL) return root;
    
    if(root->data == X){
        
        // 0 child
        
        if(root->left == NULL and root->right == NULL){
            
            delete root;
            return NULL;
            
        }
        
        // 1 child
        
        if(root->left != NULL and root->right == NULL){
            
            Node * temp = root->left;
            delete root;
            
            return temp;
            
        }
        
        
        if(root->left == NULL and root->right != NULL){
            
            Node * temp = root->right;
            delete root;
            
            return temp;
            
        }
        
        
        // 2 child
        if(root->left != NULL and root->right != NULL){
            
            // by coping data of predecessor
            int leftMax = findMax(root->left)->data;
            
            root->data = leftMax;
            
            // deleting that predecessor node in the left
            root->left = deleteNode(root->left , leftMax);
            
            return root;
            
        }
        
        
    }
    
    if(root->data > X){
        
        root->left = deleteNode(root->left , X);
        
    }
    
    else{
        
        root->right = deleteNode(root->right , X);
        
    }
    
    return root;
    
}

void inorder(Node * root){

    if(root == NULL) return;

    inorder(root->left);

    cout << root->data << " ";

    inorder(root->right);


}


int main(){

    Node * root = NULL;

    cout << "Enter the Data to be inserted in a BST"<< endl;
    inputData(root);

    int target;
    cout << "Enter target value : ";
    cin >> target;

    inorder(root);

    cout << endl;

    deleteNode(root,target);

    inorder(root);


}