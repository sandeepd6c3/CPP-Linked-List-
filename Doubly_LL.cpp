#include<iostream>
using namespace std;

class Node{
	public:
	int data ;
	Node* next;
	Node* prev;

	Node(int val){
		data = val;
		prev = next = NULL;
	}
};
	class DoublyList{
	public:
	Node* head;
	Node* tail;

	DoublyList(){
		head = tail = NULL;
	}

void push_front(int val){
   Node* newnode = new Node(val);

   if(head == NULL){
	head = tail = newnode;
   }
   else{
	newnode->next = head;
	head->prev = newnode;
	head = newnode;
   }

}
void push_back(int val)
	{
	Node* newnode = new Node(val);
	
	if(head == NULL)
	{
		head = tail = newnode;
	}
	else
	{
		tail->next = newnode;
		newnode->prev = tail;
		tail = newnode;
	}
	}
	
	void pop_front()
	{
		Node* temp = head;
		
		head = head->next;
		
		if(head != NULL)
		{
			head->prev = NULL;
		}
		temp->next = NULL;
		delete temp;
	}
	
	void print_ll(){
		Node* temp = head;
		
		while(temp != NULL)
		{
			cout<<temp->data<<"<= >";
			temp = temp->next;
		}
		cout<<"NULL";
	}
	
	

	};



int main()
{
	
	DoublyList dll;

	// dll.push_front(4);
	// dll.push_front(3);
	// dll.push_front(2);
	// dll.push_front(1);
	// dll.push_front(0);
	
	dll.push_back(1);
	dll.push_back(2);
	dll.push_back(3);
	dll.push_back(4);
	dll.push_back(5);
	
	
	dll.print_ll();
	dll.pop_front();
	dll.print_ll();
	return 0;
}
