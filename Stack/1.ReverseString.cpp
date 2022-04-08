#include<iostream>
#include<stack>
using namespace std;

    // reverse a string using stack

int main(){

    string str;
    cout << "Enter string :";
    cin >> str;

    // Extra Space complexity O(N)
    stack <char> stk;

    for(auto ch:str){
        stk.push(ch);
    }

    while(!stk.empty()){
        cout << stk.top();
        stk.pop();

    }


    return 0;
}