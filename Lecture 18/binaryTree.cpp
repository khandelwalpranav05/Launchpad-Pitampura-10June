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

void displayInOrder(node* root){
	if(root==NULL){
		return;
	}

	displayInOrder(root->left);

	cout<<root->data<<" ";

	displayInOrder(root->right);
}

void displayLevelOrder(node* root){
	queue<node*> q;

	q.push(root);

	while(!q.empty()){
		node* temp = q.front();

		q.pop();

		cout<<temp->data<<" ";

		if(temp->left!=NULL){
			q.push(temp->left);
		}

		if(temp->right!=NULL){
			q.push(temp->right);
		}

	}
	cout<<endl;
}

void displayLevelOrderNewLine(node*root){
	queue<node*> q;
	q.push(root);
	q.push(NULL);

	while(!q.empty()){
		node* temp = q.front();
		q.pop();

		if(temp==NULL){
			cout<<endl;
			if(!q.empty()){
				q.push(NULL);
			}
			continue;
		}

		cout<<temp->data<<" ";

		if(temp->left!=NULL){
			q.push(temp->left);
		}

		if(temp->right!=NULL){
			q.push(temp->right);
		}

	}
	cout<<endl;
}

int numberOfNodes(node* root){
	if(root==NULL){
		return 0;
	}

	int count;

	int left_count = numberOfNodes(root->left);
	int right_count = numberOfNodes(root->right);

	count = left_count + right_count + 1;
	return count;
}

int sumOfNodes(node*root){
	if(root==NULL){
		return 0;
	}

	int sum;
	int left_sum = sumOfNodes(root->left);
	int right_sum = sumOfNodes(root->right);

	sum = left_sum + right_sum + root->data;
	return sum;
}

int height(node*root){
	if(root==NULL){
		return -1;
	}

	int left_height = height(root->left);
	int right_height = height(root->right);

	return max(left_height,right_height) + 1;
}

int diameter(node*root){
	if(root==NULL){
		return 0;
	}

	int left_dia = diameter(root->left);
	int right_dia = diameter(root->right);

	int leftH = height(root->left);
	int rightH = height(root->right);
	int total_dia = leftH + rightH + 2;

	return max(total_dia,max(left_dia,right_dia));
}

int main(){

	node* root = buildTree();

	// displayPreOrder(root);
	// cout<<endl;

	// displayPostOrder(root);
	// cout<<endl;

	// displayInOrder(root);
	// cout<<endl;

	// displayLevelOrder(root);

	// displayLevelOrderNewLine(root);

	// cout<<numberOfNodes(root)<<endl;
	// cout<<sumOfNodes(root)<<endl;

	// cout<<height(root)<<endl;

	cout<<diameter(root)<<endl;

	return 0;
}

// 4 2 1 -1 -1 3 -1 -1 6 5 -1 -1 7 -1 -1

// 18
// 20
// 22
// 23
// 25
// 26
// 27
// 29
// 30
// 1