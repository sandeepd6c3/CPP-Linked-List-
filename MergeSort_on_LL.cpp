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

    Node* splitAtmid(Node* head){
        Node* slow = head;
        Node* fast = head;
        Node* prev = NULL;

        while(fast != NULL && fast->next != NULL){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        if(prev != NULL){
            prev->next = NULL; // Split at middle

        }
        return slow; // Slow = rightHead
    }


    Node* merge(Node* left , Node* right){
        List ans;
        Node* i = left;
        Node* j = right;
        

        while(i != NULL && j != NULL){
            if (i->data <= j->data ){
                ans.push_back(i->data);
                i = i->next; 
            }
            else{
                ans.push_back(j->data);
                j = j->next;
            }
        }
        while(i != NULL){
            ans.push_back(i->data);
            i = i->next;
        }
        while(j != NULL){
            ans.push_back(j->data);
            j = j->next;
        }
        return ans.head;
    }

    Node* mergeSort(Node* head){

        if(head == NULL || head->next == NULL){
             return head;
        }

        Node* rightHead = splitAtmid(head);
        Node* left = mergeSort(head);
        Node* right = mergeSort(rightHead);

       return merge(left,right);
    }
};

int main(){

    List ll;
    ll.push_back(4);
    ll.push_back(3);
    ll.push_back(1);
    ll.push_back(5);
    ll.push_back(2);

    ll.head = ll.mergeSort(ll.head);

ll.print_ll();

   
    return 0;
}
