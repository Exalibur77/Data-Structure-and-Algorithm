#include<iostream>
using namespace std;

// Reversal of a doubly linked list

class Node{

    public:
    int data;
    Node * prev;
    Node * next;

    Node(int d){
        data = d;
        prev = NULL;
        next = NULL;
    }


};

void print(Node * &head){

    Node * temp = head;

    while(temp != NULL){

        cout << temp->data << " --> ";
        temp = temp->next;

    }

    cout << " NULL" << endl;
}


void insertAtHead(Node *&head, int d){

    // creating a new node
    Node *newNode = new Node(d);

    newNode->next = head;

    // accessing previous will give error
    if(head == NULL) {
        head = newNode;
        return;
    }

    head->prev = newNode;
    head = newNode;
}


void insertAtTail(Node *&head , int d){

    // If empty
    if(head == NULL){
        insertAtHead(head,d);
        return;
    }

    // creating a new node
    Node *newNode = new Node(d);

    Node *temp = head;

    while(temp->next != NULL){
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;

}

// Iterative Reverse
void reverse(Node *&head){

    if(head == NULL or head->next==NULL) return;

    Node * back = NULL;
    Node * frwd = NULL;
    Node * curr = head;

    while(curr!=NULL){
        frwd = curr->next;
        curr->next = back;
        curr->prev = frwd;

        back = curr;
        curr = frwd;
    }


    head = back;

}

// Recursively Approach1 

void reverseRecur(Node *&head , Node *curr, Node *back){

    // base case
    if(curr == NULL){
        head = back;
        return;
    }

    Node * frwd = curr->next;
    curr->next = back;
    curr->prev = frwd;

    reverseRecur(head,frwd,curr);

}

Node * reverseRecur2(Node * head){

    if(head == NULL or head->next == NULL){
        return head;
    }

    Node * chotaHead = reverseRecur2(head->next);

    head->next->next = head;
    head->prev= head->next;
    head->next = NULL;

    return chotaHead;

}

int main(){


    Node * head = NULL;

    insertAtTail(head,19);
    insertAtTail(head,1);
    insertAtTail(head,9);
    insertAtTail(head,2319);
    insertAtTail(head,8473);
    insertAtTail(head,83);

    print(head);

    // reverseRecur(head,head,NULL);

    Node * newHead = reverseRecur2(head);

    print(newHead);


}