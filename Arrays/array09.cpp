#include<iostream>
using namespace std;

// Using prefix sum approach max_subarray sum is being calculated.
// Time Complexity => O(n^2 + n) = O(n^2)
// Space Complexity => O(n)

int MaxSubarray(int temp[],int n){

    int maxi=INT_MIN;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int cursum=(i>0) ? (temp[j]-temp[i-1]) : temp[j];
            // cout << cursum << " " << maxi << endl;
            maxi=max(maxi,cursum);

        }
    }
    
    return maxi;
}


int main(){

    int arr[]={-1,3,9,-2,12,11,-9};
    int n=sizeof(arr)/sizeof(int);

    // creating an temp array using precomputing.

    int temp[100];
    temp[0]=arr[0];

    for (int i = 1; i < n; i++)
    {
        temp[i]=temp[i-1]+arr[i];
    }


    cout << MaxSubarray(temp,n) << endl;



    return 0;
}