#include<iostream>
#include<vector>

using namespace std;


int solve(vector<vector<int>> &points , vector <vector<int>> &dp){

    int n = points.size();

    // Using Tabulation 

    // first find answer for the base case

    for(int last = 0 ; last <= 3 ; last++){

        int maxi = -1;

        for(int task = 0 ; task < 3 ; task++){

            if(task != last){
                maxi = max(maxi , points[0][task]);
            }
            
        }
        
        dp[0][last] = maxi;
    }

    // Now calculating for subsequent days

    for(int day=1 ; day<n ; day++){

        for(int last = 0 ; last <= 3 ; last++){

            int maxi = -1;

            for(int task = 0 ; task < 3 ; task++){

                if(task != last){

                    int merit = points[day][task] + dp[day-1][task];
                    maxi = max(maxi , merit);
                }

            }

            dp[day][last] = maxi;

        }


    }



    return dp[n-1][3];


}


int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Since days - 0 to n-1 
    // Last Task - 0 , 1, 2, 3(no task previously done)
    
    vector <vector<int>> dp(n , vector <int>(4,-1));

    return solve(points , dp);

}


int main() {

  vector < vector < int > > points = {{10,40,70},
                                      {20,50,80},
                                      {30,60,90}};

  int n = points.size();
  cout << ninjaTraining(n, points);
}