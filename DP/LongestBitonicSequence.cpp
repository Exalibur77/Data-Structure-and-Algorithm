#include<iostream>
#include<vector>


int longestBitonicSubsequence1(vector<int>& arr, int n)
{

	vector <int> dp1(n , 1);
	vector <int> dp2(n , 1);

	// Finding LCS from 0 .. n-1
	for(int i= 0 ; i<n ; i++){

		for(int prev = i-1 ; prev >=0 ; prev--){

			if(arr[prev] < arr[i]){
				dp1[i] = max(dp1[i] , 1 + dp1[prev]);
			}

		}
	}

	// Now finding out the Longest Decreasing subsequence from 0 to n-1 
	// Or LCS from (n-1 , 0)

	for(int i = n-1 ; i>=0 ; i--){

		for(int prev = i+1 ; prev < n; prev++){

			if(arr[prev] < arr[i]){
				
				dp2[i] = max(dp2[i] , 1 +dp2[prev]);

			}


		}

	}


	int ans = -1;

	// Now for every index just maxmimise the lcs and lds from it but decrease 1 beacuse i th element is included in both of them

	for(int i= 0 ; i<n ; i++){

		ans = max(ans , dp1[i] + dp2[i] - 1);

	}

	return ans;


}


int longestBitonicSubsequence2(vector<int>& arr, int n)
{

	vector <int> dp1(n , 1);
	vector <int> dp2(n , 1);

	// Finding LCS from 0 .. n-1
	for(int i= 0 ; i<n ; i++){

		for(int prev = i-1 ; prev >=0 ; prev--){

			if(arr[prev] < arr[i]){
				dp1[i] = max(dp1[i] , 1 + dp1[prev]);
			}

		}
	}

    // Reverse the array
	reverse(arr.begin() , arr.end());

	// Finding LCS from 0 .. n-1 of reversed part
	for(int i= 0 ; i<n ; i++){

		for(int prev = i-1 ; prev >=0 ; prev--){

			if(arr[prev] < arr[i]){
				dp2[i] = max(dp2[i] , 1 + dp2[prev]);
			}

		}
	}

    // Now reverse the Dp to have LDS for all i
	reverse(dp2.begin() , dp2.end());


	int ans = -1;

	// Now for every index just maxmimise the lcs and lds from it

	for(int i= 0 ; i<n ; i++){

		ans = max(ans , dp1[i] + dp2[i] - 1);

	}

	return ans;


}




int main() {
	
	vector<int> arr = {1, 11, 2, 10, 4, 5, 2, 1};
	int n = arr.size();
	
	cout<<"The length of the longest bitonic subsequence is "
        <<longestBitonicSequence(arr,n);
	
	return 0;
}