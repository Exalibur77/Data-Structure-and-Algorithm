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

// O(N)
void solve(Node* root , vector<int> &res){

    if(root == NULL) return;

    solve(root->left , res);


    res.push_back(root->data);

    solve(root->right , res);

}



Node* flattenBST(Node* root)
{

    if(root == NULL) return root;

    
    vector<int> res;

    solve(root,res);

    // Now complete res array is ready now just point right of each node to its next

    Node* newRoot = new Node(res[0]);
    
    Node* curr = newRoot;

    // Space - O(N)

    int n = res.size();

    for(int i=1 ; i<n ; i++){

        Node* temp = new Node(res[i]);
        
        curr->right = temp;
        curr->left = NULL;

        curr = curr->right;


    }
    
    curr->right = NULL;
    curr->left = NULL;

    return newRoot;


}


void inorder(Node * root){

    if(root == NULL) return ;

    cout << root->data << " ";

    inorder(root->right);

}


int main(){

 Node * root = NULL;

    cout << "Enter Data for BST " << endl;
    inputData(root);

    Node * newRoot = flattenBST(root);

    inorder(newRoot);



}