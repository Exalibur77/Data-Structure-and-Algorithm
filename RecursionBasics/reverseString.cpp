#include<iostream>
#include<string>
using namespace std;

void revStr(string &str , int s, int e){

    // base case
    if(s >= e){
        return ;
    }
    // Processing
    swap(str[s],str[e]);

    // recursive call
    revStr(str,s+1,e-1);

}

void revStr1(string &str ,int s){

    int e = str.size()-s-1;

    // base case
    if(s >= e){
        return ;
    }
    // Processing
    swap(str[s],str[e]);

    // recursive call
    revStr1(str,s+1);

}



int main(){

    string str = "qwerty";

    int n = str.length();

    revStr(str,0,n-1);
    revStr1(str,0);

    cout << str << endl;

    return 0;
}