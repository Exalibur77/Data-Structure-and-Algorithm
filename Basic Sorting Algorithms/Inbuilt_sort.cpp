#include<iostream>
#include<algorithm>
using namespace std;

bool comp(int a,int b){
    return a>b; // First Value should be greater than second value.
}

// Inbuilt Sort(Introsort) == Time Complexity O(n*logn) or may use Auxiliary space of O(logn)
int main(){

    int arr[]={12,4,76,-98,-23,27,1,001,23};
    int n=sizeof(arr)/sizeof(int);

    // sort(arr,arr+n);

    // Inbuilt Comparator Function.
    // sort(arr,arr+n,greater<int>());// For sorting in descending order.

    sort(arr,arr+n,comp);// using comp function as an parameter to an another inbuilt function sort.


    // reverse(arr,arr+n);// Time Complexity O(n)

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;




    return 0;
}