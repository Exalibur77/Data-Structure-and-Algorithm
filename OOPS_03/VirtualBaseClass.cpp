#include<iostream>
using namespace std;

// Virtual Base Class
class Student{
    protected:
    int roll_no;

    public:

        void setNum(int x){
            roll_no = x;
        }

        void printNum(){

            cout << "Your Roll Number --> " << roll_no << endl;

        }


};

class Test : virtual public Student{
    protected:
    float maths,science;

    public:

        void setMarks(float x , float y){
            maths = x;
            science = y;
        }

        void printMarks(){

            cout << "Maths Marks => " << maths << endl; 
            cout << "Science Marks => " << science << endl; 

        }

};

class Sports : public virtual Student{

    protected:
    float score;

    public:

    void setScore(float x){
        score = x;
    }

    void printScore(){
        cout << "Sport's Score => " << score << endl;
    }


};


class Result: public Test, public Sports{

    private:
    float total;

    public:
        void displayTotal(){

            total = maths+science+score;

            printNum();
            printMarks();
            printScore();

            cout << "Your Total Score => " << total << endl;
        }


};


int main(){

    Result sam;

    int x;
    cout << "Enter your Roll Number : "; cin >> x;
    sam.setNum(x);

    float m,s;
    cout << "Marks Obtained in Maths and Science : "; cin >> m >> s;
    sam.setMarks(m,s);

    float sp;
    cout << "Marks Obtained in Sports : "; cin >> sp;
    sam.setScore(sp);

    sam.displayTotal();
 

    return 0;
}