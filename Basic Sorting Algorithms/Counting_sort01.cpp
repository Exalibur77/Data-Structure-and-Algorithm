#include<iostream>
#include<vector>
using namespace std;

/*
The problem with the previous counting sort was that we could not sort the elements if we have negative numbers in it. Because there are no negative array indices. So what we do is, we find the minimum element and we will store count of that minimum element at zero index.
*/

// Counting sort for negative number as well
void counting_sort(vector<int> &arr){

    int n=arr.size();

    int max = *max_element(arr.begin(), arr.end());
    int min = *min_element(arr.begin(), arr.end());
    int range = max - min + 1;

    vector<int> freq(range,0);

    //Creating an frequency array.

    for (int i = 0; i < n; i++)
    {
        freq[arr[i]-min]++;
    }
    
    // Putting back elements from frequency array into the original array

    int j=0;// Maintaining the index to be filled in original array

    for (int i = 0; i < range; i++)
    {
        while(freq[i]>0){
            arr[j]=i+min;
            freq[i]--;
            j++;
        }
    }

    return;
}

int main(){

    vector<int> arr ;
    arr.push_back(-5);
    arr.push_back(10);
    arr.push_back(0);
    arr.push_back(-3);
    arr.push_back(8);
    arr.push_back(5);
    arr.push_back(-1);
    arr.push_back(10);

    counting_sort(arr);

    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << "\n";


    return 0;
}