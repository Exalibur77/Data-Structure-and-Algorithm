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




void preOrderTraversal(Node * &root){

    // N L R

    if(root == NULL)return;

    cout << root->data << " ";

    preOrderTraversal(root->left);

    preOrderTraversal(root->right);

    

}

int main(){

    Node * root = NULL;

    root = buildTree(root);

    preOrderTraversal(root);
    

    return 0;

}