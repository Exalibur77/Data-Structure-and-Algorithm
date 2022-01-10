#include<iostream>
// #include<math.h>
using namespace std;

int fast_exp(int a, int b){
    
    int ans=1;

    // Log(N) becasue the  number of set bits in a given number <= logn +1.
    while (b > 0)
    {
        int bit = (b&1);

        if(bit == 1){
            ans=ans * a;
        }

        a= a*a;
        b = (b>>1);
    }
    
    return ans;
}

int main(){

    int a; int b;
    cin >> a >> b;
    cout << "a^b => " << fast_exp(a,b) << endl;


    return 0;
}