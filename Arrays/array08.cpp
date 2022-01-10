#include<iostream>
using namespace std;

// Using brute force approach max_subarray sum is being calculated.
// Time Complexity => O(n^3)

int MaxSubarray(int arr[], int n){

    int maxi=INT_MIN;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int cursum=0;

            for (int k = i; k <= j; k++)
            {
                cursum+=arr[k];
            }
            maxi=max(maxi,cursum);
        }
    }
    
    return maxi;
}


int main(){

    int arr[]={12,-23,43,-11,76,-9};

    int n=sizeof(arr)/sizeof(int);

    cout << MaxSubarray(arr,n) << endl;



    return 0;
}