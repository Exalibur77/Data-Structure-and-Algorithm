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

    // Constructors[no return type is given]

    // Here Constructor Overloading happened.
    Product(){
        cout << "Empty Constructor is called " << endl;
        selling_price = -1;// default value is set over there
        cost_price =-1;
        strcpy(name,"pencil");
    }

    Product(int id , int cost_price , char name[] , int selling_price){
        // Parameterized Constructor 
        cout << "Parameterized Constructor is called " << endl;

        
        // this->id = id; // or we can use
        (*this).id = id;
        this->cost_price = cost_price;
        strcpy(this->name , name);
        this->selling_price = selling_price;
    }

    // setters functions
   
    void set_CP(int val){
        cost_price = val;
    }

    void set_SP(int val){
        selling_price = val;
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
    char arr[]="sam";
    // Product A;
    // A.get_SP();
    // A.get_CP();

    Product obj(121,1000,arr,2000);
    obj.get_SP();
    obj.get_CP();



    return 0;
}