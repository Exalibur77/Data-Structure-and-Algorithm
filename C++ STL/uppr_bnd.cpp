#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int UpperBound(vector <int> arr , int key){

    int n = arr.size();
    int s=0;
    int e=n-1;
    int mid;
    int ans =-1;

    while(s<=e){

        mid = s+ (e-s)/2;

        if(arr[mid] < key){
            s=mid+1;
        }

        else{
            ans = mid;
            e = mid-1;
        }

    }
    cout << "Present at index => " << ans << endl;
    return arr[ans];

}


// Lower Bound and Upper Bound Function for sorted arrays
int main(){

    vector <int> v;
    int n;cin >> n;

    int val;
    for (int i = 0; i < n; i++)
    {
        cin >> val;
        v.push_back(val);
    }
    
    //Sort 
    sort(v.begin(),v.end());

    for(auto &val : v){
        cout << val << " ";
    }
    cout << endl;
    // Lower Bound is the iterator either pointing to the given key or the next element (if given key is not present)
    // auto ptr = lower_bound(v.begin(),v.end(),7);
    // cout << "Position => " << ptr - v.begin() << " " << *ptr << endl;
    
    // Upper Bound is the iterator pointing to the value just greater than the given key.
    auto ptr1 = upper_bound(v.begin(),v.end(),7);
    cout << "Position => " << ptr1 - v.begin() << " " << *ptr1 << endl;


    cout << UpperBound(v,7) << endl;



    return 0;
}