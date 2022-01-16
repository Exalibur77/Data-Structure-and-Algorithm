#include<iostream>
using namespace std;

// Quick Sort using last as an pivot element.

void QuickSort(int arr[] , int s, int e);

void quicksort(int arr[] , int n){

    return QuickSort(arr,0,n-1);

}
// Using end element as a pivot element

int partition(int arr[] , int s , int e){

    int pivot = arr[e];

    int i = s-1;

    // maintaining a index i 1 before where all smaller elements are being placed in the array 

    for(int j=s ; j<e ; j++){
        if(arr[j] <= pivot){
            i++;
            swap(arr[j],arr[i]);
        }
    }
    // placing pivot at correct index
    swap(arr[i+1],arr[e]);


    return i+1;


}



void QuickSort(int arr[] , int s, int e){

    // Base case
    if(s>=e){
        return ;
    }

    // processing 
    int p = partition(arr,s,e);


    // recursive call
    QuickSort(arr,s,p-1);
    QuickSort(arr,p+1,e);


}




int main(){


    int arr[]={2,5,1,29,10,1,10,-1,2,-1,100};
    int n = sizeof(arr)/sizeof(arr[0]);

    quicksort(arr,n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;


    return 0;
}