#include<iostream>
#include<vector>
using namespace std;

void printVec(vector < pair < int,int> > &vp){

    for (int i = 0; i < vp.size(); i++)
    {
        cout << vp[i].first << " " << vp[i].second << endl;
    }

}

int main(){

    vector < pair < int,int> > vp;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int x,y;
        cin >> x >> y;

        vp.push_back({x,y});
    }
    cout << endl;

    // printVec(vp);// using variable

    // printing vector using iterator

    // vector < pair < int,int> > :: iterator it;
    

    // for (it=vp.begin() ; it!= vp.end(); it++)
    // {
    //     cout << (*it).first << " " << (*it).second << endl;
    //     //or 
    //     cout << it->first << " , " << it->second << endl;
    // }
    
    // using auto keyword
    for (auto it=vp.begin() ; it!= vp.end(); it++)
    {
        cout << (*it).first << " " << (*it).second << endl;
        //or 
        cout << it->first << " , " << it->second << endl;
    }

    // using for each loop for printing vector of pairs

    for(auto p : vp){// p(copy) is a vector name in vp
        cout << p.first << " " << p.second << endl;
    }



    return 0;
}