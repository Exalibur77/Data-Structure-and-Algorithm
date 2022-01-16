#include<iostream>
#include<vector>
using namespace std;

// Time complexity == O(n*logn)

void Merge(int arr[] , int s , int e){

    int i = s;
    int mid = (s+e)/2;
    int j = mid+1;
    
    vector <int> temp;

    while(i<=mid and j<=e){

        if(arr[i] > arr[j]){
            // insert arr2[j] at temp
            temp.push_back(arr[j++]);
        }
        else{
            temp.push_back(arr[i++]);
        }

    }

    // if one of the index crossed its length
    while(i<=mid){
        temp.push_back(arr[i++]);
    }

    while(j<=e){
        temp.push_back(arr[j++]);
    }

    // copying elements of temp in the original arr
    int k=0;
    for(int i=s ; i<=e ; i++){
        arr[i]=temp[k++];
    }

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