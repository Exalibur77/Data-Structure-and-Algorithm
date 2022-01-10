#include<iostream>
using namespace std;

// using brute_force approach

// O(n^2 * n^2) approach.
int MangoTree01(char arr[][100],int n){

    int ans=0;
    for (int row = 0; row < n-1; row++)
    {
        for (int col = 0; col < n-1; col++)
        {
           int s1=0,s2=0,s3=0,s4=0;

           /*
                 S1     |   s2
                        |
                      -------
                        |
               s3       |      s4
           
           */

            // Calculating Trees in S1
            for (int i = 0; i <= row ; i++)
            {
                for (int j = 0; j <= col; j++)
                {
                    if(arr[i][j]=='#'){
                        s1++;
                    }
                }
                
            }

            // Calculating Tress in S2
            for (int i = 0; i <= row ; i++)
            {
                for (int j = col+1; j < n; j++)
                {
                    if(arr[i][j]=='#'){
                        s2++;
                    }
                }
                
            }

            // calculating Tress in S3
            for (int i = row+1; i < n ; i++)
            {
                for (int j = col+1; j < n; j++)
                {
                    if(arr[i][j]=='#'){
                        s3++;
                    }
                }
                
            }
            
            // Calculating Tress in S4
            for (int i = row+1; i < n ; i++)
            {
                for (int j = 0; j <= col; j++)
                {
                    if(arr[i][j]=='#'){
                        s4++;
                    }
                }
                
            }
           

            int min_tree=min(s1,min(s2,min(s3,s4)));
            ans=max(ans,min_tree);

        }
        
    }
    

    return ans;




}

int MangoTree02(char arr[][100],int n){

    int ans=0;
    int temp[100][100];

    // for creating the left most column of the temp array
    for (int i = 0; i < n; i++)
    {   
        if(arr[i][0]=='#'){
            temp[i][0]=1;
        }

        else{
            temp[i][0]=0;
        }

        if(i!=0){
            temp[i][0]+=temp[i-1][0];
        }
 
    }

    // for creating the top  most row of the temp array
    for (int i = 0; i < n; i++)
    {  
        if(arr[0][i]=='#'){
            temp[0][i]=1;
        }
        
        else{
            temp[0][i]=0;
        }

        if(i!=0){
            temp[0][i]+=temp[0][i-1];
        }
        
    }
    
    
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if(arr[i][j]=='#'){
                temp[i][j]=1+temp[i-1][j]+temp[i][j-1]-temp[i-1][j-1];
            }
            else{
                temp[i][j]=0+temp[i-1][j]+temp[i][j-1]-temp[i-1][j-1];
            }
        }
        
    }
    

    for (int i=0 ; i < n ; i++)
    {
        for(int j=0; j < n; j++)
        {
            cout << temp[i][j]<<" ";
        }

        cout<<endl;
    }

/*
                 S1     |   s2
                        |
                      -------
                        |
               s3       |      s4
           
 */

    for (int row = 0; row < n-1; row++)
    {
        int s1,s2,s3,s4;
        int min_tree;
        for (int col = 0; col < n-1; col++)
        {
            s1=temp[row][col];
            s2=temp[row][n-1]-s1;
            s3=temp[n-1][col]-s1;
            s4=temp[n-1][n-1]-s1-s2-s3;

            min_tree=min(s1,min(s2,min(s3,s4)));
            ans=max(ans,min_tree);
        }
    }
    return ans;
}


// Mango Tress Problems
int main(){

    char arr[100][100];

    int n;cin >>n;
    cin.get();

    for (int i = 0; i < n; i++)
    {
        cin.getline(arr[i],100);
    }

    cout << MangoTree01(arr,n) << endl;
    cout << MangoTree02(arr,n) << endl;
    

    return 0;
}