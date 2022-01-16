#include<iostream>
#include<vector>
using namespace std;

// Search In a Sorted Rotated Array without finding out the pivot index.

int rotated_search(vector <int>& arr , int key){
    int n = arr.size();

    int s=0;
    int e=n-1;

    int mid;

    while(s<=e){

        mid =(s+e)/2;

        if(arr[mid] == key){
            return mid;
        }

        // 2 cases (line1 or line 2) Applying Bineary Search in both lines

        else if(arr[s] <= arr[mid]){// line1

            // sorted part(s,mid)
            if(key>= arr[s] and key<= arr[mid]){
                e = mid-1;
            }

            else{
                s = mid+1;
            }


        }

        else{// line2

            // sorted part(mid,e)

            if(key>=arr[mid] and key<=arr[e]){
                s=mid+1;
            }

            else{
                e=mid-1;
            }

        }

    }


    return -1;

}




int main(){

    vector <int> v{7,9,10,13,-1,3,5,6};

    int key;
    cin >> key;

    cout << rotated_search(v,key) << endl;






    return 0;
}