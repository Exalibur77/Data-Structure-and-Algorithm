#include<iostream>
using namespace std;

bool isSorted(int arr[], int n){

    // Base Case
    
    if( n==1 or n==0){
        return 1;
    }

    if(arr[0] > arr[1]){
        return false;
    }

    return isSorted(arr+1,n-1);

}



int main(){

    int arr[]={1,3,5,7,9,12,14,9};

    int n = sizeof(arr)/sizeof(arr[0]);

    cout << isSorted(arr,n) << endl;




    return 0;
}