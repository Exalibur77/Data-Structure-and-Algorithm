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


void print(Node * root){

    if(root == NULL) return;

    cout << root->data << " ";

    print(root->right);


}

void postOrder(Node * root , Node * &prev){

    if(root == NULL) return;

    postOrder(root->left , prev);
    postOrder(root->right , prev);

    prev->right = root;
    prev->left = NULL;

    prev = root;

}

void inorder(Node * root , Node * &prev){

    if(root == NULL) return;

    inorder(root->left , prev);

    prev->right = root;
    prev->left = NULL;

    prev = root;

    inorder(root->right , prev);


}

Node * p = NULL;

void preorder(Node * root){

    if(root == NULL) return;
    // going under reverse pre order traversal

    preorder(root->right);
    preorder(root->left);

    root->right = p;
    root->left = NULL;
    p = root;
}


// TC - O(N) , SC - O(H)
Node * flattenIntoPostOrderLL(Node * root){

    Node * dummy = new Node(-1);

    Node * prev = dummy;

    postOrder(root,prev);

    prev->right = NULL;
    prev->left = NULL;

    Node * ans = dummy->right;

    delete dummy;

    return ans;

}

// TC- O(N) , SC- O(H)
Node * flattenIntoInOrderLL(Node * root){

    Node * dummy = new Node(-1);


    Node * prev = dummy;

    inorder(root,prev);

    prev->right = NULL;
    prev->left = NULL;

    Node * ans = dummy->right;

    delete dummy;

    return ans;

}

// TC- O(N) , SC- O(H)
Node * flattenIntoPreOrderLL(Node * root){

    preorder(root);

    return root;
}

int main(){

    Node * root = NULL;

    root = buildTree(root);

    // Node * newRoot = flattenIntoPostOrderLL(root);

    // Node * newRoot = flattenIntoInOrderLL(root);

    Node * newRoot = flattenIntoPreOrderLL(root);

    print(newRoot);
    

    return 0;
}

