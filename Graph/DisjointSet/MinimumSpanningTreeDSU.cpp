#include<iostream>
#include<vector>
using namespace std;

// } Driver Code Ends

class DisjointSet{

    vector <int> parent , size;

public:

    // Assuming 1 based indexing
    DisjointSet(int n){

        parent.resize(n+1);
        size.resize(n+1 , 1); // Intially giving size as 1

        for(int i=0 ; i<=n ; i++){
            parent[i] = i; //  making themself as their parent
        }

    }

    // Function to find ultimate parent
    int findUPar(int node){

        if(node == parent[node]){
            return node; // this is the ultimate parent
        }

        return parent[node] = findUPar(parent[node]);
        // Step for path compression
    }

   void unionBySize(int u , int v){

        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        // means both are already connected as both ultimate parent are already equal
        if(ulp_u == ulp_v) return;

        if(size[ulp_u] > size[ulp_v]){

            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];

        }

        else{

            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];

        }

    }



};


class Solution
{

	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        
        DisjointSet st(V); // initialise a disjoint set of size v
        
        // Now we have to sort all the edges according to the wt
        
        // T.C - O(V + E)
        vector < vector<int> > edges;
        
        for(int i=0 ; i<V ; i++){
            
            for(auto &it : adj[i]){
                
                int u = i;
                int v = it[0];
                int wt = it[1];
                
                edges.push_back({wt , u , v});
                
                
            }
            
            
        }
        
        // E * Log(E)
        sort(edges.begin() , edges.end());
        
        
        int mst = 0;
        
        // E * 4 * alpha
        for(int i=0 ; i<edges.size() ; i++){
            
            int wt = edges[i][0];
            int u = edges[i][1];
            int v = edges[i][2];
            
            // Now just check whether u & v are connected or in same component
            
            if(st.findUPar(u) != st.findUPar(v)){
                // Not connected so required to connect
                
                mst += wt;
                
                // also make them connected
                st.unionBySize(u , v);
                
            }
            
            
            
        }
        
        
        // Total T.C - O(ElogE + E + V + E*apha) ~ O(E*logE + E)
        
        
        return mst;
        
        
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