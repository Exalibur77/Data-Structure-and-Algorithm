#include<iostream>
#include<vector>
#include<string>

using namespace std;


bool isValid(string &curr , string &prev){

    int n = curr.size();
    int m = prev.size();
    
    int i = 0;
    int j = 0;

    bool skip = false;

    while(i < n and j < m){

        if(curr[i] != prev[j]){

            if(skip) return false;

            else skip = true;

            i++;
        }

        else{
            i++; j++;
        }

    }

    return true;
}

  
int f(int indx , int prev_indx , vector<string> &arr , vector<vector<int>> &dp){

    if(indx == arr.size()) return 0;

    if(dp[indx][prev_indx+1] != -1) return dp[indx][prev_indx+1];

    int notTake = 0 + f(indx+1 , prev_indx , arr,dp);

    int take = INT_MIN;

    // Size difference should be 1 and only one character difference should be there in the same order as prev
    if(prev_indx == -1 or (arr[indx].size() - arr[prev_indx].size() == 1 and isValid(arr[indx] , arr[prev_indx]) ) ){
        take = 1 + f(indx+1 , indx , arr,dp);
    }

    return dp[indx][prev_indx+1] = max(take , notTake);

}

bool static cmp(string &a , string &b){
    return a.size() < b.size();
}


int longestStrChainTabulation(vector<string>& arr) {
    
    int n = arr.size();

    sort(arr.begin() , arr.end() , cmp);

    vector <int> dp(n , 1);

    int maxi = -1;

    for(int indx = 0 ;  indx < n ;  indx++){

        for(int prev_indx = indx-1 ; prev_indx >= 0 ; prev_indx--){

            if(arr[indx].size() - arr[prev_indx].size() == 1 and isValid(arr[indx] , arr[prev_indx])){

                dp[indx] = max(dp[indx] , dp[prev_indx] +1);

            }

        }

        maxi = max(maxi , dp[indx]);

    }




    return maxi;

}

int longestStrChain(vector<string>& arr){

    int n = arr.size();

    sort(arr.begin() , arr.end() , cmp);

    vector <vector<int>> dp(n , vector <int>(n+1 , -1));

    return f(0 , -1, arr , dp);
}

int main() {
	
	vector<string> words = {"a","b","ba","bca","bda","bdca"};
	
	cout<<" The length of the longest string chain is : "<<longestStrChain(words) << endl;
	cout<<" The length of the longest string chain is : "<<longestStrChainTabulation(words) << endl;
	
    return 0;
}