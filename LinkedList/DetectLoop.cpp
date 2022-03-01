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

    if(tail == NULL) tail = head;

    else{
        tail = tail->next;
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

// TC - O(N) and Space Complexity O(N)
bool isLoopPresent(Node *&head){

    unordered_map < Node* , bool > mp;

    Node * temp = head;

    while(temp!=NULL){
        
        // Already present
        if(mp[temp] == 1){
            cout << "Loop is present at value " << temp->data << endl;
            return true;
        }

        mp[temp] = 1;

        temp = temp->next;
    }


    return false;


}

// Using Floyd Loop Detection Algorithm 
// TC - O(N) and SC - O(1)
bool isLoopPresent1(Node * &head){

    if(head == NULL) return false;

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
            cout << slow->data << endl;
            return true;
        }


    }

    return 0;

}



int main(){

    Node * head = NULL;
    Node *tail = NULL;

    InsertAtHead(head ,tail, 10);
    InsertAtHead(head ,tail ,90);
    InsertAtHead(head ,tail ,990);
    InsertAtHead(head ,tail ,118);
    InsertAtHead(head ,tail ,111111);

    print(head);

    // tail is pointing one before the tail
    tail->next = head->next;

    if(isLoopPresent1(head)){
        cout << "Loop is Present" << endl;
    }

    else{
        cout << "Loop is not Present" << endl;
    }


    return 0;
}