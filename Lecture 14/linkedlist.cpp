#include <iostream>

using namespace std;

class node{
public:
	int data;
	node* next;

	node(int d){
		data = d;
		next = NULL;
	}
};

void insertAtHead(node*&head,int data){
	node* n = new node(data);
	n->next = head;
	head = n;
}

void display(node* head){
	node* temp = head;

	while(temp!=NULL){
		cout<<temp->data<<"->";
		temp = temp->next;
	}
	cout<<endl;
}

void insertAtTail(node*&head,int data){
	if(head==NULL){
		insertAtHead(head,data);
		return;
	}

	node* tail = head;

	while(tail->next!=NULL){
		tail = tail->next;
	}

	node* n= new node(data);
	tail->next = n;

}

int main(){

	node* head = NULL;

	insertAtTail(head,12);
	display(head);

	// insertAtHead(head,4);
	// insertAtHead(head,3);
	// insertAtHead(head,2);
	// insertAtHead(head,1);

	// display(head);

	// insertAtTail(head,5);
	// insertAtTail(head,6);

	// display(head);

	return 0;
}

// #include <iostream>

// using namespace std;

// void increment(int *aptr){
// 	*aptr = *aptr + 1;
// 	cout<<"Value of a inside function is "<<*aptr<<endl;

// 	int* xyz = aptr;

// 	cout<<aptr<<endl;
// 	cout<<xyz<<endl;
// 	*xyz = *xyz + 1;

// 	cout<<*xyz<<endl;
// }

// int main(){

// 	int x = 10;

// 	int &z = x;

// 	cout<<z<<endl;
// 	z++;

// 	cout<<x<<endl;

// 	// int a = 10;
// 	// increment(&a);

// 	// cout<<"Value of a inside main is "<<a<<endl;
// 	return 0;
// }