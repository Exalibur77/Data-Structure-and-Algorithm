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

void solve(Node *&root , vector<int> &ans , int lev){
    
    if(root == NULL) return;
    
    // means this value is to be included
    if(lev == ans.size()){
        ans.push_back(root->data);
    }
    
    // here right call is done prior to left call to get the right view
    solve(root->right,ans,lev+1);
    solve(root->left,ans,lev+1);
    

}




//Function to return a list containing elements of left view of the binary tree.
vector<int> leftView(Node *root)
{
    // can also fetch the first element of each level using the level order traversal
    
    vector <int> ans;
    solve(root,ans,0);
    return ans;
    
}



int main(){

    Node * root = NULL;
    
    root = buildTree(root);

    auto ans = 


    return 0;
}