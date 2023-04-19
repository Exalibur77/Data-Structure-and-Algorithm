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

void inorder(Node * & root){

    Node * curr = root;

    while(curr != NULL){

        // means no left node exists then print node and go right
        if(curr->left == NULL){
            
            cout << curr->data << " ";
            curr = curr->right;

        }

        // if left node exists then make its left subtree right most element to point curr ie make a thread
        else{
            
            // go left on time
            Node * prev = curr->left;

            // continously move right to find right most node in left subtree of the curr node
            // keep a check that you want reach curr .. if threading already exsits
            while(prev->right and prev->right != curr){

                prev = prev->right;
            }

            // no thread exsits then make a thread
            if(prev->right == NULL){

                // thread node made                
                prev->right = curr;
                curr = curr->left; // move current to left so that threading for more left subtree is made
            }

            // thread is already existing
            else{
                // break thread
                prev->right = NULL;

                // print the curr node
                cout << curr->data << " ";

                // left part is traversed and 
                curr = curr->right;

                
            }



        }

    }

    return;

}


void preorder(Node * & root){

    Node * curr = root;

    while(curr != NULL){

        // means no left node exists then print node and go right
        if(curr->left == NULL){
            
            cout << curr->data << " ";
            curr = curr->right;

        }

        // if left node exists then make its left subtree right most element to point curr ie make a thread
        else{
            
            // go left on time
            Node * prev = curr->left;

            // continously move right to find right most node in left subtree of the curr node
            // keep a check that you want reach curr .. if threading already exsits
            while(prev->right and prev->right != curr){

                prev = prev->right;
            }

            // no thread exsits then make a thread
            if(prev->right == NULL){

                // thread node made                
                prev->right = curr;

                // print the curr node
                cout << curr->data << " ";

                curr = curr->left; // move current to left so that threading for more left subtree is made
            }

            // thread is already existing
            else{
                // break thread
                prev->right = NULL;


                // left part is traversed and 
                curr = curr->right;

                
            }



        }

    }

    return;

}

void postorder(Node * & root){

    vector <int> vec;

    Node * curr = root;

    while(curr != NULL){

        // means no right node exists then print node and go left
        if(curr->right == NULL){
            
            // cout << curr->data << " ";
            vec.push_back(curr->data);

            curr = curr->left;

        }

        // if right node exists then make its right subtree left most element to point curr ie make a thread
        else{
            
            // go right one time
            Node * prev = curr->right;

            // continously move left to find left most node in right subtree of the curr node
            // keep a check that you want reach curr .. if threading already exsits
            while(prev->left and prev->left != curr){

                prev = prev->left;
            }

            // no thread exsits then make a thread
            if(prev->left == NULL){

                // thread node made                
                prev->left = curr;

                // print the curr node
                // cout << curr->data << " ";
                vec.push_back(curr->data);


                curr = curr->right; // move current to right so that threading for more right subtree is made
            }

            // thread is already existing
            else{
                // break thread
                prev->left = NULL;


                // left part is traversed  
                curr = curr->left;

                
            }



        }

    }

    reverse(vec.begin(),vec.end());

    for(auto &val : vec){
        cout << val << " ";
    }

    return;

}



// Morris Traversal using Threaded Binary Binary Tree

int main(){


    Node * root = NULL;

    root = buildTree(root);

    // Printing Inorder Traversal using Morris Traversal with using any stack or recursion 

    inorder(root);

    cout << endl;


    // Printing Preorder Traversal using Morris Traversal with using any stack or recursion 
    preorder(root);

    cout << endl;

    // Printing Post Traversal using Morris Traversal with using any stack or recursion 
    postorder(root);

    return 0;
}