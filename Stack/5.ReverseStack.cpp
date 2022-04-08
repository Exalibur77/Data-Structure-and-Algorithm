#include<iostream>
#include<stack>
using namespace std;

// Time Complexity - O(N^2) and Space Complexity - O(n^2) due to eacj recursive call of reverse causes insert call which is also uses N space .

void insertAtBottom(stack<int> &stk, int x){

    // Base case
    if(stk.empty()){
        stk.push(x);
        return;
    }

    int val = stk.top();
    stk.pop();

    insertAtBottom(stk,x);

    stk.push(val);



}



void reverseStack(stack<int> &stk){

    // Base case
    if(stk.empty()){
        return;
    }

    int ele =stk.top();
    stk.pop();

    reverseStack(stk);

    insertAtBottom(stk,ele);

}



int main(){

    stack<int> stk;

    stk.push(1);
    stk.push(1);
    stk.push(1);
    stk.push(1);
    stk.push(12);

    reverseStack(stk);

    while(!stk.empty()){

        cout << stk.top() << " ";
        stk.pop();

    }



    return 0;
}