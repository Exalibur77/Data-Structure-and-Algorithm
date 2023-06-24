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
        
        // Step 1 : Create a Set  of Pair {dist, node}
        
        set < pair<int,int>> st;
        
        vector <int> distance(V,INT_MAX);
        
        distance[S] = 0;
        
        st.insert({0 , S});
        
        
        while(!st.empty()){
            
            auto itr = st.begin();
            
            int dis = itr->first;
            int node = itr->second;
            
            st.erase(itr);
            
            
            // Moving for adjacent nodes
            
            for(auto &it : adj[node]){
                
                int edgeWt = it[1];
                int neighNode = it[0];
                
                if(dis + edgeWt < distance[neighNode]){
                    
                    // previously present in set with a higher distance
                    if(distance[neighNode] != INT_MAX){
                        
                        // remove it as it would be vain to go via this route
                        st.erase({distance[neighNode] , neighNode});
                        
                    }
                    
                    distance[neighNode] = dis + edgeWt;
                    st.insert({dis + edgeWt , neighNode});
                    
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