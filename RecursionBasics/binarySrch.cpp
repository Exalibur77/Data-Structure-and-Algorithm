#include<iostream>
using namespace std;

bool binary_srch(int arr[], int s, int e , int key){

    // Base Case
    if(s>e){
        return 0;
    }

    int mid = s+(e-s)/2;

    if(arr[mid] == key){
        return 1;
    }
    
    if(arr[mid] > key){
        return binary_srch(arr,s,mid-1,key);
    }

    //arr[mid] < key
    return binary_srch(arr,mid+1,e, key);
    

}



int main(){

    int arr[]={2,3,5,7,11,23,65,90};

    int n = sizeof(arr)/sizeof(arr[0]);

    int s=0;
    int e=n-1;
    int key; cin >> key;

    cout << binary_srch(arr,s,e,key) << endl;




    return 0;
}