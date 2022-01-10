#include<iostream>
using namespace std;
// Problem is to read N strings and print the largest string.

int main(){

    int n;
    cin >> n;
    cin.get();// cin.ignore()
    // Just to prevent reading a \n by cin.getline()
    char str[1000];
    char temp[1000];
    int max_len=INT_MIN;

    while(n--){
        cin.getline(str,1000);
        int len=strlen(str);

        if(len>max_len){
            strcpy(temp,str);
            max_len=max(max_len,len);
        }
    }

    cout << temp << endl;
    cout << "Length of string => " << max_len << endl;



    return 0;
}