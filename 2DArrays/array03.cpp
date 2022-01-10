#include<iostream>
using namespace std;

void SpiralPrint(int arr[][50],int n,int m){

    int start_row=0;
    int start_col=0;
    int end_row=n-1;
    int end_col=m-1;

    while(start_col<=end_col and start_row<=end_row){

        // start row
        for (int i = start_col; i <= end_col; i++)
        {
            cout << arr[start_row][i] << " ";
        }
        start_row++;
        
        // end col
        for (int i = start_row; i <= end_row; i++)
        {
            cout << arr[i][end_col] << " ";
        }
        end_col--;

        // end row
        if(start_row<end_row){

            for (int i = end_col; i >= start_col ; i--)
            {
                cout << arr[end_row][i] << " ";
            }
            end_row--;

        }

        // start col
        if(start_col<end_col){
            for (int i = end_row; i >= start_row; i--)
            {
                cout << arr[i][start_col] << " ";
            }
            start_col++;
        }

    }

    return;
}



int main(){

    int arr[50][50];
    int n,m;
    cout << "Enter rows and columns => ";
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
        
    }
    
    SpiralPrint(arr,n,m);




}