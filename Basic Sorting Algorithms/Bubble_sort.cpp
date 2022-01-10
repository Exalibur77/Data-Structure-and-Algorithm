#include<iostream>
using namespace std;

// Bubble Sort -- Time Complexity O(n^2)

void Bubble_sort(int arr[], int n){// Call by reference automatically

    for (int times = 1; times <= n-1; times++)
    {
        bool is_swap=false;

        // repeated swapping
        for (int i = 0; i <= n-1-times; i++)
        {
            if(arr[i]>arr[i+1]){
                swap(arr[i],arr[i+1]);
                is_swap=true;
            }
        }
        
        if(!is_swap){
            return;
        }

    }
    
    return ;

}



int main(){

    int arr[]={12,4,76,-98,-23,27,1};
    int n=sizeof(arr)/sizeof(int);

    Bubble_sort(arr,n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;



    return 0;
}