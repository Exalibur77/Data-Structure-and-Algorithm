#include<iostream>
using namespace std;

/* Pass by Reference using:
    1. Reference Variable
    2. Pointer Variable
*/

// pass by referene 
void applyTax(int & income){

    income-=income*0.10;

}


int main(){

    int income;cin >> income;

    applyTax(income);

    cout << income << endl;
   
    return 0;
}