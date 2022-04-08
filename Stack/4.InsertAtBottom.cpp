#include<iostream>
#include<stack>
using namespace std;

void solve(stack<int>& stk, int x){
    
    // base case
    if(stk.empty()){
        stk.push(x);
        return;
    }
    
    int ele = stk.top();
    stk.pop();
    
    solve(stk,x);
    
    stk.push(ele);
    
}




stack<int> pushAtBottom(stack<int>& stk, int x) 
{
 	 solve(stk,x);
           
      return stk;
}


int main(){

    stack<int> stk;

    stk.push(1);
    stk.push(1);
    stk.push(1);
    stk.push(1);

    pushAtBottom(stk,12);

    while(!stk.empty()){
        cout << stk.top() << " ";
        stk.pop();
    }
}