#include <iostream>
#include <vector>

using namespace std;



int getMaxPathSum(vector<vector<int>> &matrix)
{
    // Since our ending point could be anything from

    // (n-1 ,0) , (n-1 , 1) ....... (n-1 , m-1)

    // Exploring answer assuming all ending points one by one

    int n = matrix.size();
    int m = matrix[0].size();

    // vector <vector<int> > dp(n , vector<int> (m,-1));

    vector <int> prev(m,-1);

    // Base case is for row 0 

    for(int j=0 ; j<m ; j++){
        prev[j] = matrix[0][j];
    }

    // Now start the bottom up traversal
    for(int i=1 ; i<n ; i++){

        vector <int> curr(m,-1);

        for(int j=0 ; j<m ; j++){

            int leftD = INT_MIN;
            int up = INT_MIN;
            int rightD = INT_MIN;

            if(i-1 >=0 and j-1 >= 0)
                leftD = prev[j-1];

            if(i-1 >=0 and j<m)
                up =  prev[j];

            if(i-1 >=0 and j+1 <m)    
                rightD = prev[j+1];

            curr[j] = matrix[i][j] + max({leftD , up , rightD});

        }

        prev = curr;

    }

    // Finding maxSum for all the startinf points of our recusrion that were n-1,0 ,(n-1 , 1)...

    int maxi = INT_MIN;

    for(int j=0 ; j<m ; j++){
        maxi = max(maxi , prev[j]);
    }



    return maxi;

}


int main() {

    vector<vector<int> > matrix{{1,2,10,4},
                                {100,3,2,1},
                                {1,1,20,2},
                                {1,2,2,1}};
    
    cout<<getMaxPathSum(matrix);
}