#include<iostream>
using namespace std;

void printSubarray(int arr[], int n){

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            for (int k = i; k <= j; k++)
            {
                cout << arr[k] << " " ;
            }
            cout << endl;
        }
        // cout << endl;
    }
    
    return;
}


int main(){

    int arr[]={12,23,43,11,76,9};

    int n=sizeof(arr)/sizeof(int);

    printSubarray(arr,n);



    return 0;
}