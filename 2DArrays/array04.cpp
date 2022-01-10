#include<iostream>
using namespace std;

bool StairCaseSearch(int arr[][50],int n,int m,int key){
    
    if(n==0 or m==0){return 0;}

    int largest=arr[n-1][m-1];
    int smallest=arr[0][0];

    if(key>largest or key<smallest){
        return 0;
    }

    int i=0; int j=m-1;// starting elements indices
    while(i<n and j>=0){

        if(arr[i][j]==key){
            cout << "Present at => " << i << " , " << j << endl;
            return 1;
        }

        else if(arr[i][j]>key){// left traversal
            j--;
        }

        else{// down traversal
            i++;
        }
    }

}


int main(){

    int arr[50][50];
    int n,m,key;
    cout << "Enter rows and columns => ";
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
        
    }
    cout << "Enter key =>" ; cin >> key;
    
    if(!StairCaseSearch(arr,n,m,key)){
        cout << "Element Not Found .. !";
    }





    return 0;
}