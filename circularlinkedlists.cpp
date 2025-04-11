#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val){
        data = val;
        next = NULL;
    }
};
class CircularList{
Node* head;
Node* tail;
public:
    CircularList(){
        head = tail = NULL;
    }
    void insert_at_head(int val){
        Node* newNode = new Node(val);
        if(head == NULL){
            head = tail = newNode;
            tail -> next = head;
        }else{
            tail -> next = newNode;
            newNode -> next = head;
            head = newNode;
    }}

    void insert_at_tail(int val) {
        Node* newNode = new Node(val);
        if(head == NULL){
            head = tail = newNode;
            tail -> next = head;
        } else{
            tail -> next = newNode;
            tail = newNode;
            tail -> next = head;
    }}
    void pop_front() {
        if(head == NULL){   // Empty List
            cout<<"Nothing to delete";
            return;
        }
        else if(head == tail){   // Singel Node
            delete head;
            head = tail = NULL;
        } else{
            Node* temp = head;
            tail -> next = head -> next;
            head = head -> next;
            temp -> next = NULL;
            delete temp;
    }}
    void delete_at_tail() {
        if(tail == NULL){
            cout<<"Nothing to delete";
            return;
        }
        else if(tail == head){
            delete tail;
            head = tail = NULL;
        } else {
            Node* temp = head;
            while (temp -> next != tail){
                temp = temp -> next;
            }
            tail = temp;
            temp = temp -> next;
            tail -> next = NULL;
            temp -> next = NULL;
            tail -> next = head;
            delete temp;
        }
        
    }

    void print(){
        if(head == NULL) return;
        
        cout<< head -> data << " -> ";
        Node* temp = head->next;
        while(temp != head){
            cout<< temp -> data << " -> ";
            temp = temp -> next;
        }
        cout<< temp -> data << endl;
    }

};


int main() {
    CircularList cll;
    cll.insert_at_head(3);
    cll.insert_at_head(2);
    cll.insert_at_head(1);
    cll.insert_at_tail(4);
    cll.pop_front();
    cll.delete_at_tail();
    cll.print();
}