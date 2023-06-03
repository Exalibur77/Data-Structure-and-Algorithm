#include <iostream>
#include<vector>
using namespace std; 

void addAns(vector < vector <int> > &grid , vector < vector<int> > &ans , int n){

	vector <int> temp;

	for(int i=0 ; i<n ; i++){

		for(int j=0 ; j<n ; j++){

			temp.push_back(grid[i][j]);

		}

	}

	ans.push_back(temp);


}


bool isSafe(int row , int col , vector < vector <int> > &grid , int n){
	
	int x = row;
	int y = col;

	// check for the same row

	for(int i=0 ; i<y ; i++){

		if(grid[x][i] == 1) return false;

	}

	// for upper left diagonal

	x = row;
	y = col;


	while(x >=0 and y >= 0){

		if(grid[x][y] == 1) return false;

		x--;
		y--;
	}


	// check for bottom left diagonal

	x = row;
	y = col;

	while(x < n and y >=0){

		if(grid[x][y] == 1) return false;

		x++;
		y--;
	}

	return true;

}

void solve(int col , int n , vector < vector <int> > &grid , vector < vector<int> > &ans){

	// base case
	if(col == n){
		addAns(grid , ans , n);
		return;
	}

	// try to place in every row of the given column

	for(int row = 0 ; row < n ; row++){

		if(isSafe(row , col , grid , n)){

			// queen place kriye
			grid[row][col] = 1;

			// now move ahead to place at the next colum
			solve(col+1 , n , grid , ans);

			// now if we are not able to reach to the end remove this given queen and place it to some other position
			grid[row][col] = 0;

		}

	}

}





vector<vector<int>> nQueens(int n)
{
	
	vector < vector <int> > grid(n , vector<int>(n,0));

	vector < vector<int> > ans;

	int i = 0; // staring from the first column

	solve(i , n , grid , ans);

	return ans;

	
}

int main(){

    int n ;
    cin >> n;

    vector < vector<int> > ans = nQueens(n);

    for(auto &v : ans){

        for(auto &val : v){
            cout << val<< " ";
        }

        cout << endl;
    }

    return 0;


}