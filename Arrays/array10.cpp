#include<iostream>
using namespace std;

// Using kadanes algorithm approach max_subarray sum is being calculated.
// Time Complexity => O(n) Best Solution

int Kadanes(int arr[],int n){

    int maxi=INT_MIN;
    int cursum=0;
    for (int i = 0; i < n; i++)
    {
        cursum+=arr[i];

        maxi=max(cursum,maxi);

        if(cursum < 0){
            cursum=0;
        }
    }
    
    return maxi;
}


int main(){

    // int arr[]={-1,3,9,-2,12,11,-9};
    int arr[]={-1,-2,-3,-90};
    int n=sizeof(arr)/sizeof(int);


    cout << Kadanes(arr,n) << endl;



    return 0;
}