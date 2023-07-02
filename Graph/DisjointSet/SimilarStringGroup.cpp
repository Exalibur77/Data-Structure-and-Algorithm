#include<iostream>
#include<vector>
using namespace std;



class DisjointSet{


public:
    vector <int> parent , size;

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

bool isSimilar(string &str1 , string &str2){

    if(str1 == str2) return true;

    int n = str1.size();

    int cntDiff = 0;

    for(int i=0 ; i<n ; i++){

        if(str1[i] != str2[i]) cntDiff++;

        if(cntDiff > 2) return false;

    }

    return true;

}


class Solution {
public:
    int numSimilarGroups(vector<string>& strs) {

        int n = strs.size();

        DisjointSet st(n);

        for(int i=0 ; i<n ; i++){

            for(int j=i+1 ; j<n ; j++){

                if(isSimilar(strs[i] , strs[j])){

                    st.unionBySize(i,j);

                }
            }

        }

        int cntCompo = 0;
        // Now question boils down to just find the componenents in the graph

        for(int i=0 ; i<n ; i++){

            // Ultimate parent
            if(st.parent[i] == i){
                cntCompo++;
            }

        }

        return cntCompo;

    }
};


int main(){

    Solution obj1;

    vector <string> vec = {"tars","rats","arts","star"};

    cout << obj1.numSimilarGroups(vec);


    return 0;

}