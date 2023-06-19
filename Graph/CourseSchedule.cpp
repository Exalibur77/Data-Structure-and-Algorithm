//{ Driver Code Starts
#include <iostream>
#include<vector>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
  public:
    vector<int> findOrder(int n, int m, vector<vector<int>> prerequisites) 
    {
        
        // First create an adjacency list 

        vector <int> adj[n];

        for(auto &v : prerequisites){

            int ai = v[0];
            int bi = v[1];

            // since to complete course ai , bi is mandotory or prerequiste
            // create an edge from bi - > ai

            adj[bi].push_back(ai);
        }

        // My graph adjacency lsit is completed

        // If this directed graph has a cycle present in it , then it is not possible , otherwise it is possible

        // Two ways to find a cycle in a directed graph : DFS or BFS(Kahn's Algo)

        // Using Kah's Algo

        // 1. Creating a indegree vector
        vector <int> indegree(n,0);

        for(int i=0 ; i<n ; i++){

            for(auto &it : adj[i]){

                indegree[it]++;

            }

        }

        queue <int> q;
        // 2. Add the zero dependency nodes into queue

        for(int i=0 ; i<n ; i++){
            if(indegree[i] == 0) q.push(i);
        }

        vector <int> topo;
        
        while(!q.empty()){

            int node = q.front();
            q.pop();
            topo.push_back(node);

            // Now reduce dependecy of its neighbour
            for(auto &it : adj[node]){
                
                indegree[it]--;

                // No dependency neighbour is also found just add into queue
                if(indegree[it] == 0){
                    q.push(it);
                }

            }

        }


        // Now if cnt == n means Kahn's algo is successful which means no cycle is present as it is only valid for DAG's

        if(topo.size() != n){
            return {};
        }
       
        return topo;

    }
};

//{ Driver Code Starts.

int check(int V, vector <int> &res, vector<int> adj[]) {
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> prerequisites;

        for (int i = 0; i < m; i++) {
            cin >> u >> v;
            prerequisites.push_back({u,v});
        }
        
        vector<int> adj[n];
        for (auto pre : prerequisites)
            adj[pre[1]].push_back(pre[0]);
        
        Solution obj;
        vector <int> res = obj.findOrder(n, m, prerequisites);
        if(!res.size())
            cout<<"No Ordering Possible"<<endl;
        else
            cout << check(n, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends