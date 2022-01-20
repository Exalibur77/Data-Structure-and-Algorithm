#include<iostream>
using namespace std;

// Given a nxm grid , we have to count the number of ways to reach n-1,m-1 block

int countPaths(int i, int j, int n, int m){

    cout << i << " " << j << endl;
    // base case
    if(i==n-1 and j==m-1){
        return 1;
    }

    // corner case[when we get out of the grid]
    if(i==n or j==m){
        return 0;
    }

    int ans = countPaths(i+1,j,n,m) + countPaths(i,j+1,n,m);

    return ans;

}




int main(){

    int n,m;
    cin >> n >> m;

    int ans = countPaths(0,0,n,m);
    cout << ans << endl;

    return 0;
}