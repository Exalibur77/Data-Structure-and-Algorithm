#include<iostream>
#include<string>
using namespace std;

// Run Length Encoding Problem

/*

Input == aaabbcdd
Output == a3b2cd2

Input == abcd
Output == abcd

*/

string compress(string str){

    int n=str.size();

    string ans;
    // Time Complexity O(n)
    for (int i = 0; i < n; i++)
    {
        int count=1;

        while(i<n-1 and str[i+1]==str[i]){
            count+=1;
            i++;
        }
        ans+=str[i];
        ans+=to_string(count);
    }
    
    if(ans.size()>n){
        return str;
    }
    return ans;
    
    


}


int main(){

    string input="aaabbccss";
    cout << compress(input) << endl;

    string input1="abcd";
    cout << compress(input1) << endl;


}