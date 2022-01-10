#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int marks(vector <int> v1){
    int marks=0;
    for (int i = 0; i < v1.size(); i++)
    {
        marks+=v1[i];
    }
    return marks;
}


bool compare(pair < string , vector<int> > s1 , pair < string , vector<int> > s2){

    if(marks(s1.second) == marks(s2.second)){
        return s1.first < s2.first;
    }

    return marks(s1.second) > marks(s2.second);

}


int main(){

    vector < pair < string , vector<int> > > student_marks ={

        {"Rohan",{10,20,3}},
        {"Prateek",{01,43,11}},
        {"Sanskar",{90,20,3}},
        {"Ritul",{40,02,11}},
        {"Rahul",{10,20,3}}
    };

    sort(student_marks.begin(),student_marks.end(),compare);

    for(auto s : student_marks){
        cout << s.first << " " << marks(s.second) << endl;
    }

    return 0;
}