#include<iostream>
#include<vector>
#include<math.h>
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


Node * preorderToBST(vector <int>& pre , int mini , int maxi , int &i){

    if(i >= pre.size() ){
        return NULL;
    }

    int val = pre[i];

    // base case

    // means not in the current range at this point then return NULL or means do not add any node at this area
    if(val < mini or val > maxi){
        return NULL;
    }


    // means here it is under given range

    // create new node
    Node * root = new Node(val);

    i++; //  increment index in preorder

    root->left = preorderToBST(pre , mini , root->data , i);
    root->right = preorderToBST(pre , root->data , maxi , i);


    return root;
   
}

void inorder(Node * root){

    if(root == NULL) return;

    inorder(root->left);

    cout << root->data << " ";

    inorder(root->right);
}

int main(){

    vector <int> arr;

    int n;
    cout << "Enter size :"; cin >> n;

    cout << "Enter the preOrder data : ";

    for(int i=0 ; i<n ; i++){
        int val;
        cin >> val;

        arr.push_back(val);
    }

    int index = 0;

    Node * root = preorderToBST(arr,INT_MIN,INT_MAX,index);

    inorder(root);
    cout << endl;

}
