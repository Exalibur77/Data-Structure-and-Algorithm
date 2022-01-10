#include<iostream>
using namespace std;

int main(){

    // Character 2D Array Initilization

    // char arr[][10]={{'a','b','c','d','\0'},{'q','w','e','r','t','y','\0'}};
    // char ch[][10]={"abc","qwerty","hello"};

    // cout << arr[0] << endl;
    // cout << arr[1] << endl;
    // cout << ch[0] << endl;
    // cout << ch[1] << endl;
    // cout << ch[2] << endl;

    // Inputting a 2D Character array from user.

    int n; cin >> n;cin.ignore();

    char a[100][100];

    for (int i = 0; i < n; i++)
    {
        cin.getline(a[i],100);
    }
    
    cout << "=================================" << endl;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < strlen(a[i]); j++)
        {
            cout << a[i][j] << " ";
        }// or cout << a[i] << endl;
        
        cout << endl;
    }
    


}