#include<iostream>
#include<vector>
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

Node * findMiddle(Node *&head){

    Node * slow = head;
    Node * fast = head->next;

    while(fast and fast->next){
        fast = fast->next->next;
        slow = slow->next;
    }

    return slow;

}

Node * reverse(Node *&head){

    Node * curr = head;
    Node * prev= NULL;
    Node * frwd = NULL;

    while(curr!=NULL){

        frwd = curr->next;
        curr ->next = prev;
        prev = curr;
        curr = frwd;

    }

    return prev;

}
// Optimised Approach 

// Time Complexity - O(N)
// Space Complexity - O(1)

bool checkPalindrome(Node *&head){

    if(head == NULL or head->next == NULL) return 1;

    // Step:1 Find middle node 
    Node * middle = findMiddle(head);

    // Step:2 Reverse List after middle;
    middle->next = reverse(middle->next);

    print(head);

    // Step:3 Compare both head data
    Node * head1 = head;
    Node * head2 = middle->next;

    while(head2!=NULL){

        if(head1->data != head2->data){
            cout << head1->data << endl;
            cout << head2->data << endl;
            return false;
        }

        head1= head1->next;
        head2= head2->next;
    }

    // Step:4 Reverse the reversed half to retain the sample input(Optional)
    middle->next = reverse(middle->next);
    print(head);

    return true;

   
}

int main(){

    Node * head = NULL;

    InsertAtHead(head , 10);
    InsertAtHead(head , 90);
    InsertAtHead(head , 990);
    // InsertAtHead(head , 990);
    InsertAtHead(head , 90);
    InsertAtHead(head ,10);

    print(head);

    cout << checkPalindrome(head);

    // print(head);


    return 0;
}