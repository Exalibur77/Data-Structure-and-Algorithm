#include<iostream>
#include<queue>
using namespace std;

class Node{

    public:

    Node *left;
    Node * right;
    int data;

    Node(int x){
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

int countNodes( Node* tree){
      if(tree == NULL)
      return 0;
      
      int ans  = 1 + countNodes(tree->left) + countNodes(tree->right);
      
      return ans;
}
  

 // to check whether the tree is CBT(complete Binary Tree) or not 

//T.C -> O(n)

bool isCBT(struct Node* tree,int i, int count){
      
      if(tree == NULL){
          return true;
      }
      
      if(i >= count)
      return false;
      
      else{
        bool left = isCBT(tree->left, 2*i+1,count);
        bool  right = isCBT(tree->right, 2*i+2,count);
          
          return(left && right);

      }
      
}

 

//to find maxorder using heap

// T.C -> O(n)

bool isMaxorder(Node* tree){

      if(tree->left == NULL && tree->right==NULL )
      {
          return true;
      }
      
       if(tree->right == NULL){
           return (tree->data > tree->left->data);
       }
       
       else
       {
        bool left = isMaxorder(tree->left);
        bool right = isMaxorder(tree->right);
       
       return (left && right &&
       (tree->data > tree->left->data && tree->data > tree-> right->data));
           
       
        }
}

// heap function

bool isHeap(Node* tree) {
        
        int index = 0;
        int countNode  = countNodes(tree);
        if(isCBT(tree,index,countNode)  && isMaxorder(tree)){
            return true;
        }
        else{
            return false;
        }
}

bool isHeap1( Node* root) {
        
        if(root == NULL) return true;
        
        // using level order traversal
        
        queue <Node*> q;
        q.push(root);
        
        bool flag = 0; // means no NULL has been encountered before
        
        while(!q.empty()){
            
            Node * temp = q.front();
            q.pop();
            
            
            if(temp->left){
                
                // check whether any previous NULL is not there
                if(flag or temp->left->data > temp->data) return false;
                
                q.push(temp->left);
                
            }
            else{
                flag = 1; // NULL encountered
            }
            
            
            if(temp->right){
                
                // any previous NULL is there
                if(flag or temp->right->data > temp->data) return false;
                
                q.push(temp->right);
                
            }
            else{
                flag = 1; // NULL encountered
            }
            
            
            
        }
        
        return true;
        
}

int main(){

    Node * root = NULL;

    root = buildTree(root);

    cout << isHeap(root);
    cout << endl;
    cout << isHeap1(root);

}