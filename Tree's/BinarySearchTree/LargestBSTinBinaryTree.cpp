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


class info{

public:

    int maxi;
    int mini;

    bool isBST;
    int size;

};  

info solve(Node* root , int &ans){

    if(root == NULL){
        return {INT_MIN , INT_MAX , 1 , 0};
    }

    // leaf node
    if(root->left == NULL and root->right == NULL){
        return {root->data , root->data , true , 1};
    }


    info left = solve(root->left , ans);
    info right = solve(root->right , ans);

    info currNode;

    // left subtree maximum
    currNode.maxi = max(right.maxi,root->data);

    // right subtree minimum
    currNode.mini = min(left.mini,root->data);

    // updating size
    currNode.size = left.size + 1 + right.size;

    // all threee condition satisfied then 
    if(left.isBST and right.isBST and (root->data > left.maxi and root->data < right.mini)){

        currNode.isBST = true;
    }

    else{
        currNode.isBST = false;
    }

    // update the ans
    if(currNode.isBST == true){
        ans = max(ans , currNode.size);
    }

    return currNode;
}

int largestBST(Node* root) 
{
    int ans = 0;

    info temp = solve(root , ans);

    return ans;
}

int main(){

    Node * root = NULL;

    root = buildTree(root);

    cout << largestBST(root);

    return 0;
}
