#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Time Complexity O(n) + Space Complexity O(n)
vector<int> kRotate(vector<int> a, int k){
    // your code  goes here

    int n=a.size();
    vector <int> temp(a);

    k=k%n;

    for (int i = 0; i < n; i++)
    {
        int index=(i+k)%n;
        a[index]=temp[i];
    }
    
    return a;
    
}

// Time Complexity O(k(max)*n) = O(n^2)
vector<int> kRotate1(vector<int> a, int k){
    // your code  goes here

    int n=a.size();

    k=k%n;

    for (int i = 0; i < k; i++)
    {
        int s=0;
        int e=n-1;

        while(s<e){
            swap(a[s],a[e]);
            s++;
        }
    }
    
    return a;
    
}


// Time Complexity O(n) 
vector<int> kRotate2(vector<int> a, int k){
    // your code  goes here

    int n=a.size();

    k=k%n;

    k=n-k;
    if(k==0){
        return a;
    }
    // using left rotate reversal algorithm
    reverse(a.begin(),a.begin()+k);
    reverse(a.begin()+k,a.end());
    reverse(a.begin(),a.end());
    
    return a;
    
}




int main(){
    int n; cin >> n;
    vector<int> vect1(n);
    
    for (int i = 0; i < n; i++)
    {
        cin >> vect1[i];
    }
    int k;
    cout << "Number of Rotation : " ;cin >> k;

    vector<int> ans=kRotate2(vect1,k);

    for(int i=0; i<n ; i++){
        cout << ans[i] << " ";
    }
    
    cout << endl;
    return 0;
}