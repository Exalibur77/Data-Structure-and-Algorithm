#include<iostream>
#include"stack.h"
using namespace std;

int main(){

    stack<int> st(10);

    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);

    cout << st.peek() << endl;

    cout << st.empty() << endl;

    st.pop();
    st.pop();
    st.pop();
    st.pop();
    st.pop();


    stack <char> stk(10);
    stk.push(92);
    stk.push(109);
    stk.push(64);
    stk.push(97);

    cout << stk.peek() << endl;
    stk.pop();
    cout << stk.peek() << endl;
    stk.pop();
    cout << stk.peek() << endl;
    stk.pop();
    cout << stk.peek() << endl;
    stk.pop();


    stack <string> s(1);
    s.pop();

    return 0;
}