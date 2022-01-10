#include<iostream>
#include<math.h>
using namespace std;

int countSetbits(int n){
    // number of bits of a given number n is logn

    /*
    
        ex n = 15(1111)

        log2(15) close to 3

        No of bits = logn +1 = 3+1 = 4
    
    
    */
    int cnt=0;

    // O(logn)
    while(n!=0){

        if(n&1){// if last bit is 1
            cnt ++;
        }
        n = n/2; // or n = n>>1;

    }

    return cnt;
}

// O(no of sets bits)
int countSetbits01(int n){
    int ans=0;
    // removes the last set bit from the given number.
    while(n!=0){
        n= n&(n-1);
        ans++;
    }
    return ans;
}


int main(){

    cout << countSetbits(1) << endl;
    cout << countSetbits01(15) << endl;

    return 0;
}