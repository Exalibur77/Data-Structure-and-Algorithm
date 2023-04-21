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

void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{

    if(root == NULL) return;
    
    if(root->data == key){
         

        // finding predecssor 
        
        if(root->left){
            
            Node * temp = root->left;
            
            while(temp->right){
                temp = temp->right;
            }
            
            pre = temp;
            
        }
        
        
        // finding successor
        
        if(root->right){
            
            Node * temp = root->right;
            
            while(temp->left){
                temp = temp->left;
            }
            
            
            suc = temp;
            
        }
        
        
        
    }
    
    // means find in the left subtreee and mark it as possible successor
    if(root->data > key){
        
        suc = root;
        findPreSuc(root->left , pre , suc , key);
        
    }


    if(root->data < key){
        
        pre = root;
        findPreSuc(root->right , pre , suc , key);
        
    }
    

}

// Iterative Approach 

void findPreSuc1(Node* root, Node*& pre, Node*& suc, int key)
{

    pre = NULL;
    suc = NULL;
    
    Node * temp1 = root;

    while(temp1){
        
        // find out the successor , left most node in right subtree
        if(temp1->data > key){
            
            suc = temp1;
            temp1 = temp1->left;
            
        }
        
        else{
            temp1 = temp1->right;
        }
    }
    
    
    Node * temp2 = root;
    
    while(temp2){
        
        // finding out the predecessor , right most node in left subtree
        if(temp2->data < key){
            pre = temp2;
            temp2 = temp2->right;
        }
        
        else{
            temp2 = temp2->left;
        }
        
        
    }
    
    
}

int main(){

 Node * root = NULL;

    cout << "Enter Data for BST " << endl;
    inputData(root);

    Node * pre = NULL;
    Node * succ = NULL;

    int key;
    cout << "Enter key value : "; cin >> key;

    findPreSuc1(root,pre,succ,key);

    cout << "Predecessor of " << key << " : " << pre->data << endl;
    cout << "Successor of " << key << " : " << succ->data << endl;


}