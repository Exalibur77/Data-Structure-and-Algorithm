#include <iostream>
#include<vector>
#include<string>

using namespace std;


bool isSafe(int x , int y , vector < vector < int >> & arr ,vector < vector<bool> > &visited , int n ){

    return ((x >= 0 and x < n) and (y>=0 and y<n) and visited[x][y] != 1 and arr[x][y] == 1) ;

}



void solve(int x , int y , int n , vector < vector < int >> & arr  , vector < vector<bool> > &visited , string &path , vector <string> & ans){


    // base case [ Reached destination]
    if(x == n-1 and y == n-1){
        ans.push_back(path);
        return;
    }

    // Mark the current position as visited
    visited[x][y] = 1;

    // now i have four possible paths to reach destination so we would explore all of them
    // now to find ans in lexographical pattern , do D L R U

    vector < pair<int,int> > temp = {

        {1 , 0},
        {0 , -1},
        {0 , 1},
        {-1 , 0}
    };

    string dir = "DLRU";

    for(int i=0 ; i<temp.size() ; i++){

        int newx = x+temp[i].first;
        int newy = y+temp[i].second;

        if(isSafe(newx, newy, arr, visited, n)){

            path.push_back(dir[i]);

            solve(newx , newy , n , arr , visited , path , ans);

            path.pop_back();
        }

    }


    //now i have tried all possible ways , no backtrack to previous step to check for other answers
    visited[x][y] = 0;


}







vector < string > searchMaze(vector < vector < int >> & arr, int n) {
    
    // visited array
    vector <vector<bool>> visited(n , vector<bool>(n,0));

    vector <string> ans;

    string path = "";

    if(arr[0][0] == 0) return {};

    solve(0,0,n,arr,visited,path,ans);

    return ans;


}

int main(){

    int n;

    cin >> n ;

    vector <vector<int>> v(n, vector<int>(n));

    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<n ; j++){

            cin >> v[i][j];
        }
    }

    auto ans = searchMaze(v,n);

    for(auto &str : ans){
        cout << str << endl;
    }


    return 0;
}