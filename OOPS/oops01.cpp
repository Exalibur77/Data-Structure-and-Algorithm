#include<iostream>
#include<string>
using namespace std;

class Product{

private:

    int id;
    int cost;

public:

    string name;
    string colour;

};

int main(){

    // a object A is created of the class Product
    Product A;
    cin >> A.name;
    cin >> A.colour;

    cout << "Name => " << A.name << endl;
    cout << "Colour => " << A.colour << endl; 



    return 0;
}