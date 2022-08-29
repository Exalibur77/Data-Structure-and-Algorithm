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

// Without breaks at each level
void levelOrderTraversal(Node * &root){

    queue < Node * > q;
    q.push(root);

    while(!q.empty()){

        Node * temp = q.front();
        q.pop();

        cout << temp->data << " ";

        // if left node exsits add that

        if(temp->left){
            q.push(temp->left);
        }

        if(temp->right){
            q.push(temp->right);
        }

    }
    
    cout << endl;

    return;




}


// traversal with break at each level
void levelOrderTraversal1(Node * &root){

    queue < Node * > q;
    q.push(root);
    // adding NULL node at the end of each level
    q.push(NULL);

    while(!q.empty()){

        Node * temp = q.front();
        q.pop(); 

        // one level has been completed
        if(temp == NULL){
            cout << endl;

            // if q is not empty then add another null at the end to values of next level.
            if(!q.empty()){
                q.push(NULL);
            }

        }


        else{
             cout << temp->data << " ";

            // if left node exsits add that

            if(temp->left){
                q.push(temp->left);
            }

            if(temp->right){
                q.push(temp->right);
            }
        }

       

    }
    
    cout << endl;

    return;

}

vector<vector<int>> levelOrder(Node* root) {
        
    vector<vector<int>> ans;
        
    if(root == NULL) return ans;
        
    queue <Node *> q;
    q.push(root);
        
    while(!q.empty()){
            
        int size = q.size();
        vector <int> level;
            
        // traversing each level
        for(int i=0 ; i<size ; i++){
                
            Node * temp = q.front();
            q.pop();
                
            if(temp->left){
                q.push(temp->left);
            }
                
            if(temp->right){
                q.push(temp->right);
            }
                
            level.push_back(temp->data);
                
        }
        ans.push_back(level);
            
    }
        
    return ans;
        
        
}


int main(){

    Node * root = NULL;

    root = buildTree(root);

    // levelOrderTraversal(root);
    // levelOrderTraversal1(root);

    auto ans = levelOrder(root);

    for(auto &v : ans){
        for(auto &val : v){
            cout << val << " ";
        }
        cout << endl;
    }


    return 0;
    
}
