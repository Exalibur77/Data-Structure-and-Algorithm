#include<iostream>
using namespace std;

// Time Complexity O(n^2)
void insertion_sort(int arr[], int n){

    for (int i = 0; i < n-1; i++)
    {
        int min_idx=i;
        bool flag=0;

        // Finding the min_idx which is smallest among the unsorted array.
        for (int j = i+1; j < n; j++)
        {
            if(arr[min_idx]>arr[j]){
                min_idx=j;
                flag=1;
            }
        }
        if(flag==1){
            swap(arr[min_idx],arr[i]);
        }
    }
    

    return;


}

int main(){

    int arr[]={12,4,76,-98,-23,27,1,001,23};
    int n=sizeof(arr)/sizeof(int);

    insertion_sort(arr,n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;


    return 0;

}