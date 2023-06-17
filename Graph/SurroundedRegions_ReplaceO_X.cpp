//{ Driver Code Starts
// Initial Template for C++

#include <iostream>
#include<vector>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    
    int dx[4] = {0 , 0 , -1 , 1};
    int dy[4] = {-1 , 1 , 0 , 0};


    void dfs(vector<vector<char>> &mat ,  vector < vector <int> > &visited , int row , int col , int n , int m){
        
        
        visited[row][col] = 1;   
        
        // now go for all the neighbours
        for(int i=0 ; i<4 ; i++){
            
            int newRow = row + dx[i];
            int newCol = col + dy[i];
            
            if(newRow >=0 and newRow < n and newCol >=0 and newCol < m and visited[newRow][newCol] == 0 and mat[newRow][newCol] == 'O'){
                
                dfs(mat , visited , newRow , newCol , n, m);
                
            }
            
            
        }
        
        
        
        
    }


    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        
        vector < vector <int> > visited ( n , vector <int> (m , 0));
        
        // Now go for boundary 0's and mark visited all those 0 which are connected to a boundary 0 whcih will never be changes to a X
        
        for(int i=0 ; i<n ; i++){
            
            for(int j=0 ; j<m ; j++){
                
                
                if(i == 0 or j == 0 or i == n-1 or j == m-1){
                    
                   if(mat[i][j] == 'O' and visited[i][j] == 0){
                       
                    //   cout << i << " " << j << endl;
                       
                       dfs(mat , visited , i , j , n , m);
                       
                   }                     
                    
                }
                
                
                
                
            }
            
            
            
        }
        
        
        // Now mark all the O as X which are not being visited
        
        for(int i=0 ; i<n ; i++){
            
            for(int j=0 ; j<m ; j++){
                
                // not visited O means a not boundary connected O
                if(mat[i][j] == 'O' and visited[i][j] == 0){
                    mat[i][j] = 'X';
                }
                
                
            }
            
            
        }
        
        
        return mat;
        
        
        
        
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends