#include <iostream>

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

node* buildTree(){
	int data;
	cin>>data;

	if(data==-1){
		return NULL; 
	}

	node *root = new node(data);

	root->left = buildTree();
	root->right = buildTree();

	return root;
}

void displayPreOrder(node*root){
	if(root==NULL){
		return;
	}

	cout<<root->data<<" ";

	displayPreOrder(root->left);
	displayPreOrder(root->right);
}

void displayPostOrder(node*root){
	if(root==NULL){
		return;
	}

	displayPostOrder(root->left);
	displayPostOrder(root->right);

	cout<<root->data<<" ";
}

int main(){

	node* root = buildTree();

	displayPreOrder(root);
	cout<<endl;

	displayPostOrder(root);
	cout<<endl;

	return 0;
}

// 4 2 1 -1 -1 3 -1 -1 6 5 -1 -1 7 -1 -1