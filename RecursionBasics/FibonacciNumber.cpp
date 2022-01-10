#include<iostream>
using namespace std;

// Calculate the nth fibonacci number.(0 base indexing )

int fib(int n){

    // base case 1
    if(n==0){
        return 0;
    }

    if(n==1){
        return 1;
    }

    return fib(n-1) + fib(n-2);


}



int main(){

    int n; cin >> n;

    for(int i=0 ; i<10 ; i++){
    cout << fib(i) << endl;
    }


    return 0;
}