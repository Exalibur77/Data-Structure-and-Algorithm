#include<iostream>
using namespace std;

// Quick Sort using last as an pivot element.

void QuickSort(int arr[] , int s, int e);

void quicksort(int arr[] , int n){

    return QuickSort(arr,0,n-1);

}

int partition(int arr[] , int s , int e){

    int pivot = arr[e];
    int cnt =0; 


    // counting the number of elements smaller or equal than the pivot element

    for(int i=s ; i<=e-1 ; i++){
        if(arr[i] <= pivot){
            cnt++;
        }
    }

    int pivotIndex = s+cnt;

    // Placing the pivot at the correct location
    swap(arr[e],arr[pivotIndex]);

    // now making sure that left part of pivot is smaller or qual to pivot and right side of pivot is greater than pivot

    // does not mean in sorted manner 

    int i=s;
    int j=e;

    while (i<pivotIndex and j>pivotIndex)
    {
        //if elements present are already smaller or equal than pivot then just i++
        while(arr[i] <= pivot)
            i++;

        // if elements are already greater than just j--
        while(arr[j] > pivot){
            j--;
        }    

        // Now after exiting while loop if i is still smaller than pivotIndex and j is greater than pivotIndex then we have to place the value at i and j at the correct position.

        if(i<pivotIndex and j>pivotIndex){
            swap(arr[i++],arr[j--]);
        }


    }
    
    return pivotIndex;


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