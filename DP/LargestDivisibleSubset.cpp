#include<iostream>
#include<vector>
using namespace std;

vector<int> largestDivisibleSubset(vector<int>& nums) {

        int n = nums.size();

        if(n == 1) return nums;

        sort(nums.begin() , nums.end());

        vector <int> dp(n,1);// storing the max lenght of such subsequence
        vector <int> parent(n);

        // Since a , b , c... ie of c%b == 0 and b%a == 0 then difinately c%a == 0

        int maxLength = 0;

        for(int indx = 0 ;  indx < n ; indx++){

            parent[indx] = indx;

            for(int prev_indx = indx-1 ; prev_indx >= 0 ; prev_indx--){

                if(nums[indx] % nums[prev_indx] == 0 and dp[prev_indx] +1 > dp[indx]){

                    dp[indx] = 1 + dp[prev_indx];

                    parent[indx] = prev_indx;
                }

            }

            maxLength = max(maxLength , dp[indx]);

        }

        int lastIndex;

        for(int i = 0 ; i<n ; i++){
            if(dp[i] == maxLength) lastIndex = i;
        }

        vector<int> ans;

        ans.push_back(nums[lastIndex]);

        while(lastIndex != parent[lastIndex]){

            lastIndex = parent[lastIndex];
            ans.push_back(nums[lastIndex]);

        }

        reverse(ans.begin() , ans.end());

        return ans;
}

int main() {
	
	vector<int> arr = {1,16,7,8,4};
	
	vector<int> ans = largestDivisibleSubset(arr);
	
	cout<<" The longest divisible subset elements are: ";
	
	for(int i=0; i<ans.size(); i++){
	    cout<<ans[i]<<" ";
	}
}