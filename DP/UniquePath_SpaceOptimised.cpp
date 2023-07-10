#include <iostream>
#include <vector> 

using namespace std;

// Space Optimization , since we only require previous row and columns only for evry state

int uniquePaths(int n, int m) {
	
	vector <int> prevRow(m,0);

	for(int i=0 ; i<n ; i++){

		vector <int> temp(m,0);

		for(int j=0 ; j<m ; j++){

			if(i==0 and j==0){
				temp[j] = 1;
			}

			else{

				int left = 0;
				int up = 0;

				if(j-1 >= 0){
					left = temp[j-1];
				}

				if(i-1 >= 0){
					up = prevRow[j];
				}

				temp[j] = left+up;
			}
		}

		prevRow = temp;

	}

	return prevRow[m-1];


}


int main(){

    int n = 5;
    int m = 3;

    cout << uniquePaths(5,3) << endl;

    return 0;
}