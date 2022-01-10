#include<iostream>
using namespace std;

int main(){

    // Null Pointer , pointer which is pointing to nothing 
    int * ptr = NULL;

    // Void pointer
    void * pointer;

    int x=5;
    pointer=&x; // valid operation

    float y=0.99; // valid operation
    pointer=&y;

    return 0;
}