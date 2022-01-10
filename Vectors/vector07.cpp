#include<iostream>
#include<vector>
using namespace std;
// rotate 90 degree clockwise
void rotate(vector<vector<int>>& matrix) {
      // your code goes here
      int n=matrix.size();
      
      int start_row=0;
      int end_row=n-1;
      
      while(start_row < end_row){
          
          for(int i=0 ; i<n ; i++){
              swap(matrix[start_row][i],matrix[end_row][i]);
          }
          start_row++;
          end_row--;
          
      }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(i<j){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        
    }
    

}


int main(){

    vector< vector<int> > v= {

        {1,2,3},
        {4,5,6},
        {7,8,9}
    };

    int n=3;

    rotate(v);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
    


    return 0;
}