#include<iostream>
#include<stack>
using namespace std;

// https://www.codingninjas.com/codestudio/problems/redundant-brackets_975473?leftPanelTab=1
// Finding whether there is some redundance of brackets in the given expression 

bool findRedundantBrackets(string &s)
{
    stack<char> stk;
    
    for(auto &ch : s){
        
        if( ch == '(' || ch =='+' || ch == '-' || ch=='*' || ch == '/' ) 
        {
 			stk.push(ch);  
        }
           
        // closing bracket or alphabets(ignored)
        else{
           	
           if( ch == ')' ){
                bool isRedundent = true; 
                while(stk.top()!= '('){
					char temp = stk.top();
    			      if(temp =='+' ||  temp == '-' ||  temp=='*' ||  temp =='/' ){
                            isRedundent = false;  
                          	stk.pop();
                       }
					                   
                }         
       
            	if(isRedundent == true){
                    return 1;
                }
                stk.pop();
           }                       
           
            
           	
            
        }
        
        
        
    
    
    
    }
    return 0;
}

int main(){

    string s1= "(a+b*(c+d))";
    string s2= "(a+(b)*(c+d))";

    if(findRedundantBrackets(s1) == 1){
        cout << "Redundent" << endl;
    }

    else{
        cout << "Non Redundent" << endl;
    }

    if(findRedundantBrackets(s2) == 1){
        cout << "Redundent" << endl;
    }

    else{
        cout << "Non Redundent" << endl;
    }

}