#include<iostream>
#include<string>
using namespace std;

// void revStr(string &str , int s, int e){

//     // base case
//     if(s >= e){
//         return ;
//     }
//     // Processing
//     swap(str[s],str[e]);

//     // recursive call
//     revStr(str,s+1,e-1);

// }

// bool checkSame(string &temp , string &str){

//     return temp == str;

// }


bool checkPalindrome(string &str , int s , int e){

    // base case
    if(s >= e){
        return 1;
    }

    // processing
    if(str[s] != str[e]){
        return false;
    }

    // recursive call
    return checkPalindrome(str,s+1,e-1);

}

bool checkPalindrome1(string &str , int s ){

    int e = str.length()-s-1;
    // base case
    if(s >= e){
        return 1;
    }

    // processing
    if(str[s] != str[e]){
        return false;
    }

    // recursive call
    return checkPalindrome1(str,s+1);

}




int main(){

    string str;
    cin >> str;

    // string temp = str; 

    // int n = str.length();

    // revStr(str,0,n-1);

    // cout << checkSame(temp,str) << endl;

    cout << checkPalindrome(str , 0 , str.size()-1) << endl;
    cout << checkPalindrome1(str , 0) << endl;


    return 0;
}