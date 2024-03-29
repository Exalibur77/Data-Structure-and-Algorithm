#include<iostream>
#include<stack>
#include<vector>
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




void postOrderTraversal(Node * &root){

    // L R N

    if(root == NULL)return;


    postOrderTraversal(root->left);

    postOrderTraversal(root->right);

    cout << root->data << " ";
    

}

void postOrderTraversal1(Node *&root){

    Node *temp = root;

    stack <Node*> stk;

    stk.push(temp);

    vector <int> ans;

    while(!stk.empty()){

        temp = stk.top();
        stk.pop();
        ans.push_back(temp->data);

        if(temp->left){
            stk.push(temp->left);
        }

        if(temp->right){
            stk.push(temp->right);
        }


    }

    reverse(ans.begin(),ans.end());

    for(auto & val : ans){
        cout << val << " ";
    }



}



int main(){

    Node * root = NULL;

    root = buildTree(root);

    postOrderTraversal(root);
    cout << endl;
    postOrderTraversal1(root);

    return 0;

}