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



void solve(Node* root , int &i , int k , int &ans){

    if(root == NULL){
        return;
    }


    solve(root->left , i , k , ans);

    // increase i 
    i++;

    if(i == k){
        // cout << "K th smallest node exsits" << endl;
        ans = root->data;
        return;
    }
    
    solve(root->right , i , k , ans);


}


int kthSmallest(Node * root, int k) {
    // Write your code here.

    int i = 0;
    int ans = -1;
    solve(root , i , k , ans);
    
    return ans;

}

int main(){

    Node * root = NULL;

    cout << "Enter the Data to be inserted in a BST"<< endl;
    inputData(root);

    int k;
    cout << "Enter K : " ; cin >> k;

    cout << kthSmallest(root,k) << endl;

    return 0;
}