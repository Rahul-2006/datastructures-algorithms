#include<iostream>
#include<string>
using namespace std;

class Node{             //class for node
    public:
    int data;           //data of node
    Node* next;         //pointer to next node
    Node(int val){      //constructor
        data = val; 
        next = NULL;    //pointer to next node
    }
};

class List{         //class for linked list
    Node* head;     //pointer to head node
    Node* tail;     //pointer to tail node

    public:
    List(){                 //constructor
        head = NULL;        //initially head and tail are NULL
        tail = NULL;
    }

    void push_front(int val) {              //function to insert node at front      //O(1)
        Node* newNode = new Node(val);      //create new node
        if(head == NULL){                   //if list is empty
            head = tail = newNode;          //head and tail will point to new node
            return;
        } else{
            newNode->next = head;           //new node will point to head
            head = newNode;                 //new node will become head
            return;
        }
    }

    void push_back(int val) {                //function to insert node at back          //O(1)
        Node* newNode = new Node(val);      //create new node
        if(head == NULL){                   //if list is empty
            head = tail = newNode;          //head and tail will point to new node
            return;
        } else{
            tail->next = newNode;           //tail will point to new node
            tail = newNode;                 //new node will become tail
            return;
        }
    }

    void pop_front() {                                                                  //O(1)
        Node* temp = head; //initalizing a temp pointer to head 
        if(head ==NULL){       // Checking for the edge case where there is no initial nodes
            head=tail=NULL;   
            return;
        }else{
            head = head->next;      //Head is now changed to next node of head
            temp->next = NULL;      //temp is now pointing to NULL
            delete temp;            //deleting the temp node
        }
    }  
    void pop_back() {                                                                  //O(N)
        Node* temp = head;  //initalizing a temp pointer to head
        if(tail == NULL){    // Checking for the edge case where there is no initial nodes
            head = tail = NULL;
            return;
        } 
        while(temp->next != tail){  //traversing till the second last node (node before tail)
            temp = temp->next;      //moving to next node
        } 
        temp->next = NULL;          //making the next of second last node NULL (second last node is tail)
        temp = tail;                //temp is now pointing to tail
        delete tail;                //deleting the tail node
    }
    void insert(int val , int pos) {                                                    //O(N)
        if(pos == 0){               //if position is 0, insert at front
            push_front(val);
        }
        if(pos < 0) {               //if position is negative, invalid position
            cout<<"Invalid Position" << endl;
        }
        Node* newNode = new Node(val);          
        Node* temp = head;
        for(int i = 0 ; i < pos - 1 ; i++){         //traverse till the node before the position
            if(temp == NULL) {
                cout<<"Invalid Position"<<endl;
            }
            temp = temp->next;                      //move to next node
        }           
        newNode->next = temp->next;                 //new node will point to next node of temp
        temp->next = newNode;                       //temp will point to new node
        
    }
    int search(int target){                                                             //O(N)
        Node* temp = head;                  //temp pointer to head
        int idx = 0;                        
        while(temp != NULL){                //traverse till end of list
            if(temp->data == target){       //if data of node is equal to target
                return idx;
            }
            temp = temp->next;              //move to next node
            idx++;      
        }
        return -1;
    }

    void printLL() {                                                                        //O(N)
        Node* temp = head;                  //temp pointer to head
        while(temp != NULL) {               //traverse till end of list
            cout << temp->data << "->";     //print data of node
            temp = temp->next;              //move to next node
        }
    cout<< "NULL"<<endl;
    }
};


int main() {
    List ll;

    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);

    ll.push_back(4);
    ll.push_back(5);

    ll.insert(7,1);

    ll.pop_front();
    ll.pop_back();

    ll.printLL();

    cout<< ll.search(7);

    return 0;
}