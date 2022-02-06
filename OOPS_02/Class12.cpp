#include<iostream>
using namespace std;

// Friend Function of a class

class Complex{

    int a;
    int b;

    public:
        Complex(){}

        // using initilizer list
        Complex (int x, int y):a(x),b(y){}

        void printNum(){

            cout << a << " + " << b << "i" << endl;

        }

        // Not a member function of the given class and also cannot be accessed using the object.
        // Can be declared private or public.
        friend Complex sum(Complex &o1, Complex &o2);


};

// Now to avoid error we made this func sum as a friend function of the given class which can access to all the private and public data members and func of the class.

Complex sum(Complex &o1, Complex &o2){

    // It would give erro as we are using the private member for the object of the Complex class.
    Complex temp(o1.a+o2.a,o1.b+o2.b);

    return temp;

}


int main(){

    Complex obj1(12,4);
    Complex obj2(2,11);

    
    obj1.printNum();
    obj2.printNum();


    Complex res = sum(obj1,obj2);

    res.printNum();

    return 0;
}