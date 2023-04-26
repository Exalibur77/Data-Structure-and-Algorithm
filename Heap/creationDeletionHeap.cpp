#include<iostream>
using namespace std;

// Creating a Max Heap

class Heap{

    private:
        int arr[100];
        int size;

    public:

    Heap(){
        size = 0;
        arr[0] = -1;
    }

    void insert(int val){

        // Add the value at the end of the array and increase the size of array by 1

        size = size + 1;
        // index at which we have to insert a new value
        int index = size;

        arr[index] = val;

        // now check for all its parent 


        // Since index is being reduced by 2 at every check index insearch of parent index hence T.C - O(log2n)

        while(index > 1){

            int parentIndex = index/2;

            // value that is inserted is greater than its parent 
            if(arr[parentIndex] < arr[index]){

                // swap both the array elements
                swap(arr[parentIndex],arr[index]);

                // index is now changed to its parentIndex
                index = parentIndex;

            } 

            // value is smaller than its parent then it means , value is inserted at right position 
            else{
                return;
            }

        }



    }


    void print(){

        for(int i=1 ; i<=size ; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    // Delete function always delete only the root node

    // Time Complexity - O(log2n)

    void deleteFromHeap(){

        if(size == 0){
            cout << "Nothing to Delete" << endl;
        }

        // step : 1

        // copy the last value in the root node index

        arr[1] = arr[size];

        // step : 2

        // remove the last index value
        size--;


        // Step :3 Propogate the root index value to its correct position

        int i = 1;

        while(i < size){

            int leftIndex = 2*i;
            int rightIndex = 2*i+1;

            // correct index to which this current index is to be swapped
            int swapIndex = i;

            // leftChild is greater than my swap Index then it becomes leftIndex
            if(leftIndex <= size && arr[swapIndex] < arr[leftIndex]){
                swapIndex = leftIndex;
            }

            // if right child is also greater than my new or old swap index then update it to rightIndex
            if(rightIndex <= size && arr[swapIndex] < arr[rightIndex]){
                swapIndex = rightIndex;
            }

            
            if(i != swapIndex){
                swap(arr[i], arr[swapIndex]);
                i = swapIndex;
            }

            // it means no left and right child is greater hence swap index == i
            else{
                return ;
            }

        }



    }


};


int main(){

    Heap h;

    h.insert(10);
    h.insert(20);
    h.insert(40);
    h.insert(5);
    h.insert(1);

    h.print();

    h.deleteFromHeap();

    h.print();

}