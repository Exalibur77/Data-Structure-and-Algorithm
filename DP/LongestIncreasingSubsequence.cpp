#include<iostream>
#include<vector>
using namespace std;

// Finding out longest increasing subsequence Lenght

// {10,9,2,5,3,7,101,18} , ans = {2,5,7,101} or {2,5,7,18} .ie length is 4

// f(i , prev_index) , denotes the max size of subsequence uptill i having previous elemenent at index at prev_index
int f(int indx , int prevIndex , vector <int>&arr , int n , vector <vector<int>> &dp){

    if(indx == n){
        return 0;
    }

    if(dp[indx][prevIndex+1] != -1){
        return dp[indx][prevIndex+1];
    }


    int take = INT_MIN;
    int notTake = 0 + f(indx+1 , prevIndex , arr , n , dp);

    // take when curr val is greater than previous one 
    if(prevIndex == -1 or arr[indx] > arr[prevIndex]){
        
        take = 1 + f(indx+1 , i , arr , n , dp);

    }

    return dp[i][prevIndex+1] = max(take , notTake);

}

int longestIncreasingSubsequenceTabulation(vector<int> &arr, int n){
    
    vector<vector<int>> dp(n+1,vector<int>(n+1,0));
    
    for(int ind = n-1; ind>=0; ind --){
        for (int prev_index = ind-1; prev_index >=-1; prev_index --){
            
            int notTake = 0 + dp[ind+1][prev_index +1];
    
            int take = 0;
    
            if(prev_index == -1 || arr[ind] > arr[prev_index]){
                
                take = 1 + dp[ind+1][ind+1];
            }
    
            dp[ind][prev_index+1] = max(notTake,take);
            
        }
    }
    
    return dp[0][-1+1];
}



int lengthOfLIS(vector<int>& nums) {
        
    int n = nums.size();

    // Since for 0 th element previous index is -1 , so we want a dp of [n][n+1]

    // As prev (-1 , 0 . ....n-1)
    vector <vector<int>> dp(n , vector <int>(n+1 , -1));
    
    return f(0 , -1 , nums , n , dp);
        
}


int main(){

    vector <int> arr;

    int n;
    cin >> n;

    for(int i=0 ; i<n ; i++){
        cin >> arr[i];
    }

    int x = lengthOfLIS(arr);

    cout << x << endl;

    return 0;
}