#include<iostream>
#include <queue>
#include<climits>

using namespace std;

class Node{

public: 
    int data;
    int i;
    int j;

    Node(int data , int i , int j){

        this->data = data;
        this->i = i;
        this->j = j;

    }

};

struct cmp{

    bool operator() (Node * a , Node * b){
        return a->data > b->data ; // min Heap
    }


};


int kSorted(vector<vector<int>> &a, int k) {

    int mini = INT_MAX;
    int maxi = -1;

    // Step 1 : Add all first values into the min Heap 
    priority_queue <Node* , vector<Node*> , cmp> pq;

// T.C - O(K * logK)
    for(int i=0 ; i<k ; i++){

        int val = a[i][0];

        maxi = max(maxi , val); // updating maxi along side adding into pq
        
        Node * temp = new Node(val,i,0);

        pq.push(temp);

    }

    int ans = INT_MAX; //. finding the min range length
    
// T.C - O(N*K * logK)
    while(!pq.empty()){

        Node * temp = pq.top();
        pq.pop();

        mini = temp->data; // top nodes data would be the minimum of all k

        int range = maxi-mini+1;

        if(range < ans) ans = range;

        // Addition of the next value .. ie increasing the mini

        int row = temp->i;
        int col = temp->j;

        // withing the given size
        if(col+1 < a[row].size()){

            // next value may update our previous maximum

            maxi = max(maxi , a[row][col+1]);

            Node * next = new Node(a[row][col+1] , row , col+1);
            pq.push(next);

        }

        // Means the current lists ends which means that we would break as now the new range would not include elements of this comleted array

        else{
            break;
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

    int ans = kSorted(v,k);

    cout << ans << endl;

    return 0;

}