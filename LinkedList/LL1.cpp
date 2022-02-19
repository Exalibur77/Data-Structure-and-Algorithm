#include<bits/stdc++.h>
using namespace std;

// Singly Linked List

class Node{

    public:
    int data;
    Node * next; // Next is a pointer of a next node so the type is also a node.

    Node(int val){
        this->data = val;
        this->next = NULL;
    }

};

int main(){

    // Creating a object of class node in heap
    Node * n1 = new Node;

    cout << n1->data << endl;
    cout << n1->next << endl;

    Node * n2 = new Node(10);

    cout << n2->data << endl;
    cout << n2->next << endl;


    return 0;
}