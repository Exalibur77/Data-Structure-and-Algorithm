#include<iostream>
#include<vector>
#include<stack>
using namespace std;

// Finds the previous smaller number for each current number (i.e on left side)

// Brute Force Approach --- O(N^2)
void solve(int arr[], int size){

    for(int i=0 ; i <size ; i++){

        bool flag = 0;
        for(int j=i-1;  j>=0 ; j--){

            // arr[j] chota hai ie previous smaller element
            if(arr[i] > arr[j]){
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

vector <int> previousSmaller(int arr[] , int n){

    vector <int> ans(n);

    stack <int> stk;
    // Maintaing a stack in descending order and top() element would be the answer if the curr is greater than top

    stk.push(-1);

    for(int i=0 ; i<n ; i++){

        int curr = arr[i];

        while(stk.top() >= curr){
            stk.pop();
        }

        // as soon as smaller element appeared than curr

        ans[i] = stk.top();

        stk.push(curr);

    }

    return ans;
}





int main(){

    int arr[]={23,1,43,5,4,2,45};
    int n = sizeof(arr)/sizeof(arr[0]);

    solve(arr,n);

    vector <int> ans = previousSmaller(arr,n);

    for(auto &val : ans){
        cout << val << " ";
    }
    cout << endl;

    return 0;
}