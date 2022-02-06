#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int main(){

    vector <int> v{5,3,1,4,74,2,19};

    int n=v.size();



    // v.begin()+4  is now having the correct value which would come after sorting and left and right part of that are smaller and greater than of it respectively.

    // or gives the fifth smallest number if all are unique 


    // nth_element(v.begin(),v.begin()+4,v.end());

    for(int &val : v){
        cout << val << " ";
    }
    cout << endl;

    // Gives the fifth largest element in the given array.
    nth_element(v.begin(),v.begin()+4,v.end(),greater<int>());
    
    for(int &val : v){
        cout << val << " ";
    }


    // Partial Sorting 
    // Time Complexity -- O(N)

}