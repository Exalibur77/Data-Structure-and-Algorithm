#include<iostream>
#include<queue>
using namespace std;


template <typename T>
class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
};

class cmp{

    public:
        bool operator () (Node<int> * a , Node <int> *b){
            return a->data > b->data;
        }

};

// T.C - O( n*k logK)
// S.C - O(K) only for minHeap

Node<int>* mergeKLists(vector<Node<int>*> &listArray)
{

    int k = listArray.size();

    if(k == 0) return NULL;

    priority_queue < Node<int>* , vector<Node<int>*> , cmp > pq;

    // Step 1 . Make a minHeap of all the first element of the list

    for(int i=0 ; i<k ; i++){

        // if the list is non empty
        if(listArray[i] != NULL){

            pq.push(listArray[i]);

        }

    }

    Node <int> * head = NULL;
    Node <int> * tail = NULL;

    while(!pq.empty()){

        Node <int> * temp = pq.top();
        pq.pop();

        // insertion in LL if empty

        if(head == NULL){

            head = temp;
            tail = temp;

            // insert the next value of the same linked list temp

            if(tail->next != NULL){
                pq.push(tail->next);
            }

        }

        // already present values

        else{

            tail->next = temp;
            tail = tail->next;

            // add next value of the same linked list
            
            if(tail->next != NULL){
                pq.push(tail->next);
            }

        }


    }

    return head;


}

void print(Node<int> * &head){

    Node <int> * temp = head;

    while(temp!= NULL){

        cout << temp->data << " ";
        temp = temp->next;

    }
    
}

void insertIntoLL(Node <int> *&head , Node <int> * &tail , int val){

    Node <int> * newNode = new Node<int>(val);

    if(head == NULL){
        head = newNode;
        tail  = newNode;
    }

    else{
        tail->next = newNode;
        tail = tail->next;
    }

}


int main(){

    int k;
    cin >> k;

    vector <Node<int>*> v;

    for(int i=0 ; i<k ; i++){

        int size;
        cin >> size;

        Node <int> * head = NULL;
        Node <int> * tail = NULL;
        for(int j=0 ; j<size ; j++){
            int val; cin >> val;
            insertIntoLL(head,tail,val);
        }

        tail->next = NULL;
        tail = tail->next;

        v.push_back(head);

    }

    Node <int>* ans = mergeKLists(v);

    print(ans);

    return 0;

}
