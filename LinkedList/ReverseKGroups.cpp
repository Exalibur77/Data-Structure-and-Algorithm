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

void InsertAtHead(Node* &head , int x){

    // first create a new node to be inserted at head.

    Node * temp = new Node(x);
    temp->next = head;

    head = temp;

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

Node * reverseK(Node *head , int k){

    if(head == NULL) return NULL;

    // Reverse First K nodes
    int cnt=0;

    Node*curr = head;
    Node*prev = NULL;
    Node *frwd = NULL;

    while(curr!= NULL and cnt<k){

        frwd= curr->next;
        curr->next = prev;
        prev= curr;
        curr = frwd;
        cnt++;
    }

    // Recursive Call for next k nodes from (frwd node as head)

    if(frwd!=NULL){
        head->next = reverseK(frwd,k); // joining it with the head of the current state of reversed k nodes
    }

    return prev;



}



int main(){

    Node * head = NULL;

    InsertAtHead(head , 10);
    InsertAtHead(head , 90);
    InsertAtHead(head , 990);
    InsertAtHead(head , 118);
    InsertAtHead(head ,111111);
    InsertAtHead(head ,11);
    InsertAtHead(head ,98);
    InsertAtHead(head ,123);

    print(head);

    Node * newHead = reverseK(head,5);

    print(newHead);


    return 0;
}