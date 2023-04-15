#include<iostream>
#include<vector>
#include<map>
#include<queue>

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




Node * createMapping(Node * root , int target , map <Node*,Node*> &nodeToParent){
        
        // Storing targetNode in res
        Node * res = NULL;
        
         // Going for a level order traversal
        queue <Node*> q;
        q.push(root);
        
        // Assigning parent of root as NULL
        nodeToParent[root] = NULL;
        
        
        while(!q.empty()){
            
            
                Node * temp = q.front();
                q.pop();
                
                if(temp->data == target){
                    res = temp;
                }
                
                // If left child exsits then add its parent
                if(temp->left){
                    q.push(temp->left);
                    nodeToParent[temp->left] = temp;
                }
                
                // If right child exsits then add its parent
                if(temp->right){
                    q.push(temp->right);
                    nodeToParent[temp->right] = temp;
                }
            
        }
        
        
        return res; 
        
    }
    
    
    int burnTree(Node * root , map <Node*,Node*> &nodeToParent){
        
        // Start to burn the tree
        
        // 1 . Make visted map 
        
        map <Node*,bool> visited;
        
        visited[root] = true;
        
        // 2. Making a queue to start burning tree
        
        queue <Node *> q;
        q.push(root);
        
        int time = 0;
        
        while(!q.empty()){
            
            int size = q.size();
            
            bool flag = 0;
            
            for(int i=0 ; i<size ; i++){
                
                Node * temp = q.front();
                q.pop();
                
                // Now check for its left child , right child and parent
                
                if(temp->left and !visited[temp->left]){
                    visited[temp->left] =true;
                    q.push(temp->left);
                    flag =1;
                }
                
                if(temp->right and !visited[temp->right]){
                    visited[temp->right] =1;
                    q.push(temp->right);
                    flag = 1;
                }
                
                if(nodeToParent[temp] and !visited[nodeToParent[temp]]){
                    visited[nodeToParent[temp]] = 1;
                    q.push(nodeToParent[temp]);
                    flag = 1;
                }
                
                
            }
            
            if(flag) time++;
   
            
        }
        
        return time;
        
        
    }
    
    
  
    int minTime(Node* root, int target) 
    {
        // 1 . First create node to Parent mapping
        // 2. Find the target node
        // 3. Start Burning the tree 
        
        map <Node*,Node*> nodeToParent;
    
        Node * targetNode = createMapping(root,target,nodeToParent);
        
        int ans = burnTree(targetNode , nodeToParent);
        
        return ans;
        
        // return -1;
    }


    int main(){

        Node * root = NULL;

        root = buildTree(root);

        int target;

        cout << "Enter Target Node Value : " ;
        cin >> target; 

        cout << minTime(root,target) << endl;


    }