#include<iostream>
#include<stack>
using namespace std;

// Delete Middle Element from stack

// SC-O(N/2) Recursive calls
// TC-(N/2)

void solve(stack<int>&stk, int cnt ,int size){
    
    if(cnt == (size/2)){
        stk.pop();
        return;
    }
    
    int ele = stk.top();
    stk.pop();
    
    solve(stk,cnt+1,size);
    stk.push(ele);
    
}



void deleteMiddle(stack<int>&inputStack, int N){
	
   	int cnt =0;
   	solve(inputStack,cnt,N);
   
}

int main(){

    stack <int> stk;
    stk.push(12);
    stk.push(23);
    stk.push(65);
    stk.push(100);
    // stk.push(1);


    deleteMiddle(stk,4);

    while(!stk.empty()){
        cout << stk.top() << endl;
        stk.pop();
    }


    return 0;
}