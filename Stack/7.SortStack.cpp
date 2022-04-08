#include<iostream>
#include<stack>
using namespace std;

    // Sort the stack recursively

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


void sortStack(stack<int> &stk)
{
	if(stk.empty()){
		return;  
    }
    
    int ele = stk.top(); 
    stk.pop();
    
    sortStack(stk);
    
    insertInSorted(stk,ele);
    
}

int main(){

    stack<int> stk;

    stk.push(20);
    stk.push(1);
    stk.push(3);
    stk.push(920);
    stk.push(-1);

    sortStack(stk);

    while(!stk.empty()){
        cout << stk.top() << " ";
        stk.pop();
    }





    return 0;
}