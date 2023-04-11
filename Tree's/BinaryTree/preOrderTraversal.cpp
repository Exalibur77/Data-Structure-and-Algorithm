#include<iostream>
#include<stack>
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

// Iterative
void preOrderTraversal1(Node *&root){

    stack<Node*> stk;

    Node * temp = root;

    while(true){

        if(temp!=NULL){

            cout << temp->data << " ";

            stk.push(temp);

            temp = temp->left;

        }

        else{

            if(stk.empty()) break;

            temp = stk.top();
            stk.pop();

            temp = temp->right;

        }





    }




}

int main(){

    Node * root = NULL;

    root = buildTree(root);

    preOrderTraversal(root);

    cout << endl;

    preOrderTraversal1(root);
    

    return 0;

}