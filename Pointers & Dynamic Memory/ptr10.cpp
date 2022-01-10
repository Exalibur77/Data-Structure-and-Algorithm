#include<iostream>
using namespace std;

// Run Time Memory Allocation or Dynamic Allocation
int main(){

    int * ptr = new int;// Creating a single memory in heap

    *ptr=123;

    cout << *ptr << endl;

    // Deleting memory in heap to avoid memory leak
    // but variable is not deleted .. it can be reassigned

    delete ptr;

    ptr=new int;

    *ptr=01;

    cout << *ptr << endl;

    delete ptr;

    return 0;
}