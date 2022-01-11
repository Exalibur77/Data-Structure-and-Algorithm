#include<iostream>
using namespace std;

// return the index of the first occurence of key k
int firstOcc(int arr[] , int n , int k){

    // base case
    if(n==0){
        return -1;
    }

    if(arr[0] == k){
        return 0;
    }

    int subAns = firstOcc(arr+1,n-1,k);
    if(subAns !=-1){
        return subAns+1;
    }
    return -1;



}

int main(){

    int arr[]={2,3,1,4,5,1};
    int n = sizeof(arr)/sizeof(arr[0]);

    int ans = firstOcc(arr,n,5);

    cout << ans << endl;

}