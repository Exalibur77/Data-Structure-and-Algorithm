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


void inorder(Node * root){

    if(root == NULL) return;

    inorder(root->left);

    cout << root->data << " ";

    inorder(root->right);
}

void preorder(Node * root){

    if(root == NULL) return;

    cout << root->data << " ";
    preorder(root->left);

    preorder(root->right);
}

Node * inorderToBST(vector <int>& arr , int s , int e){

    if(s>e)return NULL;

    // first create a node with mid value

    int mid = (s+e)/2;

    Node * root = new Node(arr[mid]);

    root->left = inorderToBST(arr,s,mid-1);
    root->right = inorderToBST(arr,mid+1,e);

    return root;
}



int main(){

    vector <int> arr;

    int n;
    cout << "Enter size :"; cin >> n;
    
    for(int i=0 ; i<n ; i++){
        int val;
        cin >> val;

        arr.push_back(val);
    }

    Node * root = inorderToBST(arr,0,n-1);

    inorder(root);
    cout << endl;

    preorder(root);


}
