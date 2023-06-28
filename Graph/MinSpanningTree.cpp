//{ Driver Code Starts
#include<iostream>
#include<vector>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        int sum = 0;
        
        vector <int> visited(V,0);
        
        // A min heap { wt , node} 
        
        priority_queue < pair<int,int> , vector <pair<int,int>> , greater<pair<int,int>> > pq;
        
        // Initially push any random starting node 
        
        pq.push({0,0}); // Assuming wt as 0 and node as 0
        
        while(!pq.empty()){
            
            int node = pq.top().second;
            int wt = pq.top().first;
            
            pq.pop();
            
            // If this node is already visited , just don't operate on it
            if(visited[node] == 1){
                continue;
            }
            
            // If this node is not previously visited
            else{
                
                visited[node] = 1;
                
                sum += wt; // Add the wt in sum
                
                // Now travel accross its neighour who are unvisted
                
                for(auto &it : adj[node]){
                    
                    int newWt = it[1];
                    int neigh = it[0];
                    
                    // If it is unvisited then only push into pq
                    if(!visited[neigh]){
                        
                        pq.push({newWt , neigh});
                        
                    }
                    
                }
                
                
                
            }
            
            
            
        }
        
        return sum;
        
        
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends