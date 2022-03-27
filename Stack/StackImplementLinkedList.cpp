#include<iostream>
using namespace std;

class Node{

    public:
    Node *next;
    int data;

    Node(int x){
        data = x;
        next = NULL;
    }

};

// All operation are of O(1)
class stack{

    private:

    Node * head;
    int size;

    public:

    stack(){
        head = NULL;
        size =0;
    }


    void push(int x){

        Node * newNode = new Node(x);

        // insertAtHead;

        if(head == NULL){
            head = newNode;
            size++;
        }

        else{
            newNode->next = head;
            head = newNode;
            size++;
        }


    }

    void pop(){

        if(head == NULL) {
            cout << "Empty Linked List" << endl;
            return;
        }

        else{
            Node * temp = head;

            head = head->next;

            delete temp;

            size--;
        }

    }

    int len(){
        return size;
    }

    int top(){
        
        if(head == NULL) return -1;

        return head->data;

    }

    bool empty(){
        return size==0;
    }

};


int main(){

    stack st;

    st.push(9);    
    st.push(19);    
    st.push(111119);    
    st.push(90);    

    cout << st.len() << endl;

    st.pop();

    cout << st.len() << endl;

    cout << st.top() << endl;

    cout << st.empty() << endl;

    st.pop();
    st.pop();
    st.pop();
    st.pop();

    cout << st.empty() << endl;
    cout << st.top() << endl;




    return 0;
}