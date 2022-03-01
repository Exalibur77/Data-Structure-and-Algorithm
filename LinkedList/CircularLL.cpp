#include<iostream>
using namespace std;

class Node{

    public:
    int data;
    Node * next; 

    Node(int val){
        this->data = val;
        this->next = NULL;
    }

};

void insertNode(Node* &tail, int x){

    Node * newNode = new Node(x);

    // if linked list is empty
    if(tail == NULL){
        
        tail = newNode;
        newNode->next = tail;

        return;
    }

    newNode->next = tail->next; 
    tail->next = newNode;
    tail = newNode;


}

void print(Node * &tail){

    Node * ptr = tail;

    while(ptr->next != tail){
        cout << ptr->data << "--> " ;
        ptr = ptr->next;
    }
    cout << ptr->data << endl;


}


int main(){

    Node * tail = NULL;

    insertNode(tail,10);
    print(tail);
    insertNode(tail,100);
    print(tail);
    insertNode(tail,-11);
    print(tail);



    return 0;
}