#include<iostream>
using namespace std;
  
void reverseArray(int arr[],int n){
    int s=0;
    int e=n-1;

    while (s<e)
    {
        swap(arr[s],arr[e]);
        s+=1;
        e-=1;

    }
    

}

int main(){

    int arr[]={12,3,5,45,2,65,66,9,8,44};

    int n=sizeof(arr)/sizeof(int);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    reverseArray(arr,n);

    //Print Output

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;


    return 0;
}