//{ Driver Code Starts
#include<iostream>
#include<vector>
using namespace std;

// } Driver Code Ends
class Solution
{
    
    void dfs(int i , vector<int> &visited , vector<vector<int>>& adj , stack<int> &stk){
        
        visited[i] = 1;
        
        
        for(auto &it : adj[i]){
            
            if(!visited[it]){
                
                dfs(it , visited , adj , stk);
                
            }
            
            
        }
        
        stk.push(i);
        
    }
    
    
    void dfsNew(int node , vector <int>&visited , vector <int> adjT[]){
        
        visited[node] = 1;
        
        
        for(auto &it : adjT[node]){
            
            if(!visited[it]){
                
                dfsNew(it , visited , adjT);
                
            }
            
            
        }

        
    }
    
    
	public:
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        
        // Step 1 : Store the nodes according to their time of finish in a dfs
        vector <int> visited(V,0);
        
        // Ultimately we are storing somewhat similar to toposort
        stack <int> stk; 
        
        for(int i=0 ; i<V ; i++){
            
            if(!visited[i]){
               dfs(i , visited , adj , stk);
            }
            
        }
        
        
        // Step 2: Reverse the graph edges
        
        vector <int> adjT[V];
        
        for(int i=0 ; i<V ; i++){
            visited[i] = 0;
            for(auto &it : adj[i]){
                
                // reverse the edge from i -> it as it->i
                adjT[it].push_back(i);
                
            }
        }
        
        
        // Step 3: Start DFS and top of stack which is the starting point and count the no of dfs done
        int cnt = 0;
        
        while(!stk.empty()){
            
            int node = stk.top();
            stk.pop();
            
            if(visited[node] == 0){
                
                cnt++;
                dfsNew(node , visited , adjT);
                
                
            }
            
            
            
        }
        
        return cnt;
        
        
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<vector<int>> adj(V);

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends