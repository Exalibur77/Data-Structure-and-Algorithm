#include<iostream>
using namespace std;

void print(int arr[][100],int n,int m){// Passing value of max_colum is necessary but passing max_row is optional.

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    return;

}
int main(){

    int arr[100][100];

    int n,m;
    cout << "Enter number of rows and columns => ";
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
        
    }
    cout << endl;

    // printing a 2D array
    print(arr,n,m);

    return 0;
}

