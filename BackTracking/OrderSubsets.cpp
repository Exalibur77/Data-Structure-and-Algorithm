#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

bool cmp(string a , string b){

    if(a.length() == b.length()){
        return a<b; // lexographical order
    }

    return a.length() < b.length();
}


// finding subsets using output array which is same for each recursive call hence we require a backtrack step to reach to the original state.

// int i for filling output array
void findSubsets(char input[] , char output[] , int index , int n , int i , vector<string> &ans){

    if(index == n){
        output[i] = '\0';
        
        string temp(output);

        ans.push_back(temp);
        
        return;
    }

    // recursive step

    // not include
    findSubsets(input,output,index+1,n,i,ans);

    // included
    output[i]=input[index];
    findSubsets(input,output,index+1,n,i+1,ans);

    // Here backtracking step would not affect anything as we are adding data in output array everystep it geting override by the new ans.

    // adding a null character at the i th index of output.

    output[i]='\0';// optional in this question


}


int main(){

    char input[100];
    char output[100];

    cin >> input;

    int n =strlen(input);

    vector <string> ans;
    findSubsets(input,output,0,n,0,ans);

    sort(ans.begin(),ans.end(),cmp);

    for(auto str: ans){
        cout << str << endl;
    }


    return 0;
}