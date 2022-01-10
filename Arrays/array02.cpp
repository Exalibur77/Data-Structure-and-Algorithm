#include<iostream>
using namespace std;

// Here array copy has not made , it passed by reference using the address of the array
void printArray(int arr[],int size){

    int n=sizeof(arr)/sizeof(int);
    
    cout << "In Func " << sizeof(arr) << endl;

    arr[0]=100;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " " << *(arr+i) << " " << i[arr] << endl;
    }
    

}



int main(){

    int arr[]={1,2,4,5,6,7};

    int n=sizeof(arr)/sizeof(int);
    // int n=sizeof(arr)/sizeof(arr[0]);

    printArray(arr,n);
    
    cout << "In main " << sizeof(arr) << endl; 

    return 0;    
}