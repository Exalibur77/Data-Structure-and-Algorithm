//{ Driver Code Starts
//Initial Template for C++
#include<iostream>
#include<vector>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  
  int timer = 1;

    void dfs(int node , int parent , vector <int> &visited , vector <int> adj[] , vector <int>&tin , vector<int> &low , vector<int> &mark){

        visited[node] = 1;

        tin[node] = low[node] = timer;

        timer++;

        int child = 0;

        for(auto &it : adj[node]){

            // No need to do anything
            if(it == parent) continue;

            // Adjacent node is not visited 
            if(visited[it] == 0){
                
                dfs(it , node , visited , adj , tin , low , mark);

                // While returning when all the dfs is being completed for given node

                low[node] = min(low[node] , low[it]);

                // can this node -- it be a bridge

                if(low[it] >= tin[node] and parent != -1){
                    mark[node] =1;
                }

                child++;

            }

            // currNode neighbour is visited so we have to update its lo time 
            else{

                low[node] = min(low[node] , tin[it]);
               

            }
        }
        
        if(child > 1 and parent == -1){
            mark[node] = 1;
        }

    }
  
 
  
  
    vector<int> articulationPoints(int V, vector<int>adj[]) {
        
        vector <int> visited(V,0);
        vector <int> tin(V,0);
        vector <int> low(V,0);

        vector <int> mark(V,0);
        
        for(int i=0 ; i<V ; i++){
            
            if(!visited[i]){
                
                dfs(i , -1 , visited , adj , tin , low , mark);
                
            }
            
            
        }
        
        vector <int> ans;
        
        for(int i=0 ; i<V ; i++){
            
            if(mark[i] == 1) ans.push_back(i);
            
            
        }
        
        if(ans.size() == 0) return {-1};
        
        return ans;
        
    }
};

//{ Driver Code Starts.

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		vector<int> ans = obj.articulationPoints(V, adj);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends