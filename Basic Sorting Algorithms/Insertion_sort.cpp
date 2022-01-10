#include<iostream>
using namespace std;

// Time Complexity O(n^2)
void insertion_sort(int arr[], int n){

    for (int i = 1; i < n; i++)
    {
        int curr=arr[i];
        int prev=i-1;
         // loop is to find the current index at which the current element should be inserted .
        while (prev>=0 && arr[prev]>curr)
        {
            arr[prev+1]=arr[prev];
            prev--;
        }
        arr[prev+1]=curr;

    }
    return;

}

int main(){

    int arr[]={12,4,76,-98,-23,27,1,001,23};
    int n=sizeof(arr)/sizeof(int);

    insertion_sort(arr,n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}