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

void inorder(Node * root , vector<int> &ans){

        if(root == NULL) return;

        inorder(root->left , ans);

        ans.push_back(root->data);

        inorder(root->right , ans);

}



// T.C - O(N) and S.C -O(N)

bool isValidBST(Node* root) {
        
        // we know that a valid BST has a sorted inorder traversal

        vector <int> ans;

        inorder(root,ans);

        int n = ans.size();

        for(int i=0 ; i<n-1 ; i++){
            
            if(ans[i] >= ans[i+1]) return false;

        }

        return true;

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

