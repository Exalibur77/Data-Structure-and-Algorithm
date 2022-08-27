#include<iostream>
#include"circularQueue.h"
using namespace std;

int main(){

    int n; cin >> n;

    CircularQueue q(n);

    cout << q.enqueue(12) << endl;
    cout << q.enqueue(2)  << endl;
    cout << q.enqueue(1) << endl;
    cout << q.enqueue(1212) << endl;
    cout << q.enqueue(1200) << endl;
    cout << q.enqueue(-12) << endl;

    cout << q.size() << endl;

    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;

    cout << q.enqueue(1212) << endl;
    cout << q.enqueue(1200) << endl;
    cout << q.enqueue(-12) << endl;

    cout << q.getFront() << endl;
    cout << q.size() << endl;


    return 0;
}
