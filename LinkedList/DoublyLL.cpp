#include<iostream>
using namespace std;

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

int getLen(Node *&head){
    int len =0;
    Node * temp = head;

    while(temp != NULL){

        len++;
        temp = temp->next;

    }

    return len;
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



void insertAtPosition(Node* &head , int x ,int pos){

    // insert at head
    if(pos == 0){
        insertAtHead(head,x);
        return;
    }

    // first create a new node to be inserted .
    Node * newNode = new Node(x);

    Node * temp = head;

    int i=1;
    while(i != pos){
        temp = temp->next;
        i++;
    }

    newNode->next = temp->next;

    // To check for the last node
    if(temp->next != NULL){
        (temp->next)->prev = newNode;
    }

    temp->next = newNode;
    newNode ->prev = temp;

}

// Deleting node at a given index
void deleteNode(Node *&head, int pos){

    if(pos == 0){

        // deleting the head node.
        Node *ptr = head;

        ptr->next->prev = NULL;
        head = ptr->next;

        delete ptr;
        return;
    }

    Node *p = NULL;
    Node *curr = head;

    int i=1;

    do{
        p = curr;
        curr = curr->next;
        i++;
    }while(i <= pos);

    if(curr->next == NULL){
        p->next = NULL;
        return;
    }

    p->next = curr->next;
    curr->next->prev = p; 
    
    // memory free of the current node as it is of no use now.
    delete curr;



}


int main(){

    // Node *node1 = new Node(10);

    Node * head = NULL;

    print(head);
    // cout << getLen(head) << endl;

    insertAtHead(head,199);
    print(head);
    // cout << getLen(head) << endl;

    insertAtHead(head,-9);
    print(head);
    // cout << getLen(head) << endl;

    insertAtTail(head,-900);
    print(head);
    // cout << getLen(head) << endl;

    insertAtTail(head,7871);
    print(head);
    // cout << getLen(head) << endl;

    insertAtPosition(head,1111,4);
    print(head);

    deleteNode(head,0);
    print(head);

    deleteNode(head,3);
    print(head);


}