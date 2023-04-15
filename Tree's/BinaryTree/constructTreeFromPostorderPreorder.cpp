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

int findPos(int post[] , int val , int PostOrderStart , int PostOrderEnd){
        
    for(int i=PostOrderStart ; i<=PostOrderEnd ; i++){
            
        if(post[i] == val) return i;
            
    }
        
    return -1;
}

Node * solve(int pre[] , int post[] , int &index , int PostOrderStart , int PostOrderEnd , int n){
        
        
    if(index >= n or PostOrderStart > PostOrderEnd) return NULL;
        
    // Find the root node value from the preOrder
    int value = post[index];
    index++;
        
    // Root value creation
    Node * root = new Node(value);
        

    if(PostOrderStart == PostOrderEnd) return root;


       // Finding position in the post vector
    int position = findPos(post,pre[index],PostOrderStart,PostOrderEnd);
        
    if(position <= PostOrderEnd)

        root->left = solve(pre,post,index,PostOrderStart,position,n);
        root->right = solve(pre,post,index,position+1,PostOrderEnd-1,n);
        
        
    return root;

    
}

Node* constructTree(int pre[],int post[], int n)
{
        
    int PreOrderIndex = 0;
        
    Node * ans = solve(pre,post,PreOrderIndex,0,n-1,n);
        
    return ans;
        
}

void inOrder(Node * root){

    if(root == NULL){
        return;
    }

    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);


}


int main(){

    int n ;
    cin >> n;

    cout << "Enter PreOrder Traversal : " ;

    int pre[n] ,post[n];

    for(int i=0 ; i<n ; i++){
        cin >> pre[i];
    }

    cout << "Enter PostOrder Traversal : " ;

    for(int i=0 ; i<n ; i++){
        cin >> post[i];
    }

    Node * ans = constructTree(pre,post,n);

    inOrder(ans);

    return 0;


}