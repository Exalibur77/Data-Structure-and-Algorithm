#include<bits/stdc++.h>
using namespace std;

// creating node for the binary tree

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




void ReverselevelOrderTraversal(Node * &root){

    stack <int> s;
    queue < Node * > q;
    q.push(root);

    while(!q.empty()){

        Node * temp = q.front();
        q.pop();

        s.push(temp->data);

        // here first right node is enqueued to get the reversed order from end

        if(temp->right){
            q.push(temp->right);
        }

        if(temp->left){
            q.push(temp->left);
        }
    }
    
    while(!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }

    return;




}
void ReverselevelOrderTraversal1(Node * &root){

    stack <int> s;
    queue < Node * > q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){

        Node * temp = q.front();
        q.pop();

        if(temp == NULL){

            s.push(-1);

            if(!q.empty()){
                q.push(NULL);
            }


        }

        else{
            s.push(temp->data);

            // here first right node is enqueued to get the reversed order from end

            if(temp->right){
                q.push(temp->right);
            }

            if(temp->left){
                q.push(temp->left);
            }
        }
    }
    
    while(!s.empty()){

        if(s.top() == -1){
            cout << endl;
            s.pop();
        } 

        cout << s.top() << " ";
        s.pop();
    }
    
    return;




}

int main(){

    Node * root = NULL;

    root = buildTree(root);

    ReverselevelOrderTraversal(root);
    ReverselevelOrderTraversal1(root);

    return 0;

}