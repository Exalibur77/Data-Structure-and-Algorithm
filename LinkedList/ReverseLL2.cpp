#include<iostream>
using namespace std;

// =================== RECURSIVE WAY TO REVERSE A LINKED LIST ======================

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
// Space Complexity - O(N) (Recursive Calls as N stages would be made). 

// Using head recursion
// void reverseLL(Node * &head , Node *curr , Node * prev){

//     // Base Case
//     if(curr == NULL){
//         head = prev;
//         return;
//     }
    
//     // Solve for 1 case
//     Node * frwd = curr->next;

//     reverseLL(head,frwd,curr);

//     curr->next = prev;

// }

// Using Tail Recursion 
void reverseLL(Node * &head , Node *curr , Node * prev){

    // Base Case
    if(curr == NULL){
        head = prev;
        return;
    }
    
    // Solve for 1 case
    Node * frwd = curr->next;
    curr->next = prev;

    reverseLL(head,frwd,curr);
}




int main(){

    Node * head = NULL;

    InsertAtHead(head , 10);
    InsertAtHead(head , 90);
    InsertAtHead(head , 990);
    InsertAtHead(head , 118);
    InsertAtHead(head ,111111);

    print(head);

    reverseLL(head,head,NULL);

    print(head);


    return 0;
}