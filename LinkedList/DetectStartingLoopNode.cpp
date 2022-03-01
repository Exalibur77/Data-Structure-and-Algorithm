#include<iostream>
#include<unordered_map>
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

void InsertAtHead(Node* &head , Node* &tail, int x){

    // first create a new node to be inserted at head.
    Node * temp = new Node(x);

    if(head == NULL){
        head = temp;
        tail = temp; 
        return;
    }

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

// 
Node* floydDetectLoop(Node * &head){

    if(head == NULL) return NULL;

    Node * slow = head;
    Node * fast = head;

    while(slow!= NULL and fast!= NULL){

        fast = fast->next;
        if(fast!=NULL){
            fast = fast->next;
        }
        slow = slow->next;

        // fast and slow can meet each other at any position in  the whole loop
        if(fast == slow){
            
            return slow;
        }


    }

    return NULL;

}

Node * detectStart(Node *&head){

    if(head == NULL) return NULL;

    Node * intersect = floydDetectLoop(head);

    if(intersect == NULL) return NULL; // if no loop get detected

    Node * slow = head;

    while(slow != intersect){
        slow = slow->next;
        intersect = intersect->next;
    } 

    return slow; // or intersect

}

int main(){

    Node * head = NULL;
    Node *tail = NULL;

    InsertAtHead(head ,tail, 10);
    InsertAtHead(head ,tail ,90);
    InsertAtHead(head ,tail ,990);
    InsertAtHead(head ,tail ,118);
    InsertAtHead(head ,tail ,23);
    InsertAtHead(head ,tail ,18);
    InsertAtHead(head ,tail ,91);
    InsertAtHead(head ,tail ,111111);

    print(head);
    cout << tail->data << endl;
    tail->next = head->next->next;

    cout << floydDetectLoop(head)->data << endl;
    cout << detectStart(head)->data << endl;

    return 0;
}