#include<iostream>
#include<vector>

using namespace std;

int solve(int day , int last , vector<vector<int>> &points , vector <vector<int>> &dp){

    // base case
    if(day == 0){
        // I will tend to choose task having max merit other than my last task don

        int maxi = -1;

        for(int task = 0 ; task < 3 ; task++){

            if(task != last){
                maxi = max(maxi , points[day][task]);
            }


        }

        return maxi;
    }

    if(dp[day][last] != -1){
        return dp[day][last];
    }


    // Try all possible stuffs with given constraints and find max

    int maxi = -1;

    // Maximsiing the points that I could receive by starting with all possible task at each day except the last task done
    for(int task = 0 ; task < 3 ; task++){

        if(task != last){

            int merit = points[day][task] + solve(day-1 , task , points , dp);


            maxi = max(maxi , merit);
        }

    }



    return dp[day][last] = maxi;


}






int ninjaTraining(int n, vector < vector < int > > & points) {

  vector < vector < int > > dp(n, vector < int > (4, -1));
  return solve(n - 1, 3, points, dp);
}

int main() {

  vector < vector < int > > points = {{10,40,70},
                                      {20,50,80},
                                      {30,60,90}};

  int n = points.size();
  cout << ninjaTraining(n, points);
}