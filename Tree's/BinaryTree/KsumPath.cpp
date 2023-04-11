#include<iostream>
#include<vector>
#include<unordered_map>
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

unordered_map <int,int> mp;
    
void solve(Node * root , int k , int sum , int &count){
        
    if(root == NULL) return ;
        
    sum += root->data;
        
    count = count + mp[sum-k];
        
    if(sum == k){
        count ++;
    }
        
    mp[sum]++;
        
    solve(root->left , k , sum , count);
    solve(root->right , k , sum ,count);
        
        
    // backtrap step since we are using a universal map
        
    mp[sum]--;
        
    
}


int sumK(Node *root,int k)
{
        
    int sum = 0;
    int count = 0;
        
    solve(root,k,sum,count);
        
    return count;
        
}



int main(){


    Node * root = NULL;

    root = buildTree(root);

    cout <<  sumK(root,3) << endl;



    return 0;
}