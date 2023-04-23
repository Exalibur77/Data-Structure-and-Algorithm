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

// Insertion Time Complexity is O(log2N) as similar to binary search

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

// O(N) and space O(H)
void inorder(Node* root , Node * &prev){

    if(root == NULL) return;

    inorder(root->left , prev);
    
    prev->left = NULL;
    prev->right = root;
    prev = root;

    inorder(root->right , prev);

}


// T.C - O(N) and S.C - O(H) height
Node* flattenBST(Node* root)
{
    if(root == NULL) return root;

    Node * dummy = new Node(-1);
    Node * prev = dummy;

    inorder(root,prev);

    prev->right = NULL;
    prev->left = NULL;

    return dummy->right;

    // here we have not created n number of nodes , we just changed the links in the tree only
}


void print(Node * root){

    if(root == NULL) return ;

    cout << root->data << " ";

    print(root->right);

}


int main(){

 Node * root = NULL;

    cout << "Enter Data for BST " << endl;
    inputData(root);

    Node * newRoot = flattenBST(root);

    print(newRoot);



}