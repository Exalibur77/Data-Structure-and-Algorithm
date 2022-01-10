#include<iostream>
#include<vector>
using namespace std;

int main(){

    int n;cin >> n;
    vector <char> ch(n);
    
    cout << "Enter character array" << endl;

    for (int i = 0; i < n; i++)
    {
        cin >> ch[i];
    }
    // Sorts according to the ascii value of each character.
    sort(ch.begin(),ch.end());

    for (int i = 0; i < n; i++)
    {
        cout <<  ch[i] << " ";
    }
    cout << endl;

    return 0;
}