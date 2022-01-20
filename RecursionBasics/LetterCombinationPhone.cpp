#include<iostream>
#include<vector>
#include<string>
using namespace std;

// Using recursion and backtracking
void solve(string digits , string &output , int index ,vector <string> &m,vector <string>&ans){
        
        // base case
        if(index >= digits.size()){
            ans.push_back(output);
            return;
        }
        
        // processing
        
        string str = m[digits[index]-'0'];
        
        for(int i=0 ; i<str.size() ; i++){
            
            output.push_back(str[i]);
            solve(digits,output,index+1,m,ans);
            output.pop_back();
            
        }
        
}


vector<string> letterCombinations(string digits) {
        
        vector <string> ans;
        if(digits.size() ==0 ) return ans;
        string output="";
        int index =0;
        vector <string> m= {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        
        solve(digits,output,index,m,ans);
        
        return ans;


}

int main(){

    vector <string> ans = letterCombinations("23");

    for(auto &str : ans){
        for(auto &ch : str){
            cout << ch ;
        }
        cout << endl;
    }



    return 0;
}