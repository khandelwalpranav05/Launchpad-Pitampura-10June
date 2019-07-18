#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

class node{
public:
	int data;
	node* left;
	node* right;

	node(int d){
		this->data = d;
		left = NULL;
		right = NULL;
	}
};

node* insert(node*root,int data){
	if(root==NULL){
		// node* temp = new node(data);
		// return temp;
		return new node(data);
	}

	if(root->data > data){
		root->left = insert(root->left,data);
	}else{
		root->right = insert(root->right,data);
	}

	return root;
}

node* contruct(){
	int data;
	cin>>data;

	node* root = NULL;

	while(data!=-1){
		root = insert(root,data);
		cin>>data;
	}

	return root;
}

void displayInOrder(node* root){
	if(root==NULL){
		return;
	}

	displayInOrder(root->left);

	cout<<root->data<<" ";

	displayInOrder(root->right);
}

int main(){
	node* root = contruct();

	displayInOrder(root);
	cout<<endl;

	return 0;
}