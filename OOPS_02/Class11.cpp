#include<iostream>
using namespace std;

// Overloading ++,-- operator

class Integer{

    private:
    int x;

    public:
    
    Integer(){}

    // here no need of this operator
    Integer(int x): x(x){}

    void getData(){
        cout << "x => " << x << endl;
    }


    Integer operator++(){

        Integer temp;
        temp.x = ++x;

        return temp;
    }

    // Post Increment
    Integer operator++(int){

        Integer temp;
        temp.x= x++;

        return temp;

    }



};




int main(){


    Integer obj(2);
    obj.getData();


    // obj.operator++()

    Integer obj1 = ++obj;// Pre Increment
    obj1.getData();
    obj.getData();

    // obj.operator++(int) // post Increment (this int is to differenntiate bet post and preincrement function)

    Integer obj2 = obj++; // Post Increment
    obj2.getData();
    obj.getData();
    


    return 0;
}