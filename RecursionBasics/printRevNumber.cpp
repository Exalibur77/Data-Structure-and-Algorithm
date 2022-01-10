#include<iostream>
using namespace std;

string arr[10]={"zero" ,"one","two" , "three" , "four" , "five" , "six" ,"seven" ,"eight" , "nine"};

void sayDigit(int n){

    if(n==0){
        return;
    }

    sayDigit(n/10);

    cout << arr[n%10] << endl;
}



int main(){

    int n;

    cin >> n;

    sayDigit(n);


    return 0;
}