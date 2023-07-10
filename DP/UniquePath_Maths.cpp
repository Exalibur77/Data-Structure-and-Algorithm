#include <iostream>
#include <vector> 

using namespace std;

int uniquePaths(int n, int m) {
    

	// Imagine it as a permutation problem 

	// D D D R R R R
	// n-1     m-1

	// Now permutation of such a string with duplicates

	// (n+m-2)!
	// -------
	// (n-1)! (m-1)!

	int ans = 1;

	for(int i=1 ; i<= m-1 ; i++){

		ans = ans * (n+m-1-i)/i ;


	}

	return ans;


}


int main(){

    int n = 5;
    int m = 3;

    cout << uniquePaths(5,3) << endl;

    return 0;
}