#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node(int val){
        data = val;
        next = NULL;
    }
};
class Stack {
    Node* head;
public:
    Stack(){
        head = NULL;
    }
    void push(int val){
        Node* newNode = new Node(val);
        if(head == NULL){
            head = newNode;
        } else {
            newNode -> next = head;
            head = newNode;
        }
    }
    void pop() {
        if(head == NULL){
            cout<<"Nothing to pop " << endl;
        } else {
            Node* temp = head;
            head = head->next;
            temp->next = NULL;
        }
    }
    void top() {
        if(head == NULL){
            cout<<"NULL"<<endl;
        } else {
            cout<<head->data<<endl;
        }
    }
    void print() {
        Node* temp = head;
        while(temp != NULL){
            cout<<temp->data<<" -> ";
            temp = temp->next;
        }
        cout<<"NULL"<<endl;
        delete temp;
    }
};


int main() {
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.pop();
    s.top();
    
    s.print();
    return 0;
}


/*
Actually You can just include the complete linked list STL 
and without even implementing the linked list you can 
do the stack implementation

#include <list>
class Stack{
    list<int> l;
public:
    void push(int val) {
        l.push_back(val);
    }
    void pop() {
        l.pop_front();
    }
    void top() {
        return l.front();
    }
}

*/