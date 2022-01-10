#include<iostream>
using namespace std;

int linear_search(int arr[],int n,int key){

    for (int i = 0; i < n; i++)
    {
        if(arr[i]==key){
            return i;
        }
    }
    
    return -1;
}


int main(){

    int arr[]={12,3,5,45,2,65,66,9,8,44};
    int key;
    cout << "Enter the number to find: ";
    cin >> key;

    int n=sizeof(arr)/sizeof(arr[0]);

    int index=linear_search(arr,n,key);

    if(index!=-1){
        cout << key << " is present at the index " << index << endl;
    }
    else{
        cout << key << " is not present in the array" << endl;
    }

    return 0;
}