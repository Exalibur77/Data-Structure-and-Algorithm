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

void solve(Node *&root , int currSum , int len , int& maxSum , int &maxLen){
        
    // updating values at the end only
     if(root == NULL){
            
        if(len > maxLen){
            maxLen = len;
            maxSum = currSum;
        }
            
        else if(len == maxLen){
            maxSum = max(maxSum,currSum);
        }
            
            
        return;
    }
        
    currSum = currSum +  root->data;
    len = len+1;
        
    solve(root->left , currSum , len , maxSum , maxLen);
    solve(root->right, currSum , len , maxSum , maxLen);
        
        
}



int sumOfLongRootToLeafPath(Node *root)
{  
    int currSum= 0;
    int maxSum = INT_MIN;
        
    int len = 0;
    int maxLen = 0;
        
    solve(root,currSum,len,maxSum,maxLen);
        
    return maxSum;
}


int main(){

    Node * root = NULL;

    root = buildTree(root);

    cout << sumOfLongRootToLeafPath(root) << endl;

}