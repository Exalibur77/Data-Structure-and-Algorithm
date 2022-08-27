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

// Time Complexity - O(N) since we traverse each and every node
int height(Node *& root){

    if(root == NULL) return 0;

    int left = height(root->left);
    int right = height(root->right);

    int ans = max(left,right) + 1;

    return ans;
}

bool isBalanced(Node *root){
        
    //base case
    if(root == NULL) return 1;
        
    bool left = isBalanced(root->left);
    bool right = isBalanced(root->right);
        
    bool diff = abs(height(root->left) - height(root->right) ) <= 1 ;
        
    if(left and right and diff){
        return 1;
    }
        
    return 0;
        
}

// Optimised Approach

// Now here time complexity is being reduced to O(N) and Space Complexity - O(N)
pair<bool,int> fastIsBalanced(Node * &root){
        
    if(root == NULL){
        return {1,0};
    }
        
    auto left = fastIsBalanced(root->left);
    auto right = fastIsBalanced(root->right);
        
    bool leftAns = left.first;
    bool rightAns = right.first;
        
    bool diff =  abs(left.second - right.second) <= 1 ;
        
    pair <bool,int> ans;
        
    ans.first = leftAns and rightAns and diff ? 1 : 0; 
        
    ans.second = max(left.second,right.second)+1;
        
    return ans;
        
        
}



int main(){

    Node * root = NULL;

    root = buildTree(root);

    cout << height(root) << endl;
    cout << fastIsBalanced(root).second << endl;

    cout << isBalanced(root) << endl;

    cout << fastIsBalanced(root).first << endl;



}