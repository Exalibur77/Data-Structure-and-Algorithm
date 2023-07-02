class Solution {
public:

    int timer = 1;

    void dfs(int node , int parent , vector <int> &visited , vector <int> adj[] , vector <int>&tin , vector<int> &low , vector <vector<int>> &bridges){

        visited[node] = 1;

        tin[node] = low[node] = timer;

        timer++;

        for(auto &it : adj[node]){

            // No need to do anything
            if(it == parent) continue;

            // Adjacent node is not visited 
            if(visited[it] == 0){
                
                dfs(it , node , visited , adj , tin , low , bridges);

                // While returning when all the dfs is being completed for given node

                low[node] = min(low[node] , low[it]);

                // can this node -- it be a bridge

                if(low[it] > tin[node]){
                    bridges.push_back({it,node});
                }


            }

            // currNode neighbour is visited so we have to update its lo time 
            else{

                low[node] = min(low[node] , low[it]);
                // bridge is not possible as a cycle is being forming if we have already visited my adjacent node , means I am coming from the same path only

            }



        }

    }






    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {

        // First Create an adjacency list

        vector <int> adj[n];

        for(auto &vec : connections){

            int u = vec[0];
            int v = vec[1];

            adj[u].push_back(v);
            adj[v].push_back(u);

        }

        vector <int> visited(n,0);
        vector <int> tin(n,0);
        vector <int> low(n,0);

        vector < vector <int> > bridges;

        dfs(0 , -1 , visited , adj , tin , low , bridges);

        return bridges;


    }
};