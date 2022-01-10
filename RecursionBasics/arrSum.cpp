#include<iostream>
using namespace std;

int arrSum(int arr[], int n){

    // Base Case
    if(n==0){
        return 0;
    }

    if(n==1){
        return arr[0];
    }

    return arr[0]+ arrSum(arr+1,n-1);

}



int main(){

    int arr[]={2,4,10,1,5,3};

    int n = sizeof(arr)/sizeof(arr[0]);

    cout << arrSum(arr,n) << endl;




    return 0;
}