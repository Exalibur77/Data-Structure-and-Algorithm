#include<iostream>
#include<vector>

// Doubt

using namespace std;
// Find the just smaller or equal to the given number in a sorted array .
int lowerbound(vector <int> a, int val){
    int n=a.size();

    if(a[0]>val){
        return -1;
    }
    
    for (int i = 0; i < n; i++)
    {
        if(a[i]==val){
            return a[i]; 
        }

        if(a[i]>val){
            return a[i-1];
        }
    }
    
    return 0;


}


int main(){

    vector <int> a(5);
    for (int i = 0; i < 5; i++)
    {
        cin >> a[i];
    }
    
    cout << lowerbound(a,4);

    return 0;
}