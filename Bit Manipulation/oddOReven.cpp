#include<iostream>
using namespace std;

bool is_odd0(int x){
    if(x%2 !=0 ){
        return 1;
    }
    return 0;
}

bool is_odd1(int x){
    int last_bit = x&1;
    if( last_bit !=0 ){
        return 1;
    }
    return 0;
}



int main(){

    int x; cin >> x;

    if(is_odd1(x)){
        cout << x << " is odd" << endl;
    }
    else{
        cout << x << " is even." << endl;
    }



    return 0;
}