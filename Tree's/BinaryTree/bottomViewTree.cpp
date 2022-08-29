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

vector<int> topView(Node *root){
        
    vector <int> ans;
        
    if(root == NULL) return ans;
        
    // create a 1-1 mapping with horizontal distance and root data 
        
    map <int,int> mp;
    queue<pair<Node*,int>> q;
    q.push({root,0});
        
    while(!q.empty()){
            
        int size = q.size();
            
        for(int i=0 ; i<size ; i++){
                
            auto temp = q.front();
            q.pop();
                
            Node * curr = temp.first;
            int hd = temp.second;
                
            // data is tend to change for each HD since we want the last element to added on that index
            mp[hd] = curr->data;
                
            if(curr->left){
                q.push({curr->left,hd-1});
            }
                
            if(curr->right){
                q.push({curr->right,hd+1});
            }
                
        }
 
    }
        
    for(auto &p : mp){
        ans.push_back(p.second);
    }
        
        
    return ans;
}



int main(){

    Node * root = NULL;
    
    root = buildTree(root);

    auto ans = 


    return 0;
}