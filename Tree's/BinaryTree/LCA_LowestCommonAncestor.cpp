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



void solve(Node * root , int target , vector<Node*> temp , vector<Node*> &ans){

    if(root == NULL) return;

    // base case
    if(root->data == target){
        temp.push_back(root);
        ans = temp;
        return;
    }


    temp.push_back(root);

    solve(root->left,target,temp,ans);

    solve(root->right,target,temp,ans);

}


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


//Function to return the lowest common ancestor in a Binary Tree.
Node* lca1(Node* root ,int n1 ,int n2 ){
       
    vector<Node*> temp;
       
    vector<Node*> v1,v2;
       
    solve(root,n1,temp,v1);
    solve(root,n2,temp,v2);
        
    int i = v1.size()-1;
    int j = v2.size()-1;
        
    if(i > j){
            
        while(v1[i--]->data != v2[j]->data and i!=j);
 
    }
        
    if(j > i){
            
        while(v1[i]->data != v2[j--]->data and i!=j);
            
    }
        
        
    while(v1[i]->data != v2[j]->data){
            
        i--;
        j--;
            
    }
        
    return v1[i];
}


Node* lca2(Node* root ,int n1 ,int n2 ){
       
   // base case
   if(root == NULL) return NULL;
       
   if(root->data == n1 or root->data == n2){
       return root;
   }
       
   Node * leftAns = lca2(root->left,n1,n2);
   Node * rightAns = lca2(root->right,n1,n2);
       
       
   // it means we are on the LCA node
   if(leftAns != NULL and rightAns != NULL){
       return root;
   }
       
   else if(leftAns != NULL and rightAns == NULL){
       return leftAns;
   }
       
   else if(leftAns == NULL and rightAns != NULL){
       return rightAns;
   }
       
   else{
       return NULL;
   }
       
       
}






int main(){

    Node * root = NULL;

    root = buildTree(root);

    int t1,t2;
    cin >> t1 >> t2;

    cout << endl;

    cout << lca1(root,t1,t2)->data;

    cout << endl;

    cout << lca2(root,t1,t2)->data;


    return 0;
}

// 1 9 8 -1 -1 12 -1 -1 3 -1 10 -1 -1