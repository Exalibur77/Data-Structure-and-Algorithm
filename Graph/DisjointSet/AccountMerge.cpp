//{ Driver Code Starts
//Initial Template for C++
#include<iostream>
#include<vector>
#include<map>
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


class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        
        // Step 1 : We will create a map for every mail with index 

        unordered_map <string,int> mapMailNode;

        int n = accounts.size();

        DisjointSet st(n);

        for(int i=0 ; i<n ; i++){
            // since emails are starting from index 1
            for(int j=1 ; j<accounts[i].size() ; j++){

                string mail = accounts[i][j];

                // No such previous mail is there
                if(mapMailNode.find(mail) == mapMailNode.end()){
                    mapMailNode[mail] = i;
                }

                // Some previous index is having this mail
                else{

                    int prevNode = mapMailNode[mail];

                    // Attach this current node to prevNode

                    st.unionBySize(i , prevNode);

                }

            }


        }


        // Merging has been done , so now iterating over map , find Ultimate parent of each node and push that mail in that

        vector <string> mergeMail[n];
        
        for(auto &it : mapMailNode){

            string mail = it.first;

            // Actual parent in which this mail is to be appended
            int index = st.findUPar(it.second);

            mergeMail[index].push_back(mail);

        }

        vector<vector<string>> ans;

        // Now our task attach name in front and sort the mails

        for(int i=0 ; i<n ; i++){

            // It is being merged to someone else
            if(mergeMail[i].size() == 0) continue;

            else{
                
                sort(mergeMail[i].begin() , mergeMail[i].end());
                
                vector <string> temp;

                // insert name in temp first

                temp.push_back(accounts[i][0]);

                // now insert all emails after the name is being added

                for(auto &str : mergeMail[i]){
                    temp.push_back(str);
                }

                ans.push_back(temp);


            }

        }

        return ans;

    }
};


//{ Driver Code Starts.
int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    vector<vector<string>> accounts;

    for (int i = 0; i < n; i++)
    {
      vector<string> temp;
      int x;
      cin >> x;

      for (int j = 0; j < x; j++)
      {
        string s1;
        cin >> s1;
        temp.push_back(s1);
      }
      accounts.push_back(temp);
    }

    Solution obj;
    vector<vector<string>> res = obj.accountsMerge(accounts);
    sort(res.begin(), res.end());
    cout << "[";
    for (int i = 0; i < res.size(); ++i)
    {
      cout << "[";
      for (int j = 0; j < res[i].size(); j++)
      {
        if (j != res[i].size() - 1)
          cout << res[i][j] << ","
               << " ";
        else
          cout << res[i][j];
      }
      if (i != res.size() - 1)
        cout << "], " << endl;
      else
        cout << "]";
    }
    cout << "]"
         << endl;
  }
}
// } Driver Code Ends