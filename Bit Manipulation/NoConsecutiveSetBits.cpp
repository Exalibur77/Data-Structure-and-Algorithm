#include <bits/stdc++.h>
using namespace std;

string convert_binary(int i, int n){
    
    string temp="";
    while(i!=0){
        
        int rem = i%2;
        temp += (rem + '0');
        i=i/2;
    }
    
    if(temp.size() < n){
        temp.append(n-temp.size(),'0');
    }
    reverse(temp.begin(),temp.end());
    // cout << temp << endl;
    return temp;
}

bool isValid(string str){
    
    for(int i=0 ; i<str.size()-1 ; i++){
        
        if(str[i] == '1' and str[i] == str[i+1]){
            return false;
        }
    }
    return 1;
}

// Time complexity O(n*2^n)
vector<string> binaryStrings(int n){
    // do not modify any default function or parameter you can use helper function if needed
    
    vector<string> ans;
    // Brute Force
    
    int N = pow(2,n);
    
    for(int i=0 ; i<N ; i++){
        

        string str =convert_binary(i,n);

        if(isValid(str)){
            ans.push_back(str);
        }
        
    }
   return ans;
    
}

int main(){

    int n; cin >> n;
    vector <string> res = binaryStrings(n);

    for(auto &str : res){
        cout << str << endl;
    }

}