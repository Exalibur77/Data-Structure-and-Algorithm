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


void inorder(Node * root){

    if(root == NULL) return;

    inorder(root->left);

    cout << root->data << " ";

    inorder(root->right);


}


// T.c - O(N) and S.C - O(1)
void flatten1(Node * root) {
        
       // using morris tarversal approach
        
        Node * curr = root;
        
        while(curr != NULL){
            
            // left subtree exsits , then make predescendant -> curr->right
            if(curr->left != NULL){
                
                Node * prev = curr->left;
                
                while(prev->right){
                    prev = prev->right;
                }
                
                // now make thread
                prev->right = curr->right;
                curr->right = curr->left;
                
                curr->left = NULL;
                
            }
    
            // moving curr's right every time 
            
            curr = curr->right;
            
        }


}

// TC- O(N) and SC -O(N)
void flatten2(TreeNode* root) {
        
        // Using stack
       
       if(root == NULL) return;

       stack <Node*> stk;
       stk.push(root);
       
       while(!stk.empty()){
           
           Node * curr = stk.top();
           stk.pop();
           
           // first right node is added
           if(curr->right != NULL){
               stk.push(curr->right);
           }
           
            if(curr->left != NULL){
               stk.push(curr->left);
            }
           
            if(!stk.empty()){
                curr->right = stk.top();
            }
            
            
            curr->left = NULL;
           
       }
       




}



Node * prev = NULL;
    
void flatten3(TreeNode *root)
{
        
        if(root == NULL) return;
        
        flatten(root->right);
        flatten(root->left );
        
        root->right = prev;
        root->left = NULL;
        
        prev = root;
        
    
}

int main(){


    Node * root = NULL;

    root= buildTree(root);


    flatten1(root);
    inorder(root);





}