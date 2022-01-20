#include<bits/stdc++.h>
using namespace std;


bool can_place(vector<string> arr,int i,int j) {
    //when we are on blocked cell
    string str=arr[i];
    if(str[j]=='X') {
        return false;
    } 
    
    return true;
}
 
void print(int v[][50],int n,int m) {
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
    return ;
}
 
bool rat_mice(int v[][50],vector<string> &arr,int n,int m,int i,int j) {
    //base case
    if(i==n) {
        //print(v,n,m);
        return true;
    }
 
    //when j==m
    if(j==m) {
        return (rat_mice(v,arr,n,m,i+1,0));
    }
 
    //rec case
    if(can_place(arr,i,j)) {
        v[i][j]=1;
        //right
        if(rat_mice(v,arr,n,m,i,j+1)) {
            return true;
        }
        
        //down
        if(rat_mice(v,arr,n,m,i+1,j)) {
            return true;
        }
        //backtrack
        v[i][j]=0;
    }
    
    return false;
}
 
vector<vector<int>> ratAndMice(vector<string> arr) {
    int n=arr.size();
    string str=arr[0];
    int m=str.length();


    int v[50][50]={0};

    vector<vector<int>> vec;
    if(!rat_mice(v,arr,n,m,0,0)) {
        cout<<"NOT POSSIBLE"<<endl;
    }

    for(int i=0; i<n; i++) {
        vector<int> just;
        for(int j=0; j<m; j++) {
            just.push_back(v[i][j]);
        }
        vec.push_back(just);
    }
    return vec;

}

int main(){

    vector<string> arr {
        {"OXOO"},{"OOOO"},{"XOXO"},{"XOXO"},{"XOXO"}
    };

    vector<vector<int>> ans = ratAndMice(arr);

    for(auto &v : ans){
        for(auto &ele : v){
            cout << ele << " ";
        }
        cout << endl;
    }


}