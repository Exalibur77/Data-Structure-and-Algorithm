#include<iostream>
#include<vector>

using namespace std;

int main(){

    // Unlike 2D array we can have different columns for each row
    vector < vector <int> > arr = {
        {1,23,4,5},
        {2,3,4},
        {11,22,33,44,45,55},
        {0,1,10,0,-1}
    };
    
    // Using iterative for loops
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[i].size(); j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    
    // Using for each loop

    for (vector <int> row : arr){

        for (int val : row)
        {
            cout << val << " ";
        }
        cout << endl;
    }
    

    

    return 0;
}