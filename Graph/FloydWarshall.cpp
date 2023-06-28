//{ Driver Code Starts
//Initial template for C++

#include<iostream>
#include<vector>
using namespace std;

// T.C - O(N^3)

// } Driver Code Ends
//User function template for C++

class Solution {
  public:
	void shortest_distance(vector<vector<int>>&matrix){
	    
	    int n = matrix.size();
	    
	    // First of all mark all the edges that does not exits as 1e9
	    
	    for(int i=0 ; i<n ; i++){
	        
	        for(int j=0 ; j<n ; j++){
	        
	            if(matrix[i][j] == -1) matrix[i][j] = 1e9;
	            
	        }
	        
	    }
	    
	    // Now for every via node compute the shortest distance and at end the best distance matrix will be formed
	    
	    for(int via = 0 ; via<n ; via++){
	        
	        for(int i = 0; i<n ; i++){
	            
	            for(int j=0 ; j<n ; j++){
	                
	                matrix[i][j] = min(matrix[i][j] , matrix[i][via] + matrix[via][j]);  
	                
	            }
	            
	        }
	    }
	    
	    // Now check for any negative cycle exsits or not , we just have to check in our final distance matrix that matrix[i][i] < 0 means a negative cycle
	    
	    // revert back all those 1e9 as -1
	    
	   for(int i=0 ; i<n ; i++){
	        
	        for(int j=0 ; j<n ; j++){
	        
	            if(matrix[i][j] == 1e9) matrix[i][j] = -1;
	            
	        }
	        
	    }
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>matrix(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> matrix[i][j];
			}
		}
		Solution obj;
		obj.shortest_distance(matrix);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cout << matrix[i][j] << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends