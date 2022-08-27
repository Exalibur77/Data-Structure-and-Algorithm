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

int sum(Node *& root){

    if(root == NULL) return 0;

    if(root->left == NULL and root->right == NULL) return root->data;

    int leftSum = sum(root->left);
    int rightSum = sum(root->right);

    int ans = root->data + leftSum + rightSum;

    return ans;

}



int main(){

    Node * root = NULL;

    root = buildTree(root);

    cout << sum(root);

    return 0;
    
}