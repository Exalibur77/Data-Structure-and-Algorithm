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

int findPos(int in[] , int val , int inOrderStart , int inOrderEnd){
        
    for(int i=inOrderStart ; i<=inOrderEnd ; i++){
            
        if(in[i] == val) return i;
            
    }
        
    return -1;
}

Node * solve(int in[] , int post[] , int &index , int InOrderStart , int InOrderEnd , int n){
        
        
    if(index < 0 or InOrderStart > InOrderEnd) return NULL;
        
    // Find the root node value from the preOrder
    int value = post[index--];
        
    // Root value creation
    Node * root = new Node(value);
        
       // Finding position in the inorder vector
    int position = findPos(in,value,InOrderStart,InOrderEnd);
        
        
    root->right = solve(in,post,index,position+1,InOrderEnd,n);
    root->left = solve(in,post,index,InOrderStart,position-1,n);
        
        
    return root;
    
}

Node* constructTree(int in[],int pre[], int n)
{
        
    int PreOrderIndex = n-1;
        
    Node * ans = solve(in,pre,PreOrderIndex,0,n-1,n);
        
    return ans;
        
}

void postOrder(Node * root){

    if(root == NULL){
        return;
    }

    postOrder(root->left);
    postOrder(root->right);

    cout << root->data << " ";

}


int main(){

    int n ;
    cin >> n;

    cout << "Enter InOrder Traversal : " ;

    int in[n] ,post[n];

    for(int i=0 ; i<n ; i++){
        cin >> in[i];
    }

    cout << "Enter PostOrder Traversal : " ;

    for(int i=0 ; i<n ; i++){
        cin >> post[i];
    }

    Node * ans = constructTree(in,post,n);

    postOrder(ans);

    return 0;


}