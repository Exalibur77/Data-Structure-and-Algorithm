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


pair<int,int> solve(Node * root){
        
        
    // base case
    if(root == NULL) return {0,0};
        
    pair<int,int> leftAns = solve(root->left);
    pair<int,int> rightAns = solve(root->right);
        
    //{including , excluding} in sum the current node
    pair <int, int> res;
        
    // including the current node I am at
    res.first = root->data + leftAns.second + rightAns.second; // adding root data and sum of child nodes excluding the child nodes ie pair.second
        
    // excluding the current node I am at
    res.second = max(leftAns.first,leftAns.second) + max(rightAns.first,rightAns.second);
        
    return res;
        
        
}
  
//Function to return the maximum sum of non-adjacent nodes.
int getMaxSum(Node *root) 
{
        
    pair <int,int> ans = solve(root);
        
    return max(ans.first,ans.second);
    
}

int main(){

    Node * root = NULL;
    root = buildTree(root);

    cout << getMaxSum(root) << endl;


    return 0;
}