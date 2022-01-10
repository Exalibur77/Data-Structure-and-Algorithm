#include<iostream>
using namespace std;


int fact(int n){

    if(n==0){
        return 1;
    }

    int smallProblem = fact(n-1);
    int bigProblem = n*smallProblem;

    return bigProblem;
}

int main(){

    int n; cin >> n;
    cout << fact(n) << endl;


    return 0;
}