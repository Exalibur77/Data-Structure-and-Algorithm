//{ Driver Code Starts
// Initial Template for C++

#include <iostream>
#include<vector>
#include<queue>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    
    private:
    
    pair <int,int> solve(string &a , string &b){
        
        if(a == b) return {-1,-1};
        
        int i=0 ;
        int j=0;
        
        while(i<a.size() and j<b.size()){
            
            // pt of difference 
            if(a[i] != b[j]){
                
                return {a[i]-'a' , b[i]-'a'};
                
            }
            
            i++;
            j++;
            
            
        }
        
        // If no point of difference uptill this lenght
        return {-1,-1};
        
    }
    
    
    public:
    
    
    string findOrder(string dict[], int N, int K) {
        //code here
        
        vector<int> adj[K];
        
        for(int i=0 ; i<N-1 ; i++){
            
            // now finding out the first mismatch and return us a u->v edge
            
            pair <int , int> edge = solve(dict[i] , dict[i+1]);
            
            int u = edge.first;
            int v = edge.second;
            
            if(u != -1 and v!=-1){
                // make a directed edge from u->v
                adj[u].push_back(v);
            }
            
        }
        
        // In this way my graph has been created , Now I just have to give a valid toposort of it
        
        vector <int> indegree(K,0);
        
        for(int i=0 ; i<K ; i++){
            
            for(auto &it : adj[i]){
                
                indegree[it]++;
                
            }
            
        }
        
        queue <int> q;
        
        // Now push all elements have indegree as 0
        
        for(int i=0 ; i<K ; i++){
            
            if(indegree[i] == 0) q.push(i);
            
        }
        
        
        string ans;
        
        while(!q.empty()){
            
            int node = q.front();
            q.pop();
            
            ans.push_back(node+'a');
            
            // traverse for its neighbour and reduce their dependency
            
            for(auto &it : adj[node]){
                
                indegree[it]--;
                
                if(indegree[it] == 0){
                    q.push(it);
                }
                
            }
            
        }
        
        return ans;
        
    }
};

//{ Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends