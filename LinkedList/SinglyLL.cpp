#include<bits/stdc++.h>
using namespace std;

// Singly Linked List

class Node{

    public:
    int data;
    Node * next; 

    Node(int val){
        this->data = val;
        this->next = NULL;
    }
    

};

void InsertAtHead(Node* &head , int x){

    // first create a new node to be inserted at head.

    Node * temp = new Node(x);
    temp->next = head;

    head = temp;

}

void InsertAtTail(Node* &head , int x){


    // first create a new node to be inserted at tail.
    Node * newNode = new Node(x);

    // if initally the head is NULL which means LL is empty then just assign head to the new node to be inserted.
    if(head == NULL){
        head = newNode;
        return;
    }
    
    Node * temp = head;

    while(temp->next != NULL){
        temp = temp->next;
    }

    temp->next = newNode;

}

void InsertAtPosition(Node* &head , int x ,int pos){

    // insert at head
    if(pos == 0){
        InsertAtHead(head,x);
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
    temp->next = newNode;

}

// deleting node of the specified node
void deleteNodePos(Node* &head , int pos){

    if(pos==0){
    // Special case
        Node * temp = head;
        head= head->next;
        
        delete temp;
        return;
    }


    Node *prev = NULL;
    Node *curr = head;

    int i=1;

    do{
        prev = curr;
        curr = curr->next;
        i++;
    }while(i <= pos);

    prev->next = curr->next;
    
    // memory free of the current node as it is of no use now.
    delete curr;


}

// deleting node of a specific value
void deleteNodeVal(Node* &head , int val){

    if(head->data == val){
        // delete head

        Node * temp = head;
        head = head->next ;
        delete temp;
        return;
    }

    bool isDeleted = false;
    Node *prev = NULL;
    Node *curr = head;


    while (true)
    {

        if(curr->data ==  val){
            isDeleted = true;
            break;
        }
        prev = curr;
        curr = curr->next;
  
        if(curr == NULL) break;
    }
    
    if(isDeleted == false){
        cout << "Node with value " << val << " is not present " << endl;
        return;
    }

    prev->next = curr->next;
    delete curr;



}



void print(Node * &head){

    // making a counter pointer to move forward

    Node * temp = head;

    while(temp != NULL){

        cout << temp->data << " --> ";
        temp = temp->next;

    }

    cout << " NULL" <<endl;


}




int main(){

    // Creating a object of class node in heap
    // Node * n1 = new Node(14);

    Node * head = NULL;

    print(head);

    InsertAtTail(head,12);

    print(head);

    InsertAtHead(head,1);

    print(head);
    
    InsertAtTail(head,99);

    print(head);

    InsertAtTail(head,-12);

    print(head);

    InsertAtPosition(head,111,3);

    print(head);

    deleteNodeVal(head,1000);

    print(head);
    return 0;
}