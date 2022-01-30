#include<iostream>
#include<cstring>
#include<string>
using namespace std;

class Product{

private:

    int id;
    int cost_price;
    char name[100];
    int selling_price;

public:
    // setters functions
   
    void set_CP(int val){
        cost_price = val;
    }

    void set_SP(int val){
        selling_price = val;
    }

    void set_name(char arr[]){

        strcpy(name,arr);

    }

    // Getter function

    void get_CP(){
        cout << "CP of " << name << " is , " << cost_price << endl;
    }

    void get_SP(){
        cout << "SP of " << name << " is , " << selling_price << endl;
    }

};

int main(){

    // a object A is created of the class Product
    Product A;
    char arr[]="sam";

    A.set_name(arr);
    A.set_CP(100);
    A.set_SP(200);

   A.get_CP();
   A.get_SP();



    return 0;
}