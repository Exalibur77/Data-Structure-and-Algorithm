#include<iostream>
#include<vector>
using namespace std;

// Time Complexity O(Range+n)
void counting_sort(int arr[],int n){

    int largest=*max_element(arr,arr+n);//Finds the max_element address in the given range.

    // creating a count array
    vector<int> freq(largest+1,0);

    // Updating the freq array

    for (int i = 0; i < n; i++)
    {
        freq[arr[i]]++;
    }
    
    // Put back elements from frequency array into the original array

    int j=0;// Maintaining the index to be filled in original array

    for (int i = 0; i < largest+1; i++)
    {
        while(freq[i]>0){
            arr[j]=i;
            freq[i]--;
            j++;
        }
    }
    
    return;


}

int main(){

    int arr[]={3,12,43,65,88,9,2,4};
    int n=sizeof(arr)/sizeof(int);

    counting_sort(arr,n);// For positive elements

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;


    return 0;
}