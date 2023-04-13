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



Node * solve(Node * root , int &k , int target , int &ans){
    
    if(root == NULL) return NULL;
    
    // if node is found return that node
    if(root->data == target){
        return root;
    }
    
    
    Node * leftAns = solve(root->left , k , target , ans);
    Node * rightAns = solve(root->right , k , target , ans);
    
    
    if(leftAns == NULL and rightAns == NULL) return NULL;
    
    if(leftAns == NULL and rightAns != NULL){
        
        k--;
        
        // we have reached the kth ancestor
        if(k == 0){
            ans = root->data;
        }
        
        return rightAns;
    }
    
    if(leftAns != NULL and rightAns == NULL){
        
        k--;
        
        // we have reached the kth ancestor
        if( k == 0){
            ans = root->data;
        }
        
        return leftAns;
        
    }
    
    return NULL;
    
    
    
}






// your task is to complete this function
int kthAncestor(Node *root, int k, int node)
{
    
    int ans = -1;
    
    Node * res = solve(root , k , node , ans);
    
    // cout << res->data << endl;
    
    return ans;
    
    
    
}


int main(){

Node * root = NULL;

    root = buildTree(root);

    int k , target;
    cout << "Enter K : " ; cin >> k;
    cout << "Target Node : " ; cin >> target;

    int ans = kthAncestor(root,k,target);

    cout << ans << endl;

    return 0;

}