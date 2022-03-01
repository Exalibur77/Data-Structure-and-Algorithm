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

int getLen(Node *&head){
    int len =0;
    Node * temp = head;

    while(temp != NULL){

        len++;
        temp = temp->next;

    }

    return len;
}
// Brute Force O(N)
Node * findMiddle1(Node *&head){

    int len = getLen(head);

    int mid = len/2;

    int i=0;
    Node * temp = head;

    while(i<mid){
        temp = temp->next;
        i++;
    }

    return temp;

}

// Using Fast and Slow pointer
Node * findMiddle2(Node * head){

    // if empty or single 
    if(head == NULL or head->next == NULL) return head;

    Node * slow = head;
    Node * fast = head->next;

    while(fast!= NULL){
        fast = fast->next;
        if(fast!=NULL) fast= fast->next;

        slow = slow->next;

    }

    return slow;

}

// more optimized than 2nd approach
Node * findMiddle3(Node * head){

    Node * slow = head;
    Node * fast = head;

    while(fast!=NULL and fast->next!=NULL){

        slow = slow->next;
        fast = fast->next->next;

    }

    return slow;

}

int main(){

    Node * head = NULL;

    InsertAtHead(head , 10);
    InsertAtHead(head , 90);
    InsertAtHead(head , 990);
    InsertAtHead(head , 118);
    InsertAtHead(head ,111111);

    print(head);

    Node * ans = findMiddle3(head);

    cout << ans->data << endl;

    return 0;
}