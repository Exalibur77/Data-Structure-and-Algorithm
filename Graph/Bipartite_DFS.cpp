//{ Driver Code Starts
#include<iostream>
#include<vector>
using namespace std;

// } Driver Code Ends
class Solution {
public:

    // Using DFS traversal

    bool checkComponent(int start , int V , vector<int>adj[] , vector <int> &color , int c){
        
	   color[start] = c;
	   
	   // now start marking all its neighbour
	   
	   for(auto &neighbour : adj[start]){
	       
	       if(color[neighbour] == -1){
	           
	           bool success = checkComponent(neighbour , V , adj , color , !c);
	           
               // As soon as single problem is being identified just return false
	           if(success == false) return false;
	           
	       }
	       
           // Condition for identifying the problem
	       else if(color[neighbour] == color[start]){
	           return false;
	       }
	       
	   }
       
        return true;
        
    }
    
    


	bool isBipartite(int V, vector<int>adj[]){
	   
	   vector <int> color(V,-1);
	   
	    for(int i=0 ; i<V ; i++){
            
            // not colored yet try color is component
            if(color[i] == -1){
                
                if(checkComponent(i , V , adj , color, 0) == 0) return false;
                
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