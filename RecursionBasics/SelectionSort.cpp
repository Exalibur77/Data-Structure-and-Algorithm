#include<iostream>
using namespace std;

// Selection Sort
void sortArr(int arr[] , int n){

    // base case
    if(n ==0 or n==1) return ;

    // processing
    int min_idx =0;
    for (int i = 0; i < n; i++)
    {   
        if(arr[i] < arr[min_idx]){
            min_idx = i;
        }
    }
    // swapping the first element of the array (at each recursive call) with min value .
    swap(arr[0],arr[min_idx]);

    // recursive call
    sortArr(arr+1,n-1);

}


int main(){

    int arr[]={2,1,4,5,2,7,3,1,0,-1};
    int n = 10;

    // Selection Sort

    // for (int i = 0; i < n; i++)
    // {
    //     int min_idx = i;

    //     for (int j = i+1; j < n; j++)
    //     {
    //         if(arr[j] < arr[min_idx]){
    //             min_idx = j;
    //         }
    //     }
        
    //     swap(arr[i], arr[min_idx]);

    // }
    
    sortArr(arr,n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    

    return 0;
}