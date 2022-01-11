#include<iostream>
using namespace std;

// return the index of the first occurence of key k
int lastOcc(int arr[] , int n , int k){

    // base case
    if(n==0){
        return -1;
    }

    if(arr[n-1] == k){
        return n-1;
    }

    return lastOcc(arr,n-1,k);



}

int main(){

    int arr[]={7,3,1,2,4,5,1};
    int n = sizeof(arr)/sizeof(arr[0]);

    int ans = lastOcc(arr,n,7);

    cout << ans << endl;

}