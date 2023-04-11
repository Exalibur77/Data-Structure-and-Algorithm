#include<iostream>
using namespace std;

// Time complexity == O(n*logn)

void Merge(int arr[] , int s , int e){

    int mid = (s+e)/2;

    int len1 = mid-s+1;
    int len2 = e-mid;

    // Creating two copy of arrays to be merged 

    int * arr1 = new int[len1];
    int * arr2 = new int[len2];

    // Copying elements from original array into these dummy arrays

    int k =s;// index of the main array

    for (int i = 0; i < len1; i++)
    {
        arr1[i]=arr[k];
        k++;
    }
    
    // k = mid +1;

    for (int i = 0; i < len2; i++)
    {
        arr2[i]=arr[k];
        k++;
    }
    
    // Merging Arr 1 and 2 and putting back in main array

    int i=0;int j=0;
    k=s;// index of the main array

    while(i<len1 and j<len2){

        if(arr1[i] > arr2[j]){
            // insert arr2[j] at arr[k]

            arr[k++]= arr2[j++]; 
        }
        else{
            arr[k++]= arr1[i++]; 
        }

    }

    // if one of the index crossed the len (putting back the left element )

    while(i<len1){
        arr[k++]= arr1[i++];
    }

    while(j<len2){
        arr[k++]= arr2[j++];
    }

    // Freeing up the dynamic memory

    delete []arr1;
    delete []arr2;


}



void MergeSort(int arr[], int s , int e){

    // base case
    if(s>=e){
        return ; //(Already sorted or s > e)
    }

    int mid = s + (e-s)/2;

    // Sort the left array (s -> mid)
    MergeSort(arr,s,mid);


    // Sort the right array (mid+1 -> end)
    MergeSort(arr,mid+1,e);


    // Merging the both sorted array
    Merge(arr,s,e);

}


int main(){


    int arr[]={2,4,2,1,6,3,2,7,56,2,23,12};
    int n = sizeof(arr)/sizeof(arr[0]);


    MergeSort(arr,0,n-1);

    for(int &val : arr){
        cout << val << " ";
    }

    return 0;
}