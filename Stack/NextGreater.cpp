#include<iostream>
#include<vector>
#include<stack>
using namespace std;

// Finds the next greater number for each current number (i.e on right side)

// Brute Force Approach --- O(N^2)
void solve(int arr[], int size){

    for(int i=0 ; i <size ; i++){

        bool flag = 0;
        for(int j=i+1 ; j<size ; j++){

            // arr[j] bda hai ie next greater element
            if(arr[i] < arr[j]){
                flag =1 ;
                cout << arr[j] << " ";
                break;
            }


        }
        // ie nhi mila
        if(flag == 0) cout << -1 << " ";
    }

    cout << endl;
}


// Stack Use 
// TC- O(N) and Space Complexity - O(N)

vector <int> nextGreater(int arr[] , int n){

    vector <int> ans(n);

    stack <int> stk;
    // Maintaing a stack in ascending order and top() element would be the answer if the curr is smaller than top

 

    for(int i=n-1 ; i>=0 ; i--){

        int curr = arr[i];

    // remove element smaller than current and find for larger element 
        while(!stk.empty() and stk.top() <= curr){
            stk.pop();
        }


        if(stk.empty()){
            ans[i] = -1;
        }

        // as soon as greater element appeared than curr

        else{
            ans[i] = stk.top();
        }
        

        stk.push(curr);

    }

    return ans;
}





int main(){

    int arr[]={23,1,43,5,4,2,45};
    int n = sizeof(arr)/sizeof(arr[0]);

    solve(arr,n);

    vector <int> ans = nextGreater(arr,n);

    for(auto &val : ans){
        cout << val << " ";
    }


    return 0;
}