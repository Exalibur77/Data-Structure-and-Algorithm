#include<iostream>
using namespace std;

// Friend Function of a class in another class
// And Friend Class

class Complex; // forward declaration of the class complex

class Calc{

    public:

        int sumReal(Complex &o1, Complex &o2);

        int sumComp(Complex &o1, Complex &o2);


};

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

        // individually adding the function of class Calc as friend of complex
        // friend int Calc :: sumReal(Complex &o1, Complex &o2);
        // friend int Calc :: sumComp(Complex &o1, Complex &o2);

        // Aliter: Add the whole class Calc as a friend of Complex

        friend class Calc;

};



int Calc::sumReal(Complex &o1, Complex &o2){
    return o1.a+o2.a;
}
int Calc::sumComp(Complex &o1, Complex &o2){
    return o1.b+o2.b;
}


int main(){

    Complex c1(12,4);
    Complex c2(1,-1);

    Calc obj;

    int res = obj.sumReal(c1,c2);

    cout << res << endl;

    int resc = obj.sumComp(c1,c2);

    cout << resc << endl;


}