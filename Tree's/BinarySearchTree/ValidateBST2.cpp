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



bool isValid(Node * root , long  mini , long maxi){

        if(root == NULL){
            return true;
        }

        // if in the given range 
        if(root->data > mini and root->data < maxi){

            bool left = isValid(root->left , mini , root->data);

            bool right = isValid(root->right , root->data ,  maxi);

            // if current node is range and its left and right subtree is valid then retunr truel
            return left and right;

        }

        // otherwise return false
        return false;

}



bool isValidBST(Node* root) {
        
        bool ans = isValid(root , LONG_MIN , LONG_MAX);

        return ans;

}


int main(){

    Node * root = NULL;

    root = buildTree(root);

    if(isValidBST(root)){
        cout << "It is a valid BST" << endl;
    }

    else{
        cout << "It is not a BST" << endl;
    }
    


    return 0;
}

