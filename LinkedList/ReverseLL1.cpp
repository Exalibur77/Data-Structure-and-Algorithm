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

// Time Complexity - O(N) N is size of linked list
// Space Complexity - O(1) (No extra memory is used). 
void reverseLL(Node * &head){

    Node * prev = NULL;
    Node * curr = head;
    Node * forward;

    while(curr != NULL){

        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    head=prev;

}




int main(){

    Node * head = NULL;

    InsertAtHead(head , 10);
    InsertAtHead(head , 90);
    InsertAtHead(head , 990);
    InsertAtHead(head , 118);
    InsertAtHead(head ,111111);

    print(head);

    reverseLL(head);

    print(head);


    return 0;
}