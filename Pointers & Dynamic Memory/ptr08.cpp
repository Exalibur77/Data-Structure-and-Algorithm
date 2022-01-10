#include<iostream>
using namespace std;

int main(){
    // Array and Pointers 
    int arr[]={1,2,3,45,6};

    cout << *arr << endl;
    int *ptr=arr;
    cout << ptr << endl;
    
    for (int i = 0; i < 5; i++)
    {
        cout << *(arr+i) << " " << arr[i] << " " << i[arr] << endl;// Shifts of arr+1 means shift of 4 bytes as it is an integer array
        cout << *ptr << endl;
        ptr++;
    }

    cout << ptr << endl;
    cout << *ptr << endl;

    return 0;
}