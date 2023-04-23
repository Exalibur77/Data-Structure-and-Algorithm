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

void inorderPrint(Node * root){

    if(root == NULL) return;

    inorderPrint(root->left);

    cout << root->data << " ";

    inorderPrint(root->right);
}


void inorder(Node* root , Node * &prev){

    if(root == NULL) return;

    inorder(root->left , prev);
    
    prev->left = NULL;
    prev->right = root;
    prev = root;

    inorder(root->right , prev);

}


// T.C - O(N) and S.C - O(H) height
Node* flattenBST(Node* root)
{
    if(root == NULL) return root;

    Node * dummy = new Node(-1);
    Node * prev = dummy;

    inorder(root,prev);

    prev->right = NULL;
    prev->left = NULL;

    return dummy->right;

    // here we have not created n number of nodes , we just changed the links in the tree only
}

int findLen(Node *& head){

    Node * temp =head;
    int cnt = 0;

    while(temp){
        temp= temp->right;
        cnt++;
    }

    return cnt;

}

Node * LLintoBST(Node * &head , int n){

    if(n<=0 or head == NULL) return NULL;

    Node * left = LLintoBST(head,n/2);

    // create node

    Node * root = head;

    root->left = left;

    head = head->right;

    root->right = LLintoBST(head,n-n/2-1);

    return root;

}



int main(){

    Node * root1 = NULL;

    inputData(root1);

    Node * root2 = NULL;

    inputData(root2);

    Node * head1 = flattenBST(root1);
    Node * head2 = flattenBST(root2);

    // now merge these two linked list 

    Node * dummy = new Node (-1);

    Node * temp = dummy;
    temp->left = NULL;

    while(head1!= NULL and head2!=NULL){

        if(head1->data < head2->data){

            temp->right = head1;
            head1 = head1->right;
            temp = temp->right;

        }

        else{
            temp->right = head2;
            head2 = head2->right;
            temp = temp->right;
        }

    }

    while(head1 != NULL){
        temp->right = head1;
        head1 = head1->right;
        temp = temp->right;
    }

    while(head2 != NULL){

        temp->right = head2;
        head2 = head2->right;
        temp = temp->right;

    }

    // merging of linked lsit is complete with O(1) space and time of O(M+N)
    Node * res = dummy->right;

    int n = findLen(res);

  
    Node * finalAns = LLintoBST(res,n);

    inorderPrint(finalAns);

    return 0;
}