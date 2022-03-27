#include<iostream>
#include<stack>
using namespace std;

int main(){

    // Stack creation
    stack <int> st;

    // Push operatiom
    st.push(12);
    st.push(9);
    st.push(1002);
    st.push(1);

    // size operation
    cout << st.size() << endl;

    // removes the first element 
    st.pop();

    // gives or retrieves the top element
    cout << st.top() << endl;

    cout << st.size() << endl;

    // empty check 
    if(st.empty()) cout << "Stack is empty" << endl;

    else cout << "Stack is non-empty" << endl;

}