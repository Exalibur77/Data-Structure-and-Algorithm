#include<iostream>
#include<vector>

using namespace std;
    
bool isSafe(int row , int col , int val , vector<vector<char>>& board){

    int n = board.size();

    for(int i=0 ; i<n ; i++){

        // same row

        if(board[row][i] == val) return false;

        // same column

        if(board[i][col] == val) return false;

        // same subgrid
        if(board[3*(row/3) + i/3][3*(col/3) + i%3] == val) return false;

    }

    return true;

}


bool solve(vector<vector<char>>& board){

    int n= board.size();
    int m= board[0].size();

    for(int row=0 ; row<n ; row++){

        for(int col = 0 ; col<n ; col++){

            // if an empty cell is encountered

            if(board[row][col] == '.'){

                // try to place any value from 1 to 9

                for(char val = '1' ; val <= '9' ; val++){

                    if(isSafe(row , col , val , board)){

                        board[row][col] = val; // place the value

                        bool success = solve(board);

                        if(success) return true;

                        // backtrack , since aage we cannot make a valid sudoko so backtrack previous empty position
                        else{
                            board[row][col] = '.';
                        }

                    }

                }

                return false;

            }


        }

    }

    return true;

}

void solveSudoku(vector<vector<char>>& board) {
    
    solve(board);

}


int main(){


    vector<vector<char>> vec(9, vector<char>(9,'0'));

    for(int i=0 ; i<9 ; i++){

        for(int j=0 ; j<9 ; j++){

            char ch;

            cin >> ch;

            vec[i][j] = ch;

        }


    }

    cout << " Answer Soduko " << endl;

    solveSudoku(vec);

    for(auto &v : vec){

        for(auto &val : v){

            cout << val << " ";

        }

        cout << endl;
    }

}

