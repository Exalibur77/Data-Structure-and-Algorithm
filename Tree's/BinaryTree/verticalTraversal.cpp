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

    
    
vector<int> verticalOrder(Node *root){


    vector <int> ans;
    if(root == NULL) return ans;
        
    // horizontal dis - > lvel -- > nodes
    map < int , map < int , vector<int>> > mp;
        
    // node              HD       Level
    queue < pair< Node* , pair<int,int>> > q;
        
    q.push({root,{0,0}}); // root's node level is zero and hd = 0
        
    while(!q.empty()){
            
        int size = q.size();
            
        for(int i=0 ; i<size ; i++){
                
            auto temp = q.front();
            q.pop();
                
            Node *node = temp.first;
            int hd = temp.second.first;
            int level = temp.second.second;
                
                
            mp[hd][level].push_back(node->data);
                
            if(node->left){
                q.push({node->left , {hd-1,level+1}});
            }
                
            if(node->right){
                q.push({node->right , {hd+1,level+1}});
            }
                
                
        }
   
    }
        
        
    for(auto &i : mp){
            
        for(auto &j : i.second){
            
            for(auto &k : j.second){
                    
                ans.push_back(k);
                    
            }
                
        }
            
            
    }
        
    return ans;
        
        
}




int main(){

    Node * root = NULL;

    root = buildTree(root);

    vector <int> ans = verticalOrder(root);

    for(auto &val : ans){
        cout << val << " ";
    }





}