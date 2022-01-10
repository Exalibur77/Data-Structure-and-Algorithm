#include<iostream>
using namespace std;

void sortArr(int arr[] , int n){
    // Using head recursion
    if(n==0 or n==1) return;

    // recursive call
    sortArr(arr,n-1);

    // processing

    // positiong the last element of the arr
    int last = arr[n-1];
    int j = n-2;

    while (j>=0 and arr[j] > last) // previous element is greater than the last element of the array
    {
        arr[j+1] =arr[j];
        j--; 
    }
    
    arr[j+1] = last;

}


int main(){

    int arr[]={2,1,4,5,2,7,3,1,0,-1};
    int n = 10;

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    sortArr(arr,n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;


    return 0;
}