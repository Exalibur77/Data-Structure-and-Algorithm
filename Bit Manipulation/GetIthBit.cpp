#include<iostream>
#include<math.h>
using namespace std;

int get_bit(int n,int pos){
    n=(n>>pos);
    return (n&1);
}

int get_bit01(int n, int pos){
    int mask = (1<<pos);

    return (n&mask) > 0 ? 1 : 0 ; 
}

void clear_bit (int &n, int pos){
    // If bit is 0 nothing get changed in n and it remains same.
    int mask = ~(1<<pos);

    n = (n&mask);
    return;
}

void set_bit (int &n , int pos){
    // if ith bit is 1 then taking or with does not affect it but if it is 0 then it get changed to 1.
    int mask = (1<<pos);

    n = (n|mask);
    return ;
}
// update the bit of n at pos with value v
void update_bit(int &n , int pos , int v){

    int bit = get_bit(n,pos);

    if(bit == v){return;}

    else{
        if(bit ==1){
            clear_bit(n,pos);
        }
        else{
            set_bit(n,pos);
        }
    }
    return;

}
// Alternate for update_bit

void update_bit01(int &n , int pos , int v){

    clear_bit(n,pos);

    int mask = (v<<pos);

    n = n|mask;

}

// Clear Last ith bits

void clearLastiBits(int &n , int i){
    
    // // Method 1(o(i))
    // for (int j = 0; j < i; j++)
    // {
    //     clear_bit(n,j);
    // }
    // return;


    // Method 2 O(1)

    int mask = (~0)<<i;
    // int mask = -1<<i;

    n = n&mask;
    return;

}


// Clear Bits in range

void clearBitsInRange(int &n , int i , int j){

    // Brute Force O(j-i+1)

    // for (int k = i; k <=j; k++)
    // {
    //     clear_bit(n,k);
    // }
    
    // return;


    // Method 2 O(1)

    int a = ((~0)<<(j+1));
    // int b = pow(2,i) -1; // int b = (1<<i) -1; 
    int b= ~((~0)<<i);
    int mask = a|b;

    n = n&mask;
}


int main(){
    // indexing of number here is from right to left
    int n ; cin >> n;
    // int pos; cin >> pos;
    int i,j; cin >> i >> j;
    // int bit = get_bit01(n,pos);

    // cout << bit << " is present at " << pos << " index of binary of " << n << endl;

    // clear_bit(n,pos);

    // set_bit(n,pos);

    // update_bit01(n,pos,0);

    // clearLastiBits(n,pos);

    clearBitsInRange(n,i,j);

    cout << n << endl;
    return 0;
}