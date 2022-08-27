#include<bits/stdc++.h>
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

// Time Complexity - O(N) since we traverse each and every node
int height(Node *& root){

    if(root == NULL) return 0;

    int left = height(root->left);
    int right = height(root->right);

    int ans = max(left,right) + 1;

    return ans;
}

// Time Complexity - O(n^2)  since height is also O(N)
int diameter(Node *& root){

    if(root == NULL) return 0;

    int op1 = diameter(root->left);
    int op2 = diameter(root->right);
    int op3 = height(root->left) + 1 + height(root->right);

    return max(op1,max(op2,op3));


}

// Optimised Approach

// Now here time complexity is being reduced to O(N) and Space Complexity - O(N)
pair<int,int> fastDiameter(Node *&root){

    if(root == NULL) return {0,0};

    pair<int,int> left = fastDiameter(root->left);
    pair<int,int> right = fastDiameter(root->right);

    int op1 = left.first;
    int op2 = right.first;
    int op3 = left.second + 1 + right.second;

    pair <int,int> ans;
    ans.first = max(op1,max(op2,op3)); // this is diameter 
    ans.second = max(left.second,right.second) + 1; // this is height

    return ans;

}



int main(){

    Node * root = NULL;

    root = buildTree(root);

    cout << height(root) << endl;

    cout << diameter(root) << endl;

    cout << fastDiameter(root).first << endl;





}