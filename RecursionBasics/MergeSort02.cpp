#include<iostream>
#include<algorithm>
using namespace std;

// Merge Sort without using an extra Space.

void Merge(int arr[] , int s , int e , int maxele){

    int mid = (s+e)/2;

    int i=s;
    int j=mid+1;

    int k=s;// index of the main array

    while(i<=mid and j<=e){

            if (arr[i] % maxele <= arr[j] % maxele) {
                arr[k] = arr[k] + (arr[i] % maxele) * maxele;
                k++;
                i++;
            }
            else {
                arr[k] = arr[k] + (arr[j] % maxele) * maxele;
                k++;
                j++;
            }

    }
    
    while (i <= mid) {
        arr[k] = arr[k] + (arr[i] % maxele) * maxele;
        k++;
        i++;
    }

    while (j <= e) {
        arr[k] = arr[k] + (arr[j] % maxele) * maxele;
        k++;
        j++;
    }

    for (int i =s; i <= e; i++)
    {
        arr[i] = arr[i]/maxele;
    }
    


}

void MergeSortRec(int arr[], int s , int e , int maxele){

    // base case
    if(s>=e){
        return ; //(Already sorted or s > e)
    }

    int mid = s + (e-s)/2;

    // Sort the left array (s -> mid)
    MergeSortRec(arr,s,mid,maxele);


    // Sort the right array (mid+1 -> end)
    MergeSortRec(arr,mid+1,e, maxele);


    // Merging the both sorted array
    Merge(arr,s,e ,maxele);

}

void MergeSort(int arr[] , int n){
    int maxele = *max_element(arr,arr+n)+1;

    MergeSortRec(arr,0,n-1,maxele);
}

int main(){


    int arr[]={2,4,9,1,10};
    int n = sizeof(arr)/sizeof(arr[0]);


    MergeSort(arr,n);

    for(int &val : arr){
        cout << val << " ";
    }

    return 0;
}