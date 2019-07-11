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

void insertAtHead(node*&newHead,int data){
	node* n = new node(data);
	n->next = newHead;
	newHead = n;
}

void display(node*&head){
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

int length(node* head){
	int count = 0;

	while(head!=NULL){
		head = head->next;
		count++;
	}

	return count;
}

void insertAtIndex(node*&head,int data,int pos){
	if(pos==0 || head==NULL || pos==1){
		insertAtHead(head,data);
	}

	if(pos>length(head)){
		insertAtTail(head,data);
	}

	node* temp = head;

	int count = 1;

	while(count<pos-1){
		temp = temp->next;
		count++;
	}

	node* n = new node(data);

	n->next = temp->next;
	temp->next = n;
}

void deleteAtHead(node*&head){
	node* temp = head;
	head = head->next;

	delete temp;
}

void deleteAtTail(node*head){
	node* prev = NULL;
	node* temp = head;

	while(temp->next!=NULL){
		prev = temp;
		temp = temp->next;
	}

	delete temp;
	prev->next = NULL;
}

bool searchIterative(node* head,int item){
	node* temp = head;

	while(temp!=NULL){
		if(temp->data==item){
			return true;
		}
		temp = temp->next;
	}

	return false;
}

bool searchRecursive(node* head,int item){
	if(head==NULL){
		return false;
	}

	if(head->data==item){
		return true;
	}else{
		return searchRecursive(head->next,item);
	}
}

node* midPoint(node*head){
	node* slow = head;
	node* fast = head;

	while(fast!=NULL and fast->next!=NULL){
		fast = fast->next->next;
		slow = slow->next;
	}

	return slow;
}

void reverseIterative(node*&head){
	node* prev = NULL;
	node* cur = head;

	while(cur!=NULL){
		node* n = cur->next;
		cur->next = prev;
		prev = cur;
		cur = n;
	}

	head = prev;
}

node* reverseRecursive(node*&head){
	//Base
	if(head==NULL || head->next==NULL){
		return head;
	}

	//Recur
	node* newHead = reverseRecursive(head->next);
	node* curr = head;
	curr->next->next = curr;
	curr->next = NULL;
	return newHead;
}

node* merge(node* a,node* b){
	if(a==NULL){
		return b;
	}

	if(b==NULL){
		return a;
	}

	node*c;

	if(a->data < b->data){
		c = a;
		c->next = merge(a->next,b);
	}else{
		c = b;
		c->next = merge(a,b->next);
	}

	return c;
}

int main(){

	node* head = NULL;

	// insertAtTail(head,12);
	// display(head);

	// insertAtHead(head,2);
	// display(head);

	// insertAtHead(head,4);
	// insertAtHead(head,3);
	// insertAtHead(head,2);
	// insertAtHead(head,1);

	// display(head);

	// insertAtTail(head,5);
	// insertAtTail(head,6);

	// display(head);

	// reverseIterative(head);

	// display(head);

	// head = reverseRecursive(head);

	// display(head);

	// insertAtIndex(head,789,3);

	// display(head);

	// deleteAtHead(head);

	// display(head);

	// deleteAtTail(head);

	// display(head);

	// if(searchIterative(head,3)){
	// 	cout<<"Found!"<<endl;
	// }else{
	// 	cout<<"Not found!"<<endl;
	// }

	// if(searchRecursive(head,3)){
	// 	cout<<"Found!"<<endl;
	// }else{
	// 	cout<<"Not found!"<<endl;
	// }

	// node* mid = midPoint(head);

	// cout<<mid->data<<endl;



	node* a = NULL;
	node* b = NULL;

	insertAtHead(a,5);
	insertAtHead(a,3);
	insertAtHead(a,1);

	display(a);

	insertAtHead(b,6);
	insertAtHead(b,4);
	insertAtHead(b,2);

	display(b);

	node* merged_head = merge(a,b);

	display(merged_head);

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

// Stacks and queues (1)
// Binary Tree BST (2)
// HashMap & Heaps (2)
// Tries (1)
// Graph (2)
// DP (2)
