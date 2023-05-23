#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Node{
    
public:
    int data;
    int i;
    int j;

    Node(int data , int i , int j) {
        this->data = data;
        this->i = i;
        this->j = j;
    }
};

class Cmp{

    public:
    bool operator()(Node * a , Node * b){
        return a->data > b->data; //. since in MIN heap data data is stored like 12 5 1 in container with 1 having max priority
    }

};

// T.C - O(N*K*logK)
// S.C - O(K) + O(N*K)

vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    // Using min Heap 

    priority_queue < Node* , vector<Node*> , Cmp > pq;

    for(int i=0 ; i<k ; i++){

        Node * temp = new Node(kArrays[i][0],i,0);
        pq.push(temp);
    }


    vector <int> ans;

    // now the top value will be the first value of the result

    while(pq.size() > 0){

        Node * temp = pq.top();
        ans.push_back(temp->data);
        pq.pop();
        
        int row = temp->i;
        int col = temp->j;
        
        if(col+1 < kArrays[row].size()){
            
            Node * next = new Node(kArrays[row][col+1] , row , col+1);
            pq.push(next);
            
        }
 
    }

    return ans;
    
}

int main(){

    vector <vector<int>> v;

    int k;
    cout << "Enter Number of vectors : ";
    cin >> k;

    for(int i=0 ; i<k ; i++){

        int n;
        cout << "Enter size of row : "  ; cin >> n;

        vector <int> row(n);

        for(int j=0 ; j<n ; j++){
            
            cin >> row[j];

        }

        v.push_back(row);
    }

    vector <int> ans = mergeKSortedArrays(v,k);

    for(auto &val : ans){
        cout << val << " ";
    }
    cout << endl;

    return 0;

}
