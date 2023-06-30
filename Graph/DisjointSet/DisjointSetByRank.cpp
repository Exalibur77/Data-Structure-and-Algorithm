#include<iostream>
#include<vector>
using namespace std;

// Time Complexity - O(4*Alpha) ~ O(1)
// Space Complexity - O(N/V)

class DisjointSet{

    vector <int> parent , rank;

public:

    // Assuming 1 based indexing
    DisjointSet(int n){

        parent.resize(n+1);
        rank.resize(n+1 , 0); // Intially giving rank as 1

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

    void unionByRank(int u , int v){

        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        // means both are already connected as both ultimate parent are already equal
        if(ulp_u == ulp_v) return;

        // Attach lower rank with higher rank
        if(rank[ulp_u] > rank[ulp_v]){
            parent[ulp_v] = ulp_u;
        }

        else if(rank[ulp_v] > rank[ulp_u]){
            parent[ulp_u] = ulp_v;
        }

        // Rank of both's ultimate parent is equal
        else{
            // attach any one and increase its rank to +1

            // attaching v to u
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }

    }



};

int main(){


    DisjointSet st(7);

    st.unionByRank(1,2);
    st.unionByRank(2,3);
    st.unionByRank(4,5);
    st.unionByRank(6,7);
    st.unionByRank(5,6);

    // check whether 3 and 7 are connected to same component
    if(st.findUPar(3) == st.findUPar(7)){
        cout << "Yes " << 3 << "and " << 7 << " are connected" << endl;
    }

    else{
        cout << "No " << 3 << "and " << 7 << " are not connected" << endl;

    }

    st.unionByRank(3,7);

    // check whether 3 and 7 are connected to same component
    if(st.findUPar(3) == st.findUPar(7)){
        cout << "Yes " << 3 << "and " << 7 << " are connected" << endl;
    }

    else{
        cout << "No " << 3 << "and " << 7 << " are not connected" << endl;
    }



    return 0;
}