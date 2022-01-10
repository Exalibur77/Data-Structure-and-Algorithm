#include<iostream>
#include<math.h>
#include<vector>
using namespace std;

// Printing subsets of the given array ( random combination but comes accordinf to their position)''

/*
    {a,b,c} = {a},{b},{c},{a,b},{b,c},{a,c},{a,b,c},{}  // total 2^n


*/

void printSubsets(int arr[] , int n){

    // O(n*(2^n))
    int N = pow(2,n);

    // N is number of subsets each i represented by its binary number denotes the subset

    /*
        [1,2,3]
        
        0 -> 000 {}
        1 -> 001 {1} // 0th bit is 1 hence arr[0] is the subset
        2 -> 010 {2} // 1st bit is 1 hence arr[1] is the subset
        3 -> 011 {1,2} // 0th and 1st bit is 1 hence arr[0],arr[1] is the subset
        4 -> 100 {3}
        5 -> 101 {1,3}
        6 -> 110 {2,3}
        7 -> 111 {1,2,3}
    
    
    
    */

    for (int i = 0; i < N; i++)
    {
        
        for (int j = 0; j < n; j++)
        {
            int mask = (1<<j);
            
            if((mask&i)!=0){
                cout << arr[j] << " ";
            }
        }
        cout << endl;
    }
    
}


void printSubsequence(string str){

    // O(n*(2^n))
    int n = str.size();
    int N = 1<<n ; //pow(2,n)

    for (int i = 0; i < N; i++)
    {
        
        for (int j = 0; j < n; j++)
        {
            int mask = (1<<j);
            
            if((mask&i)!=0){
                cout << str[j] << " ";
            }
        }
        cout << endl;
    }
    
}

void solve(int arr[] , vector <int> output , int index , int n){

    if(index >= n){

        for (int i = 0; i < output.size(); i++)
        {
            cout << output[i] << " ";
        } 
        cout << endl;

        return ;
    }
    // if not included

    solve(arr,output,index+1,n);

    // included
    int ele = arr[index];
    output.push_back(ele);

    solve(arr,output,index+1,n);

}



void PrintSubsets(int arr[] , int n){

    vector <int> output;
    int index =0;
    solve(arr,output,index,n);


}





int main(){

    int arr[]={1,2,3};

    int n= 3;

    printSubsets(arr,n);

    printSubsequence("ABC");

    // Using recursion

    // PrintSubsets(arr,n);



    return 0;
}