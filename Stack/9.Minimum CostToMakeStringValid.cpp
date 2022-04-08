#include<iostream>
#include<string>
#include<stack>
using namespace std;


https://www.codingninjas.com/codestudio/problems/minimum-cost-to-make-string-valid_1115770?leftPanelTab=0



int findMinimumCost(string str) {
  // Write your code here
    
    int n = str.size();
    if(n%2 == 1) return -1;
    
    stack <char> stk;

    for(auto &ch : str){
        
        if(ch == '{'){
            stk.push(ch);
        }
       
        // close bracket
        else{
       		
            if(!stk.empty() and stk.top() == '{'){
                stk.pop();
            }
            
            else{
                stk.push(ch);
            }
            
            
            
        }
        
    }
    
    int a = 0, b= 0;
    
    while(!stk.empty()){
        
        if(stk.top() == '{') a++;
        else b++;
        
        stk.pop();
        
    }
    
    int ans = (a+1)/2 + (b+1)/2;
    
    return ans;
}

int main(){

    string str;

    cin >> str;


    cout << findMinimumCost(str);




}