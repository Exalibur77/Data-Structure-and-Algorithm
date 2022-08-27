#include<iostream>
#include<queue>

using namespace std;

int main(){

    // STL of doubly ended queue
    deque <int> dq;

    dq.push_back(1);
    dq.push_back(2);
    dq.push_back(3);
    dq.push_back(4);

    dq.push_front(10);
    dq.push_front(9);
    dq.push_front(8);
    dq.push_front(7);


    while(!dq.empty()){
        cout << dq.front() << endl;
        dq.pop_front();
    }

    return 0;
}