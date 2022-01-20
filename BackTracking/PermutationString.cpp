#include<iostream>
#include<string>
using namespace std;

void printPermutation(string &str , int index){

    // base case
    if(str.length() <= index){
        cout << str << endl;
        return;
    }

    // recursive case

    for(int j=index ; j<str.length() ; j++){

        swap(str[j],str[index]);

        printPermutation(str,index+1);

        swap(str[j],str[index]); // backTrack Step is important as str is passed by reference 
        // It becomes optional if str is passed by value as each stack call has its own string str.
    }

}


int main(){

    string str = "abc";
    int n = str.length();

    string output="";
    printPermutation(str,0);

}