#include<bits/stdc++.h>
using namespace std;

int EvaluatePostfix(string str){

    stack <int> stk;

    while(!stk.empty()) stk.pop();

    for(auto &ch : str){

        if(ch>='0' and ch<='9') stk.push(ch-'0');

        else{

            int b = stk.top();
            stk.pop();

            int a = stk.top();
            stk.pop();

            if(ch == '+') stk.push(a+b);

            else if(ch == '-') stk.push(a-b);

            else if(ch == '*') stk.push(a*b);

            else if(ch == '/') stk.push(a/b);

        }

        cout << ch  << " ";
        cout << stk.top() << endl;

    }

    return stk.top();


}

int main(){

    string str;
    cin >> str;
    cout << EvaluatePostfix(str);


    return 0;
}