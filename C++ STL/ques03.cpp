#include<iostream>
#include<unordered_set>
#include<math.h>

using namespace std;

int main(){

    int t; cin >> t;

    while (t--)
    {
        int n,m;
        cin >> n >> m;
        unordered_set <long long int> s;
        
        for (int i = 0; i < (n+m); i++)
        {
            long long int val;
            cin >> val;
            if(i<n){
                s.insert(val);
            }
            else{
                auto it = s.find(val);

                if(it == s.end()){
                    cout << "NO" << endl;
                }
                else{
                    cout << "YES" << endl;
                }
            }
        }
        

    }
    



}