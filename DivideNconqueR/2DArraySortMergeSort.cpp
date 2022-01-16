#include<bits/stdc++.h>
using namespace std;

void merge_row(vector<vector<int>> &arr, int row , int cs , int cm , int ce){

    int i=cs;
    int j=cm+1;

    vector <int> sorted;

    while(i<=cm and j<=ce){

        if(arr[row][i] < arr[row][j]){
            sorted.push_back(arr[row][i++]);
        }

        else{
            sorted.push_back(arr[row][j++]);
        }
    }

    while(i<=cm){
        sorted.push_back(arr[row][i++]);
    }

    while(j<=ce){
        sorted.push_back(arr[row][j++]);
    }

    int k=0;

    for(int i=cs ; i<=ce ; i++){
        arr[row][i]=sorted[k++];
    }

    return;

}

void merge_col(vector<vector<int>> &arr, int col , int rs , int rm , int re){

    int i=rs;
    int j=rm+1;

    vector <int> sorted;

    while(i<=rm and j<=re){

        if(arr[i][col] < arr[j][col]){
            sorted.push_back(arr[i++][col]);
        }

        else{
            sorted.push_back(arr[j++][col]);
        }
    }

    while(i<=rm){
        sorted.push_back(arr[i++][col]);
    }

    while(j<=re){
        sorted.push_back(arr[j++][col]);
    }

    int k=0;

    for(int i=rs ; i<=re ; i++){
        arr[i][col]=sorted[k++];
    }

    return;

}






void merge(int m, int n, vector<vector<int>> &arr , int rs,int rm, int re , int cs, int cm , int ce){

    // merging each row
    for(int i=rs ; i<=re ; i++){
        merge_row(arr,i,cs,cm,ce);
    }

    //merging each colum
    for(int i=cs ; i<=ce ; i++){
        merge_col(arr,i,rs,rm,re);
    }

    return;

}






void merge_sort(int m, int n, vector<vector<int>> &arr , int rs, int re , int cs , int ce){


    // base case
    if(rs>=re and cs>=ce){
        return;
    }

    int rm = (rs+re)/2;
    int cm = (cs+ce)/2;

    // recursive sorting
    merge_sort(m,n,arr,rs,rm,cs,cm);
    merge_sort(m,n,arr,rm+1,re,cs,cm);
    merge_sort(m,n,arr,rs,rm,cm+1,ce);
    merge_sort(m,n,arr,rm+1,re,cm+1,ce);



    // merging all these subarrays
    merge(m,n,arr,rs,rm,re,cs,cm,ce);



}





vector<vector<int>> mergeSort(int m, int n, vector<vector<int>> &arr){// m rows and n columns

    merge_sort(m,n,arr,0,m-1,0,n-1);

    return arr;
}


int main(){

    vector<vector<int>> arr{

        {9,1,4,2},
        {3,1,4,6},
        {5,3,1,7},
        {3,1,5,1}
    };

    int row = arr.size();
    int col = arr[0].size();

    vector <vector<int> > ans = mergeSort(row,col,arr);

    for(int i=0 ; i<row ; i++){
        for(int j=0 ; j<col ; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }



}