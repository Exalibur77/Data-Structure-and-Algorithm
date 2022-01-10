#include<iostream>
using namespace std;

void printCounting(int n){

    if(n == 0){
        return;
    }

    cout << n << " ";
    printCounting(n-1);
    
    // cout << "Hello" << n <<endl;
}

int main(){

    int n; cin >> n;
    printCounting(n);
    // cout << endl;

    return 0;
}