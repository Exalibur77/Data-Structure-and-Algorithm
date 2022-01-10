#include<iostream>
#include<vector>

using namespace std;

int main(){

    vector <int> arr{1,2,4,5,6,7};

    // Popping back function O(1)
    arr.pop_back();

    // Push_back Function O(1)
    arr.push_back(12);

/*    // Size of the array
    cout << arr.size() << endl;

    // Capacity of the array
    cout << arr.capacity() << endl;
*/

    // Print All Elements
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << endl;
    }

    // Printing using for each loop

    for (int val : arr){
        cout << val << ",";
    }
    cout << endl;


    return 0;
}