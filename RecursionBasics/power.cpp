#include<algorithm>
#include<iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

long long int power(int a, int b){

    if(b==0) return 1;

    if(b == 1) return a;

    long long int ans = power(a,b/2);

    // if b  is odd
    if((b&1) == 1){
        return 1ll*a*ans*ans;
    }

    return 1ll*ans*ans;



}

// This is linear approach O(b)
long long int power0(int a, int b){

    if(b==0) return 1;

    if(b == 1) return a;

    return 1ll*a*power0(a,b-1);

}


int main(){


    int a, b;
    cin >> a >> b;

    {
        auto start = high_resolution_clock::now();

        cout << power0(a,b) << endl;

        auto stop = high_resolution_clock::now();

        auto duration = duration_cast<microseconds>(stop - start);
  
        cout << "Time taken by function: "
         << duration.count() << " microseconds" << endl;
    }

    cout << "=======" << endl;
    {
        auto start = high_resolution_clock::now();

        cout << power(a,b) << endl;

        auto stop = high_resolution_clock::now();

        auto duration = duration_cast<microseconds>(stop - start);
  
        cout << "Time taken by function: "
         << duration.count() << " microseconds" << endl;
    }
    




    

    return 0;
}