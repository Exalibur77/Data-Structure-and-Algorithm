#include<iostream>
using namespace std;

void printArr(int arr[][9] , int n){

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

}

bool isSafe(int arr[9][9] , int i , int j , int num , int n){

    // check for the column
    for(int k=0 ; k<n ; k++){
        if(arr[k][j] == num){
            return false;
        }
    }

    // check for the row
    for(int k=0 ; k<n ; k++){
        if(arr[i][k] == num){
            return false;
        }
    }

    // checking for subgrid[sx,sy represents the starting coordinate of their respective grid]
    int sx= (i/3)*3;
    int sy = (j/3)*3;

    for(int x=sx ; x<sx+3 ; x++){

        for(int y=sy ; y<sy+3 ; y++){

            if(arr[x][y] == num){
                return false;
            }
        }


    }

    return true;

}


bool solveSoduko(int arr[9][9] , int i , int j , int n){

    // base case
    // if my row becomes equal to n
    if(i==n){
        // print the answer 
        printArr(arr,n);
        return true;
    }

    // recursive case
    if(j==n){
        return solveSoduko(arr,i+1,0,n);
    }

    // skip the prefilled cell
    if(arr[i][j]!=0){
        return solveSoduko(arr,i,j+1,n);
    }

    // on the cell to be filled 
    // try out all possibility

    for (int num =1; num <= n; num++)
    {
        // check if it is safe to place num at current i,j

        if(isSafe(arr,i,j,num,n)){

            arr[i][j]=num;

            bool success = solveSoduko(arr,i,j+1,n);

            if(success){
                return true;
            }

        }

    }

    // if no num works 
    // backtrack it to 0 and call for the previously filled cell
    arr[i][j] = 0;
    return false;
    

}




int main(){

    int n=9;
    int arr[9][9]={

        {5,3,0,0,7,0,0,0,0},
        {6,0,0,1,9,5,0,0,0},
        {0,9,8,0,0,0,0,6,0},
        {8,0,0,0,6,0,0,0,3},
        {4,0,0,8,0,3,0,0,1},
        {7,0,0,0,2,0,0,0,6},
        {0,6,0,0,0,0,2,8,0},
        {0,0,0,4,1,9,0,0,5},
        {0,0,0,0,8,0,0,7,9}

    };

    if(!solveSoduko(arr,0,0,n)){
        cout << "No Solution Exists" << endl;
    }




    return 0;
}