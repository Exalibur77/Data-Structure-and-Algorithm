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

// Insertion Time Complexity is O(log2N) as similar to binary search

Node * insertIntoBST(Node * root , int d){

    // base case
    if(root == NULL){

        root = new Node(d);
    
        return root;

    }

    // insert towards right
    if(root->data < d){
        root->right = insertIntoBST(root->right,d);
    }


    else{
        root->left = insertIntoBST(root->left , d);
    }

    return root;


}




void inputData(Node * &root){

    int data;
    cin >> data;

    while(data != -1){

        root = insertIntoBST(root,data);
        cin >> data;

    }


}


void preorder(Node * root){

    if(root == NULL) return;

    cout << root->data << " ";

    preorder(root->left);
    preorder(root->right);
}

void inorderVEC(Node * root , vector<int> &v){

    if(root == NULL) return;

    inorderVEC(root->left,v);

    v.push_back(root->data);

    inorderVEC(root->right,v);
}

void inorder(Node * root ){

    if(root == NULL) return;

    inorder(root->left);

    cout << root->data << " ";

    inorder(root->right);
}

Node * inorderToBST(vector<int> &in , int s , int e){

    if(s>e) return NULL;

    int mid = (s+e)/2;

    // Create a node with value as in[mid]

    Node * root = new Node(in[mid]);

    // creation of left 

    root->left = inorderToBST(in,s,mid-1);

    // creation of right

    root->right = inorderToBST(in,mid+1,e);

    return root;

}

Node * mergeBST(Node *root1 , Node *root2){

    if(root1 == NULL) return root2;

    if(root2 == NULL) return root1;
 
    // step1 : Save root1 and root2  inorder traversals

    vector<int> v1,v2;

//  TC -O(N+M) and S.C - (N+M)
    inorderVEC(root1,v1);
    inorderVEC(root2,v2);

    // Step2 : Merge these sorted 2 vectors.


    int n1 = v1.size();
    int n2 = v2.size();

    vector <int> merged;

    int i=0 , j=0;

//  TC -O(N+M) and S.C - (N+M)

    while(i<n1 and j<n2){

        if(v1[i] < v2[j]){
            merged.push_back(v1[i++]);
        }

        else{
            merged.push_back(v2[j++]);
        }

    }

    while(i<n1){
        merged.push_back(v1[i++]);
    }

    while(j<n2){
        merged.push_back(v2[j++]);
    }


    // Step3 : Convert a Balanced BST using the merged inorder Traversal of both BST

    int size = merged.size();

//  TC -O(N+M) and S.C - (N+M)
    Node * res = inorderToBST(merged,0,size-1);

    return res;

}



int main(){


    Node * root1 = NULL;

    inputData(root1);

    Node * root2 = NULL;

    inputData(root2);

//  TC -O(N+M) and S.C - (N+M)
    Node * res = mergeBST(root1,root2);

    preorder(res);
    cout << endl;
    inorder(res);




}