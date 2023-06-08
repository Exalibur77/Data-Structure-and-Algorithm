#include<iostream>
using namespace std;

// Function to return the
// maximum xor

// T.C - O(N^2)
int max_xor(int arr[], int n)
{

    int maxXor = 0;

    // Calculating xor of each pair
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            maxXor = max(maxXor,
                         arr[i] ^ arr[j]);
        }
    }
    return maxXor;
}



// Driver Code
int main()
{

    int arr[] = { 25, 10, 2, 8, 5, 3 };
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << max_xor(arr, n) << endl;
    return 0;
}