#include<iostream>
using namespace std;

int solve(int arr[],int s, int e , int n);

int findPivot(int arr[], int n){

    return solve(arr,0,n-1,n);

}

int solve(int arr[],int s, int e , int n){

    // base case
    if(s>e){
        return -1;
    }

    if(s==e){
        return s;// return e
    }

    int mid = (s+e)/2;

    // processing
    if(arr[mid] > arr[0]){// line 1
        return solve(arr,mid+1,e,n);
    }

    // else if(arr[mid] < arr[n-1]){
        return solve(arr,s,mid,n);
    // }



}





// Find Pivot  
int main(){

    int arr[]={6,7,1,2,3,5};
    int n= sizeof(arr)/sizeof(arr[0]);
    int pivotIndex = findPivot(arr,n);
    cout << pivotIndex << endl;
    return 0;
}