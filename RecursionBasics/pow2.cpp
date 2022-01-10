#include<iostream>
using namespace std;


int pow2(int n){

    if(n==0) return 1;

    int smallProblem = pow2(n-1);

    int bigProblem = 2*smallProblem;

    return bigProblem;

}

int main(){

    int n; cin >> n;
    cout << pow2(n) << endl;


    return 0;
}