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

// Insertion Time Complexity is O(N)

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

void preOrder(Node * &root){

    if(root == NULL) return;

    cout << root->data << endl;

    preOrder(root->left);
    preOrder(root->right);


}

int main(){

    Node * root = NULL;

    cout << "Enter the Data to be inserted in a BST"<< endl;
    inputData(root);

    cout << "PreOrder output of the Binary Search Tree" << endl;
    preOrder(root);


    return 0;
}

