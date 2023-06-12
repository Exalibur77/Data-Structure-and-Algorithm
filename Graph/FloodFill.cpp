//{ Driver Code Starts
#include<iostream>
#include<vector>

using namespace std;

// } Driver Code Ends
class Solution {
public:

    void dfs(int row , int col , int n , int m , int prevColor , int newColor , vector <vector<int>>& visited ,vector<vector<int>>& image , int dx[] , int dy[]){
        
        visited[row][col] = 1;
        image[row][col] = newColor;
        
        // now move to all its four directional neighbours
        
        
        for(int i=0 ; i<4 ; i++){
            
            int nrow = row + dx[i];
            int ncol = col + dy[i];
            
            if(nrow >=0 and nrow < n and ncol >= 0 and ncol <m and visited[nrow][ncol] == 0 and image[nrow][ncol] == prevColor){
                
                dfs(nrow , ncol , n , m , prevColor , newColor , visited , image , dx , dy);
                
                
            }
            
            
        }
        
        
        
    }




    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        
        int n = image.size();
        int m = image[0].size();
        
        vector <vector<int>> visited(n , vector<int>(m,0));
        
        int prevColor = image[sr][sc];
        
        int dx[4] = {-1 , +1 , 0 , 0};
        int dy[4] = {0 , 0 , -1 , +1};
        
        
        dfs(sr , sc , n , m , prevColor , newColor , visited , image , dx , dy);
        
        
        
        return image;
        
        
        
        
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends