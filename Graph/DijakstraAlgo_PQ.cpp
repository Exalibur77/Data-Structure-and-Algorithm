//{ Driver Code Starts
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        
        // Step 1 : Create a Priority Queue or Min heap of Pair {dist, node}
        
        priority_queue < pair<int,int> , vector<pair<int,int>> , greater <pair<int,int>> > pq;
        
        
        vector <int> distance(V,INT_MAX);
        
        distance[S] = 0;
        
        // Distance with Node
        pq.push({0 , S});
        
        
        while(!pq.empty()){
            
            int dis = pq.top().first;
            int node = pq.top().second;
            
            pq.pop();
            
            // Moving for adjacent nodes
            
            for(auto &it : adj[node]){
                
                int edgeWt = it[1];
                int neighNode = it[0];
                
                if(dis + edgeWt < distance[neighNode]){
                    distance[neighNode] = dis+edgeWt;
                    pq.push({dis+edgeWt , neighNode});
                }
                
                
                
            }
          
            
        }
        
        return distance;
        
        
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
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends