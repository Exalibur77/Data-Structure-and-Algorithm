#include<iostream>
using namespace std;

void fillArray(int arr[] , int n , int i){

    // base case
    if(i==n){
        return;
    }

    // processing
    arr[i]=i+1;

    // recursive call
    fillArray(arr,n,i+1);

    // backTrack Statement this being executed after returning from the base case.
    arr[i] = arr[i]*-1;

}



int main(){

    int arr[100];
    int n; cin >> n;

    fillArray(arr,n,0);
    cout << endl;
    for(int i=0 ; i<n ; i++){
        cout << arr[i] << " ";
    }


}