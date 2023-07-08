//{ Driver Code Starts
#include<iostream>
#include<vector>
using namespace std;

// } Driver Code Ends
//User function Template for C++

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


// T.c - O(E*4alpha + V)



class Solution {
  public:
    int numProvinces(vector<vector<int>> adj, int V) {
        
        DisjointSet dsu(V);
        
        for(int i=0 ; i<V ; i++){
            
            for(int j=0 ; j<V ; j++){
                // means there is an edges between i and j
                if(adj[i][j] == 1){
                    
                    dsu.unionBySize(i,j);
                    
                }
                
                
            }
            
            
        }
        
        int cnt =0;
        
        // Now we just have to check the number of different ultimate parents or no of bosses that are present
        
        for(int i=0 ; i<V ; i++){
            
            if(dsu.findUPar(i) == i) cnt++;
            
        }
        
        return cnt;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends