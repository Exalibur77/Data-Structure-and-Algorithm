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

// 1. Traverse left excluding the leaf node of left boundary
void traverseLeft(Node *&root , vector<int> &ans){
        
    if(root == NULL){
        return;
    }
    
    if(root->right == NULL and root->left == NULL){
        return;
    }
        
    ans.push_back(root->data);
        
       // now move left 
    if(root->left){
        traverseLeft(root->left,ans);
    }
        
    // if no left then move right 
    else{
        traverseLeft(root->right,ans);
    }
        
        
        
}


// 2. Leaf node traversal

void traverseLeaf(Node * &root , vector<int> &ans){
        
    if(root == NULL){
        return;
    }
        
    // this is the leaf node
    if(root->left == NULL and root->right == NULL){
        ans.push_back(root->data);
        return;
    }
        
    traverseLeaf(root->left , ans);
    traverseLeaf(root->right , ans);
        
        
}


// 3. Right traversal excluding leaf 
    
void traverseRight(Node * &root , vector<int> &ans){
        
    if(root == NULL){
        return;
    }
        
    if(root->right == NULL and root->left == NULL){
        return;
    }
        
    if(root->right) traverseRight(root->right,ans);
        
    else traverseRight(root->left,ans);
        
    // vapas aate hue values add kar do
    ans.push_back(root->data);
        
        
}


vector <int> boundary(Node *root)
{
        
    vector <int> ans;
    ans.push_back(root->data);
        
    //1 . Traverse left
        
    traverseLeft(root->left , ans);
        
    // 2. Traverse Leaf nodes of both right and left subtree of root node
        
    // left subtree leaf nodes
    traverseLeaf(root->left, ans);
        
    // right subtree leaf nodes
    traverseLeaf(root->right, ans);
        
        
    // 3. Traverse Right
    traverseRight(root->right , ans);
        
    return ans;
}

int main(){

    Node * root = NULL;

    root = buildTree(root);

    auto ans = boundary(root);

    for(auto &val : ans){
        cout << val << endl;
    }




}