#include<iostream>
using namespace std;

/*
    // 1byte + 3byte padding
    char a | cell padding
    ..... int id......... // 4 byte

*/

class Person{
private:
    char grade;
public:
    int id;

    void setGrade(char ch){
        grade = ch;
    }

    void getGrade(){
        cout << "Grade => " << grade << endl;
    }

};

int main(){

    Person sam;

    sam.id = 99;

    // HERE SIZE IS NOT 1+4 = 5 , padding and greedy alignment concept is used

    cout << sizeof(sam) << endl;

    sam.setGrade('A');

    cout << "Id ==> "  << sam.id << endl;
    sam.getGrade();




    return 0;
}