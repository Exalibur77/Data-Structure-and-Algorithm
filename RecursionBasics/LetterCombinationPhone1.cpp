#include<iostream>
#include<vector>
#include<string>
using namespace std;


vector<string> letterCombinations(string digits) {
        vector<string> ans;
        int n = digits.size();
        if(n==0){
            return ans;
        }
        ans.push_back("");
        
        vector <string> m= {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        
        // Iterative Approach
        
        for(int i=0 ; i<n ; i++){
            
            string str = m[digits[i]-'0'];
            vector <string> temp;
            
            // making combination of my str[i] =2 with result formed till then
            for(int j=0 ; j<str.size() ; j++){
                
                for(int k=0 ; k<ans.size() ; k++){
                    
                    temp.push_back(ans[k]+str[j]);
                }
                
            }
            
            swap(ans,temp);
            
            
        }
        
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