#include <iostream>
#include<vector>
using namespace std; 

// T.C - O(N! * N)
// S.C - O(N)

void addAns(vector < vector <int> > &grid , vector < vector<int> > &ans , int n){

	vector <int> temp;

	for(int i=0 ; i<n ; i++){

		for(int j=0 ; j<n ; j++){

			temp.push_back(grid[i][j]);

		}

	}

	ans.push_back(temp);


}


bool isSafe(int row , int col , vector <int> &leftRow , vector <int> &upperDiagonal ,vector <int> &lowerDiagonal , int n){


	return leftRow[row] == 0 and upperDiagonal[n-1 + col-row] == 0 and lowerDiagonal[row+col] == 0;


}

void solve(int col , int n , vector < vector <int> > &grid , vector < vector<int> > &ans ,vector <int> &leftRow , vector <int> &upperDiagonal ,vector <int> &lowerDiagonal){

	// base case
	if(col == n){
		addAns(grid , ans , n);
		return;
	}

	// try to place in every row of the given column

	for(int row = 0 ; row < n ; row++){

		if(isSafe(row , col , leftRow , upperDiagonal , lowerDiagonal , n)){

			// queen place kriye
			grid[row][col] = 1;

			leftRow[row] = 1;
			lowerDiagonal[row+col] = 1;
			upperDiagonal[n-1+col-row] = 1;

			// now move ahead to place at the next colum
			solve(col+1 , n , grid , ans , leftRow , upperDiagonal , lowerDiagonal);

			leftRow[row] = 0;
			lowerDiagonal[row+col] = 0;
			upperDiagonal[n-1+col-row] = 0;
			
			// now if we are not able to reach to the end remove this given queen and place it to some other position
			grid[row][col] = 0;


		}

	}

}


vector<vector<int>> nQueens(int n)
{
	
	vector < vector <int> > grid(n , vector<int>(n,0));

	vector < vector<int> > ans;

	vector <int> leftRow(n,0) , upperDiagonal(2*n - 1 ,0) , lowerDiagonal(2*n-1 , 0);

	int i = 0; // staring from the first column

	solve(i , n , grid , ans , leftRow , upperDiagonal , lowerDiagonal);

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