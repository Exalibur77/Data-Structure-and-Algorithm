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

// Naive Approach 

// Time Complexity - O(N)
// Space Complexity - O(N)

bool checkPalindrome(Node *&head){

    if(head == NULL or head->next == NULL) return 1;

    vector <int> arr;

    Node * temp = head;

    while(temp!=NULL){
        arr.push_back(temp->data);
        temp = temp->next;
    }

    int s=0;
    int e=arr.size()-1;

    while(s<e){
        if(arr[s++]!=arr[e--]) return 0;
    }

    return 1;

}

int main(){

    Node * head = NULL;

    InsertAtHead(head , 10);
    InsertAtHead(head , 90);
    InsertAtHead(head , 990);
    InsertAtHead(head , 90);
    InsertAtHead(head ,10);

    print(head);

    cout << checkPalindrome(head);


    return 0;
}