#include<iostream>
#include<vector>
#include<string>

using namespace std;


// T.C - O(N*M)
// S.C - O(1)
string longestCommonPrefix(vector<string> &arr, int n)
{

    int mini = 1001;

    for(auto &word : arr){
        int size = word.size();
        mini = min(mini , size);
    }

    string ans;

    for(int i=0; i<mini ; i++){

        char prev = arr[0][i];

        for(auto &word : arr){

            if(word[i] != prev) return ans;

        }

        ans += prev;

    }

    return ans;


}

int main(){

    int n;
    cin >> n;

    vector <string> arr(n);

    for(int i=0 ; i<n ; i++){
        cin >> arr[i];
    }

    string ans = longestCommonPrefix(arr,n);

    cout << ans << endl;

    return 0;

}
