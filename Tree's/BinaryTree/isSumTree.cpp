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

// Time Complexity - O(N) and Space Complexity - O(height)


pair<bool,int> isSumTreeFast(Node *&root){
        
    // base case 1
    if(root == NULL){
        return {true,0};
    }
        
    // base case 2 of leaf node
    if(root->left == NULL and root->right == NULL){
        return {true,root->data};
    }
        
    auto leftAns = isSumTreeFast(root->left);
    auto rightAns = isSumTreeFast(root->right);
        
    bool isLeftSumTree = leftAns.first;
    bool isRightSumTree = rightAns.first;
        
    bool condn = (root->data == leftAns.second + rightAns.second);
        
    pair<bool,int> ans;
        
    if(isLeftSumTree and isRightSumTree and condn){
        ans.first = true;
        ans.second = 2 * root->data; // leftAns.second + root->data + rightAns.second
    }
        
    else{
        ans.first = false;
    }
        
    return ans;
        
}
    
    
    
bool isSumTree(Node* &root)
{
    return isSumTreeFast(root).first;
}

int main(){

    Node * root = NULL;

    root = buildTree(root);

    cout << isSumTree(root) << endl;



}