#include<bits/stdc++.h>
using namespace std;

// creating node for the binary tree

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

Node * buildTree(Node * root){

    cout << "Enter the data : " ;
    int data;
    cin >> data;

    if(data == -1){
        return NULL;
    }

    root = new Node(data);

    // making left and right of the current root node

    cout << "Enter the data for inserting in left of " << data << endl;
    root->left = buildTree(root->left);

    cout << "Enter the data for inserting in right of " << data << endl;
    root->right = buildTree(root->right);

    // original root node of the tree
    return root;

}

bool isIdentical(Node * &r1, Node * &r2){
    // base case
    if(r1 == NULL and r2 == NULL) return true;
        
    if(r1 == NULL and r2 != NULL) return false;
        
    if(r1 != NULL and r2 == NULL) return false;
        
    bool left = isIdentical(r1->left,r2->left);
    bool right = isIdentical(r1->right,r2->right);
        
    bool val = r1->data == r2->data;
        
    if(left and right and val) return true;
        
    return false;
        
}



int main(){

    Node * root1 = NULL;
    Node * root2 = NULL;

    cout << "Building Tree 1" << endl;
    root1 = buildTree(root1);

    cout << "Building Tree 2" << endl;
    root2 = buildTree(root2);

    cout << isIdentical(root1,root2) << endl;

    return 0;
    
}