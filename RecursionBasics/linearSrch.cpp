#include<iostream>
using namespace std;

bool srch(int arr[], int n , int key){

    // Base Case
    if(n==0){
        return 0;
    }

    if(arr[0] == key){
        return true;
    }

    return srch(arr+1,n-1,key);

}



int main(){

    int arr[]={2,4,10,1,5,3};

    int n = sizeof(arr)/sizeof(arr[0]);
    int key; cin >> key;

    cout << srch(arr,n ,key) << endl;




    return 0;
}