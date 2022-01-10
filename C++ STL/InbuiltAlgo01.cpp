#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;

int main(){

    int n; cin >> n;
    vector <int> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    
    cout << "Min Element => " << *min_element(v.begin(),v.end()) << endl;
    cout << "Max Element => " << *max_element(v.begin(),v.end()) << endl;

    int sum = accumulate(v.begin(),v.end(),0);
    int cnt = count(v.begin(),v.end(),2); // counts the number of 2 in the given range

    cout << sum << endl;
    cout << cnt << endl;

    reverse(v.begin(),v.end());

    for(auto &val : v){
        cout << val << " ";
    }
    cout << endl;
    
    return 0;
}