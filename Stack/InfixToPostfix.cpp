#include<bits/stdc++.h>
using namespace std;

int prec(char ch){

    if(ch == '^') return 3;

    else if(ch == '/' or ch == '*') return 2;

    else if(ch == '+' or ch == '-') return 1;

    else return -1;
}

string InfixToPostfix(string str){

    stack <int> stk;

    string ans;

    for(int i=0 ; i<str.size() ; i++){

        char ch = str[i];

        if((ch >= 'a' && ch<='z') or(ch >='A' && ch<='Z')){
            ans.push_back(ch);
        }

        else if(ch == '('){
            stk.push(ch);
        }

        // closing bracket
        else if(ch == ')'){
            
            while(!stk.empty() and stk.top() != '('){
                ans.push_back(stk.top());
                stk.pop();
            }

            // pop the '(' empty bracket also

            if(!stk.empty()) stk.pop();

        }

        // operator
        else{

            // equal precedence wale is also popped since they are already in stack which means they are present prviously then curr towards left
            while(!stk.empty() and prec(stk.top()) >= prec(ch)){
                ans.push_back(stk.top());
                stk.pop();
            }
            stk.push(ch);


        }

    }

    while(!stk.empty()){
        ans.push_back(stk.top());
        stk.pop();
    }


    return ans;
}


int main(){

    string input;

    cin >> input ;

    cout << InfixToPostfix(input) << endl;

    return 0;
}