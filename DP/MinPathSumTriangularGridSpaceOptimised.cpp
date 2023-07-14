#include <iostream>
#include <vector>
using namespace std;

int minimumPathSum(vector<vector<int> > &triangle, int n){
    vector <int> nextRow(n);

	// base case is for row n-1

	for(int j=0 ; j<n ; j++){
		nextRow[j] = triangle[n-1][j];
	}


	for(int i=n-2 ; i>=0 ; i--){

		vector <int> curr(n,0);

		for(int j=i ; j>=0 ; j--){

			int down =  triangle[i][j] + nextRow[j];

			int diagonal = triangle[i][j] + nextRow[j+1];

			curr[j] = min(down, diagonal);

		}

		nextRow = curr;

	}


	return nextRow[0];

    
}

int main() {

  vector<vector<int> > triangle{{1},
                                {2,3},
                                {3,6,7},
                                {8,9,6,10}};
                            
  int n = triangle.size();
  
  cout<<minimumPathSum(triangle,n);
}