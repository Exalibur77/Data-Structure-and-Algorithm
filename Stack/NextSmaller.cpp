#include<iostream>
#include<vector>
#include<stack>
using namespace std;

// Finds the next smaller number for each current number (i.e on right side)

// Brute Force Approach --- O(N^2)
void solve(int arr[], int size){

    for(int i=0 ; i <size ; i++){

        bool flag = 0;
        for(int j=i+1 ; j<size ; j++){

            // arr[j] chota hai ie next smaller element
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

vector <int> nextSmaller(int arr[] , int n){

    vector <int> ans(n);

    stack <int> stk;
    // Maintaing a stack in descending order and top() element would be the answer if the curr is greater than top

    stk.push(-1);

    for(int i=n-1 ; i>=0 ; i--){

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

    vector <int> ans = nextSmaller(arr,n);

    for(auto &val : ans){
        cout << val << " ";
    }


    return 0;
}