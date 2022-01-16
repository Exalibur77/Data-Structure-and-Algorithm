#include<iostream>
#include<vector>
using namespace std;

int solve(vector<int> v , int s, int e , int key){
     
     // base case
     if(s>e){
         return -1;
     }
     
     int mid = (s+e)/2;
     
     if(v[mid] ==key){
         return mid;
     }
     
     else if(v[mid] > key){
         return solve(v,s,mid-1,key);
     }
     
     return solve(v,mid+1,e,key);
     
 } 
  
  
 
int binarySearch(vector<int> v, int x)
{
    // your code goes here
    
    int ans = solve(v,0,v.size()-1,x);
    return ans;
    
}

int main(){

    vector <int> arr{2,3,6,10,11,100,392,900};
    int key; cin >> key;
    cout << binarySearch(arr,key) << endl;


    return 0;
}