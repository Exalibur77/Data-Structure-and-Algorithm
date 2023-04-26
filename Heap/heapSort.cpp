#include<iostream>
#include <vector>
using namespace std;

// Heapify Algorith is a process of creating a heap from an given array.


// Making the heap below the index ie arranging value in max Heap
void heapify(vector <int> &arr , int n , int index){

    int largest = index;

    int left = 2*index +1;
    int right = 2*index +2;

    if(left < n and arr[left] > arr[largest]){
        largest = left;
    } 

    if(right < n and arr[right] > arr[largest]){
        largest = right;
    }


    if(largest != index){
        swap(arr[largest] , arr[index]);

        // recursively call for the affected sub tree whose rootIndex would be largest
        heapify(arr,n,largest);
    }


}


vector <int> createHeap(vector <int> &arr){

    int n = arr.size();

    // Running heapify function for only non leaf nodes index
    for(int i=n/2-1 ; i>=0 ; i--){

        heapify(arr,n,i);

    }

    return arr;

}


void heapSort(vector <int> &arr , int n){

    int size = n;

    while(size){

        // Step 1 : Swap the last element with the greatest 0th element
        swap(arr[0],arr[size-1]);

        size--;
        // decrement size

        // Step 2 : Place the value at root at correct position at every iteration
        heapify(arr,size,0);

    }

}

int main(){

    int n ;
    cin >> n;

    cout << "Input Array " << endl;

    vector <int> arr(n,0);

    for(int i=0 ; i<n ; i++){
        int val;
        cin >> val;
        arr[i] = val;
    }

    // First Creation of heap of the random entered array

    // T.C ~ O(N)
    vector <int> ans = createHeap(arr);

    cout << "Printing Heap Array" << endl;

    for(auto &val : ans){
        cout << val << " ";
    }

    cout << endl;

    // TC ~ O(N * log2N)
    heapSort(ans,n);

    cout << "Printing Sorted Array" << endl;

    for(auto &val : ans){
        cout << val << " ";
    }



}