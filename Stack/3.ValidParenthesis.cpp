#include<iostream>
#include<stack>
using namespace std;

// Balanced Parenthesis or not 

// TC - O(N) and SC - O(N)

bool isValidParenthesis(string str)
{    
    stack <char> stk;
 	
    for(auto &ch: str){
        
        // Opening bracket
        if(ch == '(' or ch == '[' or ch == '{'){
            stk.push(ch);
        }
        
        // closing bracket
        else{
           
            if(stk.size() != 0){
                
                char c = stk.top();
                
                if((ch == ')' and c == '(') or 
                (ch == ']' and c == '[') or 
                (ch == '}' and c == '{')){
                    stk.pop();
                }
                
                else{
                    return 0;
                }
                
            }
            
            // empty and close bracket
            else return 0;
            
        }
        
    }
    
    if(stk.size() == 0) return 1;
    
    else return 0;
    
    
    
}

int main(){

    string str;
    cin >> str;

    if(isValidParenthesis(str)){
        cout << "valid" << endl;
    }

    else{
        cout << "Invalid" << endl;
    }


}