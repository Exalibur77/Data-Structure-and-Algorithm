#include<iostream>
#include<cstring>
#include<string>
using namespace std;

// Deep Copy and Shallow Copy of an object

/*
    Shallow Copy is just copying each obj member to another obj {whether it is dynamically allocated memory}

    Deep Copy , We need to define our own copy contructor only if an object has pointer to dynamically allocaated memory.


*/

class Product{

private:

    int id;
    int cost_price;
    char *name;
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

    Product(int id , int cost_price , char *name , int selling_price){
        // Parameterized Constructor 
        cout << "Parameterized Constructor is called " << endl;

        
        // this->id = id; // or we can use
        (*this).id = id;
        this->cost_price = cost_price;
        
        // Allocating name memopry in heap
        this->name = new char[strlen(name)+1];
        strcpy(this->name,name);
        this->selling_price = selling_price;
    }

    // copy Constructor it is predefined already.

    // making userdefined copy constructor

    Product(const Product &X){
        id = X.id;
        cost_price = X.cost_price;
        selling_price = X.selling_price;
        
        // making a seperate heap memory for the second object
        name = new char[strlen(X.name)+1];
        strcpy(this->name,X.name);

    }


    // setters functions
   
    void set_CP(int val){
        cost_price = val;
    }

    void set_SP(int val){
        selling_price = val;
    }

    void set_name(char *name){
        strcpy(this->name,name);
    }

    // Getter function

    void get_CP(){
        cout << "CP of " << name << " is , " << cost_price << endl;
    }

    void get_SP(){
        cout << "SP of " << name << " is , " << selling_price << endl;
    }

    void get_details(){

        cout << "CP => " << cost_price << endl;
        cout << "SP => " << selling_price << endl;
        cout << "ID => " << id << endl;
        cout << "Name => " << name << endl;
        cout << "==========================" << endl;
    }

    // Destructor is always called by default at the end of object but you should define a user defined destructor to delete dynamically allocated memory
    ~Product(){
        cout << "Destructor is called " << name << endl;

        delete []name;
        name = NULL;
    }

};

int main(){

    char arr[]="sam";

    Product obj(121,1000,arr,2000);
    Product obj1(obj);

    obj1.set_name("raju");

    // This created a deep copy an hence changing the name of obj1 will not changes the name of the obj.

    obj.get_details();

    // or
    // Product obj1 = obj;

    obj1.get_details();

    return 0;
}