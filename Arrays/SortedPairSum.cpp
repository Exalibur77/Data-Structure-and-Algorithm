#include<iostream>
#include<vector>
using namespace std;

pair<int, int> closestSum(vector<int> arr, int x){
    
    int n=arr.size();
    int ans_l,ans_r;
    int l=0,r=n-1,diff=INT_MAX;

    if(abs(arr[l]+arr[r]-x)<diff){
        ans_l=l;
        ans_r=r;
        diff=abs(arr[l]+arr[r]-x);
    }

    if(arr[l]+arr[r] > x){
        r--;
    }

    else{
        l++;
    }

    return {arr[ans_l],arr[ans_r]};
}

int main(){

    



}