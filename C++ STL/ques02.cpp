#include<set>
#include<iostream>
using namespace std;

int main(){

    int t;cin >> t;
    while (t--)
    {
        set <string> s;
        int n; cin >> n;

        for (int i = 0; i < n; i++)
        {
            string str; cin >> str;
            s.insert(str);
        }
        
        for(auto &str : s){
            cout << str << endl;
        }
    }
    
    
    return 0;
}