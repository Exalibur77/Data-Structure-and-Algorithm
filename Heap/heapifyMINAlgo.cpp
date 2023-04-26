#include<iostream>
#include <vector>
using namespace std;

// Heapify Algorith is a process of creating a heap from an given array.


// Making the heap below the index ie arranging value in max Heap
void heapify(vector <int> &arr , int n , int index){

    int smallest = index;

    int left = 2*index +1;
    int right = 2*index +2;

    if(left < n and arr[left] < arr[smallest]){
        smallest = left;
    } 

    if(right < n and arr[right] < arr[smallest]){
        smallest = right;
    }


    if(smallest != index){
        swap(arr[smallest] , arr[index]);

        // recursively call for the affected sub tree whose rootIndex would be largest
        heapify(arr,n,smallest);
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

    // Asssuming Here 0 based indexing 

    vector <int> ans = createHeap(arr);

    cout << "Printing Heap Array" << endl;

    for(auto &val : ans){
        cout << val << " ";
    }

}