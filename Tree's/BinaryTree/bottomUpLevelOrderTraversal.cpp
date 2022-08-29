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

vector<vector<int>> BottomUplevelOrder(Node* root) {
        
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

    reverse(ans.begin(),ans.end());    
    
    return ans;
        
        
}

int main(){


    Node * root = NULL;

    root = buildTree(root);

    auto ans = BottomUplevelOrder(root);

    for(auto &v : ans){
        for(auto &val : v){
            cout << val << " ";
        }
        cout << endl;
    }




    return 0;
}