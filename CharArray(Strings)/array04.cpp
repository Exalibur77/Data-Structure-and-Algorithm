#include<iostream>
using namespace std;

int main(){

    char sentence[1000];

    // cin.getline(char_array,max_length,delimeter) 
    // delimeter is by default '\n'

    // cin.getline(sentence,1000);
    // cout << sentence << endl;

    cin.getline(sentence,1000,'.');
    cout << sentence << endl;

    return 0;
}