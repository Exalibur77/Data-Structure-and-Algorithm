#include<iostream>
#include<vector>
using namespace std;

// Avoiding duplicates permuation
// Permutation of the given array or can be applied over strings

void solve(vector<int> nums , vector<vector<int>>& ans , int index){
        
        // base case
        
        if(index >= nums.size()){
            bool flag=1;

            for(auto &v : ans){
                if(v == nums){
                    flag=0; // same array mil gya 
                    break;
                }
            }

            if(flag){
                ans.push_back(nums);
            }
            
            return;
        }
        
        // traversing index till the end so that each element get a chance to be swapped with starting value
        
        for(int j=index ; j<nums.size() ;j++){
            // swapping the j th element with index element 
            swap(nums[j],nums[index]);
            
            solve(nums,ans,index+1);
            
            // backtrack == so that we reach our original state before performing swap again
            
            swap(nums[j],nums[index]);
            
        }
        
}


vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int index = 0;
        
        solve(nums,ans,index);
        return ans;
}

int main(){

    vector <int> arr={1,2,1};

    vector<vector<int>> ans = permute(arr);

    for(auto &v : ans){
        for(auto &val : v){
            cout << val << " ";
        }
        cout << endl;
    }


    return 0;
}