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

// Time Complexity - O(N)
// Space Complexity - O(N)
void solve(Node * root , int k , int target , vector <int> temp , int &ans){
    
    if(root == NULL) return;    
    
    if(root->data == target){
        
        // for(auto &val : temp){
        //     cout << val << " ";
        // }
        // cout << endl;
        
        // if ancestor exsits
        if(temp.size() >= k){
            ans = temp[temp.size()-k];
        }
        
        else ans = -1;
        
        return;
    }
    
    temp.push_back(root->data);
    
    solve(root->left , k , target , temp , ans);
    
    solve(root->right , k , target , temp , ans);
    
    
}


int kthAncestor(Node *root, int k, int node){
    
    vector <int> temp;
    int ans = -1;
    
    solve(root ,k ,node, temp , ans);
    
    
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

}