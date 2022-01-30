#include<iostream>
#include<vector>
using namespace std;

void printArr(vector <vector <int> > &arr, int n){

    for(int i=0 ; i<n ; i++){

        for(int j=0 ; j<n ; j++){

            cout << arr[i][j] << " ";

        }
        cout << endl;
    }

}


void sumTill(vector <vector <int> > &arr, int n){

    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<n ; j++){

            if(i-1>=0){
                arr[i][j] += arr[i-1][j];
            }
            

            if(j-1 >=0){
                arr[i][j] += arr[i][j-1];
            }
            
            if(i-1>=0 and j-1>=0){
                arr[i][j] -= arr[i-1][j-1];
            }


        }
    }




}


int main(){

    vector <vector <int>> arr{

        {1,2,3,-1},
        {-1,3,2,1},
        {0,9,1,-2},
        {8,6,-1,2}

    };

    printArr(arr,4);

    sumTill(arr,4);

    printArr(arr,4);

    return 0;
}