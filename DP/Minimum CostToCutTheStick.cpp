#include <iostream>
#include<vector>
using namespace std;

int f(int i, int j, vector<int> &cuts,  vector<vector<int>> &dp){
    
    // base case
    if(i>j)
        return 0;
        
    if(dp[i][j]!=-1)
        return dp[i][j];
    
    int mini = INT_MAX;
    
    for(int ind=i; ind<=j; ind++){
        
        int ans = cuts[j+1] - cuts[i-1] +
                    f(i,ind-1,cuts,dp) +
                    f(ind+1,j,cuts,dp);
        
        mini = min(mini, ans);
        
    }
    
    return dp[i][j] = mini;
}


int cost(int n, int c, vector<int> &cuts){
    
    // modify the cuts array
    
    cuts.push_back(n);
    cuts.insert(cuts.begin(),0);
    sort(cuts.begin(),cuts.end());
    
    vector<vector<int>> dp(c+1,vector<int>(c+1,-1));

    return f(1,c,cuts,dp);
}

int costTabulation(int n, int c, vector<int> &cuts){
    
    // cuts.push_back(n);
    // cuts.insert(cuts.begin(),0);
    // sort(cuts.begin(),cuts.end());
    
    vector<vector<int>> dp(c+2,vector<int>(c+2,0));
    
    for(int i=c; i>=1; i--){

        for(int j=i; j<=c; j++){
            
            int mini = INT_MAX;
    
            for(int ind=i; ind<=j; ind++){
        
                int ans = cuts[j+1] - cuts[i-1] + dp[i][ind-1] + dp[ind+1][j];
        
                mini = min(mini, ans);
        
            }
    
            dp[i][j] = mini;
        }
    }
    
    return dp[1][c];

}


int main() {
	
	vector<int> cuts = {3,5,1,4};
	
	int c = cuts.size();
	
	int n = 7;
	
	cout<<"The minimum cost incurred: "<<cost(n,c,cuts) << endl;
	cout<<"The minimum cost incurred: "<<costTabulation(n,c,cuts) << endl;
	
	return 0;
}