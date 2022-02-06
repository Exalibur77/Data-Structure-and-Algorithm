#include<iostream>
using namespace std;

// Operator Overloading


class Complex{

    private:
        int a,b;

    public:
        Complex(){}

        Complex(int a, int b): a(a),b(b){}

        void showData(){
            cout << a << " + i" <<b << endl;
        }

        Complex& operator+(const Complex &obj){

            a+=obj.a;
            b+=obj.b;

            return *this;
        }

        Complex operator-(){

            Complex temp;

            temp.a = -1*a;
            temp.b = -1*b;

            return temp;
        }

};


int main(){

    Complex obj1(1,4);
    Complex obj2(2,5);

    obj1.showData();
    obj2.showData();

    // Overloading binary operator left is called object

    // obj1= obj1.operator+(obj2); // or
    obj1 = obj1+obj2;

    // Uranary operator , there is only one caller object

    // obj2 = obj1.operator-() // or
    obj2 = -obj1;


    obj1.showData();
    obj2.showData();

    return 0;

}