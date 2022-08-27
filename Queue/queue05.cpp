#include<iostream>
#include"deque.h"
using namespace std;

int main(){

    deque dq(10);

    // cout << "Helo";

    dq.insertFront(10);
    dq.insertFront(1);
    dq.insertFront(-199);

    dq.insertEnd(1000);
    dq.insertEnd(199);
    dq.insertEnd(23230);

    cout << dq.size() << endl;

    cout << dq.getBack() << " " << dq.getFront() << endl;

    dq.popEnd();
    dq.popEnd();
    dq.popEnd();
    dq.popEnd();

    cout << dq.size() << endl;

    cout << dq.getBack() << " " << dq.getFront() << endl;


    return 0;
}