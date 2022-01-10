#include<iostream>
using namespace std;

// Bubble Sort using Recursion
void sortArr(int arr[], int n){

    // Base case
    if(n==1 or n==0) return ;

    // processing 

    for (int i = 0; i < n-1; i++)
    {
        if(arr[i] > arr[i+1]){
            swap(arr[i],arr[i+1]);
        }
    }

    // recursive call
    sortArr(arr,n-1);
    

}

int main(){

    int arr[]={2,1,5,2,7,54,90,14};

    int n = sizeof(arr)/sizeof(arr[0]);


    sortArr(arr,n);

    for(int val: arr){
        cout << val << " ";
    }


    return 0;
}