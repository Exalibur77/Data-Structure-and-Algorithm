//{ Driver Code Starts
#include<iostream>
#include<vector>
using namespace std;

// } Driver Code Ends
class Solution {
public:

    bool checkComponent(int start , int V , vector<int>adj[] , vector <int> &color){
        
	   queue <int> q;
	   q.push(start);
	  
	   color[start] = 0;
	   
	   while(!q.empty()){
	       
	       int node = q.front();
	       q.pop();
	       
	       for(auto &neighbour : adj[node]){
	           
	           if(color[neighbour] == -1){
	               
	               q.push(neighbour);
	               
	               color[neighbour] = !color[node];
	               
	           }
	           
	           // previously coloured but of same colour as adjacent .. means a cycle has marked it with that colored
	           else if(color[neighbour] == color[node]){
	               return false;
	           }
	       
	           
	       }
	       
	       
	       
	   }
	   
	   return true;
	   
       
        
    }
    


	bool isBipartite(int V, vector<int>adj[]){
	   
	   vector <int> color(V,-1);
	   
	    for(int i=0 ; i<V ; i++){
            
            // not colored yet try color is component
            if(color[i] == -1){
                
                if(checkComponent(i , V , adj , color) == 0) return false;
                
            }
    
            
        }
        
        
	    return true;
	   
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
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends