#include<iostream>
using namespace std;

// Node class represents a single node in the linked list.
class Node{
    public:
    int data;
    Node* next;

    Node(int val){
       data = val;
       next = NULL;
    }
};

// List class manages the linked list operations.
class List{
    public:
    Node* head;
    Node* tail;

    List(){
        head = NULL;
        tail = NULL;
    }

    // Insert a new node at the beginning of the list.
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

    // Insert a new node at the end of the list.
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

    // Print the linked list from head to tail.
    void print_ll(){
        Node* temp = head;
        while(temp != NULL){
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

  

    // Split the list into two halves and return the head of the right half.
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
            prev->next = NULL; // Break the list into two parts.
        }

        return slow; // slow is the start of the right half.
    }

    // Reverse the linked list and return the new head.
    Node* reverse(Node* head){
        Node* prev = NULL;
        Node* curr = head;
        Node* next = NULL;

        while(curr != NULL){
            next = curr->next;   // Save next node.
            curr->next = prev;   // Reverse current node's pointer.
            prev = curr;         // Move prev forward.
            curr = next;         // Move curr forward.
        }

        return prev; // Prev points to the new head after reversal.
    }

    // Prepare for zig-zag reordering of the list.
    Node* zigzagLL(Node* head){
        // Split list into two halves.
        Node* rightHead = splitAtmid(head);

        // Reverse the second half for alternating merge.
        Node* rightHeadRav = reverse(rightHead);

        // Alternate merging:
        // 1st node from first half, 2nd node from reversed second half.
        // This method is not yet fully implemented in this version.

        Node* left = head;
        Node* right = rightHeadRav;
        Node* tail = right;

        while(left !=  NULL && right != NULL){
            Node* nextleft = left->next;
            Node* nextright = right->next;

            left->next = right;
            right->next = nextleft;

            tail = right;

            left = nextleft;
            right = nextright;

        }
        if(right != NULL){
            tail->next = right;
        }
        return head;
    } 
};

int main(){
    List ll;

    // Create an unsorted linked list.
    ll.push_back(1);
    ll.push_back(2);
    ll.push_back(3);
    ll.push_back(4);
    ll.push_back(5);

    // Sort the linked list using merge sort.
    // ll.head = ll.mergeSort(ll.head);

    // Print the sorted linked list.
    ll.print_ll();

    ll.head = ll.zigzagLL(ll.head);
    ll.print_ll();

    return 0;
}
