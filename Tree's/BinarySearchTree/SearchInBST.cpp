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

// Iterative Apporach - Avg O(H) , skew O(n) , Sc- O(1)
bool searchInBST(Node  *root, int x) {
    // Write your code here.

    Node *temp = root;

    while(temp){

        if(temp->data == x) return true;

        // move right
        else if(temp->data < x){
            temp = temp->right;
        }

        else{
            temp = temp->left;
        }
        
    }

    return false;

}

// T.C - O(H) , SC - O(H) due to recursion stack
void solve(Node *root, int x , bool &ans){

    // base case 
    if(root == NULL) return;

    // if target value is meet
    if(root->data == x){
        ans = 1;
        return;
    }

    // TARGET value is greater than the current node value then move right
    if(x > root->data){
        solve(root->right , x , ans);
    }

    else{
        solve(root->left , x , ans);
    }


}



int main(){

    Node * root = NULL;

    cout << "Enter the Data to be inserted in a BST"<< endl;
    inputData(root);

    int target;
    cout << "Enter target value : ";
    cin >> target;

    cout << endl;

    cout << searchInBST(root,target) << endl;

    bool ans = false;
    solve(root,target,ans);
    cout << ans << endl;

    return 0;
}
