#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

// Creating of a undirected graph using Adjacency list
// S.C - O(2*M)
// T.C - O(M)

int main(){

    int n; // denotes no of nodes
    cin >> n;

    int m; // denotes no of edges
    cin >> m;

    // vector <int> adj[n+1]; //  using 1 based indexing
    // vector<vector<int>> adj(n+1);  

    unordered_map <int , vector<int> > adj;


    for(int i=0 ; i<m ; i++){

        int u,v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u); // remove this to have a directed graph using adjacency list

    }

    // for(auto &vec : adj){
    //     for(auto &val : vec){
    //         cout << val << " ";
    //     }
    //     cout << endl;
    // }

    // printing if we initialise using a map
    for(auto &p : adj){

        cout << p.first <<  " -> ";

        for(auto &val : p.second ){
            cout << val << " ";
        }

        cout << endl;

    }



}