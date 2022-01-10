#include<iostream>
using namespace std;

// Search Space should be monotonic ie should be sorted and work for ascending numbers and also work for descending with some edit.

int binary_search(int arr[],int n,int key){

    int s=0;
    int e=n-1;
    int mid;
    // As soon as s crosses e .. loop should terminate 

    while (s<=e)
    {
        mid=(s+e)/2;
        if(arr[mid]==key){
            return mid;
        }

        else if (arr[mid]>key)
        {
            e=mid-1;
        }
        
        else{
            s=mid+1;
        }
    }
    
    return -1;


}

int main(){

    int arr[]={12,23,43,54,76,98,102};
    int n=sizeof(arr)/sizeof(arr[0]);
    int key;
    cin >> key;

    int index=binary_search(arr,n,key);

    if(index!=-1){
        cout << key << " is present at the index " << index << endl;
    }
    else{
        cout << key << " is not present in the array" << endl;
    }

    return 0;
}