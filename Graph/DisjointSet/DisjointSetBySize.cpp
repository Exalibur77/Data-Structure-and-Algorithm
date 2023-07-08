#include<iostream>
#include<vector>
using namespace std;

// Time Complexity - O(4*Alpha) ~ O(1)
// Space Complexity - O(N/V)

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

int main(){


    DisjointSet st(7);

    st.unionBySize(1,2);
    st.unionBySize(2,3);
    st.unionBySize(4,5);
    st.unionBySize(6,7);
    st.unionBySize(5,6);

    // check whether 3 and 7 are connected to same component
    if(st.findUPar(3) == st.findUPar(7)){
        cout << "Yes " << 3 << "and " << 7 << " are connected" << endl;
    }

    else{
        cout << "No " << 3 << "and " << 7 << " are not connected" << endl;

    }

    st.unionBySize(3,7);

    // check whether 3 and 7 are connected to same component
    if(st.findUPar(3) == st.findUPar(7)){
        cout << "Yes " << 3 << "and " << 7 << " are connected" << endl;
    }

    else{
        cout << "No " << 3 << "and " << 7 << " are not connected" << endl;
    }



    return 0;
}