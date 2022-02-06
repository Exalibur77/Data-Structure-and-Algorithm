#include <iostream>
using namespace std;

class base{

    private:
    int x;

    protected:
    int y;

    public:
    int z;

};

class child : private base{


    public:
    
    // cannot set x as x is private in the base class as it is unaccessible
    // void setX(int x){
    //     this->x = x;
    // }

    void setY(int y){ 
        this->y = y;
    }
    void setZ(int z){
        this->z = z;
    }

    // cannot get x aswell because x is unaccesible for its child class.

    // int getX(){
    //     return x;
    // }

    int getY(){
        return y;
    }

    int getZ(){
        return z;
    }

};





int main(){


    child obj;

    // obj.setX();

    obj.setY(100);

    obj.setZ(90);

    cout << obj.getY() << endl;
    cout << obj.getZ() << endl;





    return 0;
}