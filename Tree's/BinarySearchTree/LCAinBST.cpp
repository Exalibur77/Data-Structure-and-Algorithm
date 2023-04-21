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

Node* LCAinaBST(Node* root, int P, int Q)
{
    if(root == NULL) return root;
    
    Node* temp = root;

    while(temp!= NULL){
        
        // both node lies in left part
        if(temp->data > P and temp->data > Q){
            temp = temp->left;
        }
        

        // both node lies in right part
        else if(temp->data < P and temp->data < Q){
            temp = temp->right;   
        }
        
        // at any temp where temp->data is in range of (p,Q) or (Q,P) , means temp lies in between of both means the origination of P and Q would have been first occured at the current temp
        else{
            return temp;
        }

        
    }

    return NULL;

}


int main(){

 Node * root = NULL;

    cout << "Enter Data for BST " << endl;
    inputData(root);

    int P,Q;
    cout << "Enter two target nodes values : ";
    cin >> P >> Q;

    cout << LCAinaBST(root,P,Q)->data << endl;


}