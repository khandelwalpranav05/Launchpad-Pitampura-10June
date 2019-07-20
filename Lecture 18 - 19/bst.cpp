#include <iostream>
#include <queue>
#include <cmath>
#include <climits>

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

bool search(node* root,int data){
	if(root==NULL){
		return false;
	}

	if(root->data > data){
		return search(root->left,data);
	}else if(root->data < data){
		return search(root->right,data);
	}else{
		return true;
	}
}

node* buildTreeFromArray(int arr[],int s,int e){
	if(s>e){
		return NULL;
	}

	int mid = (s+e)/2;
	node* root = new node(arr[mid]);

	root->left = buildTreeFromArray(arr,s,mid-1);
	root->right = buildTreeFromArray(arr,mid+1,e);
	return root;
}

bool isBST(node* root,int minVal = INT_MIN,int maxVal = INT_MAX){
	if(root==NULL){
		return true;
	}

	bool left_bst = isBST(root->left,minVal,root->data);
	bool right_bst = isBST(root->right,root->data,maxVal);

	if(left_bst and right_bst and root->data >=minVal and root->data<=maxVal){
		return true;
	}else{
		return false;
	}
}

node* deletion(node* root,int data){
	if(root==NULL){
		return NULL;
	}

	if(data > root->data){

		root->right = deletion(root->right,data);
		return root;

	}else if(data < root->data){

		root->left = deletion(root->left,data);
		return root;

	}else{

		if(root->left == NULL and root->right==NULL){
			delete root;
			return NULL;
		}

		if(root->left != NULL and root->right==NULL){
			node* temp = root->left;
			delete root;
			return temp;
		}

		if(root->left == NULL and root->right!=NULL){
			node* temp = root->right;
			delete root;
			return temp;
		}

		if(root->left != NULL and root->right !=NULL){
			node* new_data = root->right;

			while(new_data->left!=NULL){
				new_data = new_data->left;
			}

			root->data = new_data->data;

			root->right = deletion(root->right,new_data->data);
			return root;
		}
	}
}

int numberOfBST(int n){
	if(n==0){
		return 1;
	}

	int ans = 0;
	for(int i=1;i<=n;i++){
		ans += numberOfBST(i-1)*numberOfBST(n-i);
	}

	return ans;
}

int main(){
	// node* root1 = contruct();

	// displayInOrder(root);
	// cout<<endl;

	// int arr[]= {1,2,3,4,5,6,7};
	// node* root2 = buildTreeFromArray(arr,0,6);
	// cout<<search(root,6)<<endl;

	// cout<<isBST(root1)<<endl;
	// cout<<isBST(root2)<<endl;

	// root2 = deletion(root2,4);
	// displayInOrder(root2);
	// cout<<endl;

	cout<<numberOfBST(4)<<endl;

	return 0;
}