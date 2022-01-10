#include<iostream>
#include<vector>
#include<algorithm>
// #include<numeric>
using namespace std;

// All of , none of and any of Functions (returns true or false)
int main(){

    // Lambda Functions (Short representation of the functions )
    
    auto sum = [](int x, int y){return x+y;};
    cout << sum(23,4) << endl;

    cout << [](int x){return x+12;}(2) << endl;

    vector <int> v= {2,3,4,67,8};

    // all_of
    cout << all_of(v.begin(),v.end(),[](int x){return x>0;}) << endl; // Checks all elements are positive
    cout << all_of(v.begin(),v.end(),[](int x){return x<100;}) << endl; // Checks all elements are <100
    cout << all_of(v.begin(),v.end(),[](int x){return x%2==0;}) << endl; // Checks all elements are even

    // any_of (koi bhi ek satisfy kar jaye given condition ko )
    cout << any_of(v.begin(),v.end(),[](int x){return x<0;}) << endl; // checks if any element is negative

    // none_of (tab true dega jab saare condition satisfy naa kre)
    cout << none_of(v.begin(),v.end(),[](int x){return x<0;}) << endl; // checks if none of the element is negative


    return 0;
}