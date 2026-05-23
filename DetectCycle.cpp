#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int val){
       data=val;
       next=NULL;
    }
};

class List{
    public:
    Node*head;
    Node*tail;

    List(){
        head = NULL;
        tail = NULL;
    }

    void push_front(int val){
        Node* newNode = new Node(val);
        if(head == NULL){
            head = newNode;
            tail = newNode;
        }
        else{
            newNode->next = head;
            head = newNode;
        }
    }

    void push_back(int val){
        Node* newNode = new Node(val);
        if(head == NULL){
            head = newNode;
            tail = newNode;
        }
        else{
            tail->next = newNode;
            tail = newNode;
        }
    }

    void print_ll(){
        Node* temp = head;
        while(temp != NULL){
            cout<<temp->data<<"->";
            temp = temp->next;
        }
        cout<<"NULL"<<endl;
    }

    bool isCycle(Node* head){
        
        Node*slow=head;
        Node*fast=head;

        while(fast!=NULL && fast->next !=NULL){
            slow=slow->next;
            fast=fast->next->next;

        if(slow == fast){
            cout<<"Cycle Detected !"<<endl;
            return true;

        }
        
    }
    cout<<"Cycle Does't exists"<<endl;
    return false;
    }
};

int main(){

    List ll;
    ll.push_back(1);
    ll.push_back(2);
    ll.push_back(3);
    ll.push_back(4);
    ll.push_back(5);

    ll.tail->next=ll.head;

    ll.isCycle(ll.head);
    return 0;
}