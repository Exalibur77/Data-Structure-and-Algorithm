#include<iostream>
using namespace std;

// Printing all possible ways of placing n queen in a nxn grid.

void printBoard(int board[][20] , int n){

    cout << "Board Is Getting printed" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}


bool canPlace(int board[][20] , int n , int i , int j){

    // Check for column
    // Ki us jth column mein koi aur queen toh nhi hai

    for (int k = 0; k < i; k++)
    {
        if(board[k][j] == 1){ // Already koi queen hai us column mein
            return false;
        }
    }
    
    // check for left diagonal

    int x=i;
    int y=j;

    while(x>=0 and y>=0){

        if(board[x][y] ==1){
            return false;
        }
        x--;
        y--;
    }

    x=i;
    y=j;

    // checking for right diagonal

    while(x>=0 and y<n){
        if(board[x][y] ==1){
            return false;
        }
        x--;y++;
    }

    return true;

}
/*
    Time Complexity 
1.
    nC1 from each row to place queen in n such rows

    n*n*n.... nsuch rows

    O(n^n).

2. or can be said as

    nC1 for 1st row , n-1C1 for 2nd row , n-2C1 for third row ... n such rows
    
    n*(n-1)*(n-2)*(n-3)*(n-4)*(n-5).....

    O(n!)    

*/

int solveNQueen(int n , int board[][20] , int i){ // i representing ith row

    // base case
    if(i == n){
        // print board
        printBoard(board,n);

        // if i==n which means we have reached last row+1 ie we have got the solution 
        return 1;
    }

    // recursive case
    // place one queen in each row

    int ways=0;

    for (int j = 0; j < n; j++)
    {
        // whether the current i , j is safe or not
        if(canPlace(board,n,i,j)){

            board[i][j]=1; // queen is placed.

           ways += solveNQueen(n,board,i+1);// for next row{If neeche wala success hai toh upr wala true return kar de parent ko}

            // if false then current row should change the position of queen to j+1 column

            // BackTrack

            board[i][j]=0;

        }
    }

    return ways;


} 



int main(){

    int board[20][20]={0};
    int n; cin >> n;

    int ans = solveNQueen(n,board,0);
    cout << ans << endl;

    return 0;

}