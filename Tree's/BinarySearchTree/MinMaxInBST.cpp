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

// right most element would be the maximum value
int findMax(Node * &root){

    if(root == NULL) return INT_MIN;

    Node * temp = root;

    while(temp->right){
        temp = temp->right;
    }

    // Temp node will be the maximum value node

    return temp->data;

}

// left most element would be the min value
int findMin(Node * &root){

    if(root == NULL) return INT_MAX;

    Node * temp = root;

    while(temp->left){
        temp = temp->left;
    }

    // Temp node will be the maximum value node

    return temp->data;

}


int main(){

    Node * root = NULL;

    cout << "Enter Data for BST " << endl;
    inputData(root);


    int maxi = findMax(root);
    int mini = findMin(root);

    cout << maxi << " " << mini << endl;

    return 0;
}