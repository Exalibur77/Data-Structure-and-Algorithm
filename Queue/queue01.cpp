#include<iostream>
#include<queue>

using namespace std;

// STL declaartion of queue
int main(){

    queue <int> q;

    q.push(1);
    q.push(13);
    q.push(11);
    q.push(41);

    cout << q.size() << endl;

    cout << q.front() << endl;

    q.pop();

    cout << q.front() << endl;

    q.pop();
    q.pop();
    q.pop();

    if(q.empty()){
        cout << "Queue is Empty" << endl;
    }



    return 0;
}