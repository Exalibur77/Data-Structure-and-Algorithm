#include<iostream>
#include<vector>

using namespace std;


int solve(vector<vector<int>> &points){

    int n = points.size();

    // Space Optimising while Tabulation , since only single previous state of size 4 is rerqired

    vector <int> prev(4,-1);

    // first find answer for the base case

    for(int last = 0 ; last <= 3 ; last++){

        int maxi = -1;

        for(int task = 0 ; task < 3 ; task++){

            if(task != last){
                maxi = max(maxi , points[0][task]);
            }
            
        }
        
        prev[last] = maxi;
    }

    // Now calculating for subsequent days

    for(int day=1 ; day<n ; day++){

        vector <int> temp(4,-1);

        for(int last = 0 ; last <= 3 ; last++){

            int maxi = -1;

            for(int task = 0 ; task < 3 ; task++){

                if(task != last){

                    int merit = points[day][task] + prev[task];
                    maxi = max(maxi , merit);
                }

            }

            temp[last] = maxi;

        }

        prev = temp;

    }

    return prev[3];


}


int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Since days - 0 to n-1 
    // Last Task - 0 , 1, 2, 3(no task previously done)

    return solve(points);

}


int main() {

  vector < vector < int > > points = {{10,40,70},
                                      {20,50,80},
                                      {30,60,90}};

  int n = points.size();
  cout << ninjaTraining(n, points);
}