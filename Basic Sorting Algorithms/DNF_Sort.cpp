#include<iostream>
using namespace std;

void dnfsort(int arr[] , int n){

    int s =0 ;
    int e =n-1;
    int mid = 0;

    while(mid <= e){

        switch (arr[mid])
        {
        case 0:
            swap(arr[s++],arr[mid++]);
            break;
        case 1:
            mid++;
            break;
        case 2:
            swap(arr[mid],arr[e--]);
            break;
        
        default:
            break;
        }

    }


    return ;

}



int main(){

    int arr[]={2,1,2,1,1,0,0,0,1};
    int n = sizeof(arr)/sizeof(arr[0]);

    dnfsort(arr,n);

    for(int &val: arr){
        cout << val << " ";
    }    
    cout << endl;

}