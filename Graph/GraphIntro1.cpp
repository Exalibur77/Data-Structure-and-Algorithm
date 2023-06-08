#include<iostream>
#include<vector>

using namespace std;

// Creating of a undirected graph using Adjacency matrix
// S.C - O(N^2)
// T.C - O(M)

int main(){

    int n; // denotes no of nodes
    cin >> n;

    int m; // denotes no of edges
    cin >> m;

    vector < vector <int> > adj(n , vector<int>(n,0));

    for(int i=0 ; i<m ; i++){

        int a,b;
        cin >> a >> b;

        adj[a][b] = 1; //  a-b
        adj[b][a] = 1; // b-a For storing directed graph just remove this line

        // Both are connected as it is undirected graph

    }

    for(auto &vec : adj){
        for(auto &val : vec){
            cout << val << " ";
        }
        cout << endl;
    }



}