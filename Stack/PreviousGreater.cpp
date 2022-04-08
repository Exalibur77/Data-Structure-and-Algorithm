#include<iostream>
#include<vector>
#include<stack>
using namespace std;

// Finds the previous greater number for each current number (i.e on left side)

// Brute Force Approach --- O(N^2)
void solve(int arr[], int size){

    for(int i=0 ; i <size ; i++){

        bool flag = 0;
        for(int j=i-1;  j>=0 ; j--){

            // arr[j] bda hai ie previous greater element
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

vector <int> previousGreater(int arr[] , int n){

    vector <int> ans(n);

    stack <int> stk;
    // Maintaing a stack in ascending order and top() element would be the answer if the curr is smaller than top

    for(int i=0 ; i<n ; i++){

        int curr = arr[i];

    // pop all the smaller element than curr
        while(!stk.empty() and stk.top() <= curr){
            stk.pop();
        }

    // no greater element found
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

    vector <int> ans = previousGreater(arr,n);

    for(auto &val : ans){
        cout << val << " ";
    }
    cout << endl;

    return 0;
}