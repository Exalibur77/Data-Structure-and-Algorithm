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

Node * helper(Node * root);

// Function to delete a node from BST.
Node *deleteNode(Node *root, int X) {
    
    if(root == NULL){
        return root;
    }
    
    // deleting the root node
    if(root-> data == X){
        return helper(root);
    }
    
    
    Node * temp = root;
    
    while(temp!=NULL){
        
        // we have to move left
        if(temp->data > X){
            
            if(temp->left and temp->left->data == X){
            
                temp->left = helper(temp->left);
                break;
            }
            
            else{
                temp = temp->left;
            }
        }
        
        else{
            
            if(temp->right and temp->right->data == X){
                
                temp->right =helper(temp->right);
                break;
                
            }
            
            else{
                temp = temp->right;
            }
            
            
        }    
     
        
    }

    return root; 
   
    
}


Node * find(Node * root){
    
    while(root->left){
        
        root = root->left;
        
    }
    
    return root;
    
}


Node * helper(Node * root){
    
    // no left subtree then just directly connect to right subtree
    if(root->left == NULL){
        return root->right;
    }
    
    else if(root->right == NULL){
        return root->left;
    }
    
    Node * leftChild = root->left;
    
    // finding the successor
    Node * rightsLeftMost = find(root->right);
    
    rightsLeftMost->left = leftChild;
    
    return root->right;
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

    Node * newNode = deleteNode(root,target);

    inorder(newNode);


}