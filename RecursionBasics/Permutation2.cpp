#include<iostream>
#include<vector>
#include<set>
using namespace std;

// Avoiding duplicates permuation using set 
// Permutation of the given array or can be applied over strings

void solve(vector<int> nums , set<vector<int>>& temp , int index){
        
        // base case
        
        if(index >= nums.size()){
            
            temp.insert(nums);
            
            return;
        }
        
        // traversing index till the end so that each element get a chance to be swapped with starting value
        
        for(int j=index ; j<nums.size() ;j++){
            // swapping the j th element with index element 
            swap(nums[j],nums[index]);
            
            solve(nums,temp,index+1);
            
            // backtrack == so that we reach our original state before performing swap again
            
            swap(nums[j],nums[index]);
            
        }
        
}


vector<vector<int>> permute(vector<int>& nums) {
        set <vector<int>> temp;
        int index = 0;
        vector<vector<int>> ans;

        solve(nums,temp,index);

        // copying value of temp to ans

        for(auto &v : temp){
            ans.push_back(v);
        }

        return ans;
}

int main(){

    vector <int> arr={1,1,1};

    vector<vector<int>> ans = permute(arr);

    for(auto &v : ans){
        for(auto &val : v){
            cout << val << " ";
        }
        cout << endl;
    }


    return 0;
}