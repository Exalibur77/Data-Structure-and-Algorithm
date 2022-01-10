
#include <iostream>
#include<algorithm>
using namespace std;

int lowerBound(int *arr , int n , int key){

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

int main() {
	// your code goes here


    // Lower Bound (just greater than the given key)


    int arr[]={1,3,4,4,5,7,10,13,20};

    int n = 9;

    cout << lowerBound(arr,n,10) << endl;
    cout << "Present at index => " << lower_bound(arr,arr+n,10) - arr << endl;
    cout << *lower_bound(arr,arr+n,10) << endl;

	return 0;
}

