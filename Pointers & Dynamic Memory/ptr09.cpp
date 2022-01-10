#include<iostream>
using namespace std;

// Run Time Memory Allocation or Dynamic Allocation
int main(){

    int n;cin >> n;

    // Creating a variable sized array in heap memory

    int * ptr = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> ptr[i];// cin >> *(ptr+i);
    }
    
    for (int i = 0; i < n; i++)
    {
        cout << ptr[i] << " ";
    }
    cout << endl;

    // Deleting array to avoid memory leak

    delete []ptr;

    return 0;
}