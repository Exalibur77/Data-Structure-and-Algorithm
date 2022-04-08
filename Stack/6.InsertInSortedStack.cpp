#include<iostream>
#include<stack>
using namespace std;

    // Insert the new element such that stack(already sorted in descending order) remains sorted in descending order.

void insertInSorted(stack<int>&stk,int x){

    // base case
    if(stk.empty() or stk.top() <= x){
        stk.push(x);
        return;
    } 

    int ele = stk.top();
    stk.pop();

    insertInSorted(stk,x);

    // vapas jaate hue add kar dena 
    stk.push(ele);

}

int main(){

    int x;
    cin >> x;

    stack<int> stk;

    stk.push(2);
    stk.push(10);
    stk.push(34);
    stk.push(92);

    insertInSorted(stk,x);

    while(!stk.empty()){
        cout << stk.top() << " ";
        stk.pop();
    }

    return 0;
}