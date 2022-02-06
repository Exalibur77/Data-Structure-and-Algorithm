#include <iostream>
using namespace std;


class qwerty{

    // empty class

};



int main(){


    qwerty obj;

    // Empty class object also have a size of 1 byte even there is no data type or memory initilised. [Just to mark the presense of class]
    cout << sizeof(obj) << " " << endl;

    return 0;
}