#include<iostream>
#include<string>
#include<vector>
using namespace std;

vector<vector<string>> phoneDirectory(vector<string>&contactList, string &queryStr)
{
    
    vector<vector<string>> ans;

    int n = queryStr.size();

    string prefix;

    for(int i=0 ; i<n ; i++){

        vector <string> temp;

        prefix.push_back(queryStr[i]);

        for(auto & str : contactList){
            
            if(str.find(prefix) == 0){
                temp.push_back(str);
            }
            
        }

        if(temp.size() == 0) ans.push_back({"0"});

        ans.push_back(temp);
        
    }

    return ans;
    
}

int main(){


    int n;
    cin >> n;

    vector <string> arr;

    for(int i=0 ; i<n ; i++){
        string str;
        cin >> str;

        arr.push_back(str);
    }

    string query;
    cin >> query;

    vector<vector<string>> ans = phoneDirectory(arr,query);

    for(auto &v : ans){

        for(auto & str : v){

            cout << str << " ";

        }

        cout << endl;
    }

    return 0;

}