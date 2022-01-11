#include<iostream>
#include<string>
using namespace std;

// 2021 should be printed as two zero two one recusrively

void numSpell(int n, string map[]){

    if(n==0){
        return;
    }

    numSpell(n/10,map);

    int rem = n%10;

    cout << map[rem] << " ";

}




int main(){

    string map[]={"zero","one","two","three","four","five","six","seven","eight","nine"};

    int n;
    cin >> n;

    numSpell(n,map);
    cout << endl;

    return 0;
}