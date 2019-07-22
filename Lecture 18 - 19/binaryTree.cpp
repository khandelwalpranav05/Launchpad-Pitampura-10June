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

bool isBalanced(node* root){
	if(root==NULL){
		return true;
	}

	bool leftBalanced = isBalanced(root->left);
	bool rightBalanced = isBalanced(root->right);

	if(!leftBalanced or !rightBalanced){
		return false;
	}

	int leftH = height(root->left);
	int rightH = height(root->right);

	int gap = abs(leftH - rightH);

	if(gap>1){
		return false;
	}else{
		return true;
	}

}

class L2{
public:
	int height;
	int diameter;
};

L2 diameterOptimized(node*root){
	L2 val;

	if(root==NULL){
		val.height = -1;
		val.diameter = 0;
		return val;
	}

	L2 left = diameterOptimized(root->left);
	L2 right = diameterOptimized(root->right);

	val.height = max(left.height,right.height) + 1;
	val.diameter = max(left.height + right.height + 2,max(left.diameter,right.diameter));
	return val;
}

class BalancePair{
public:
	int height;
	bool isBalanced;
};

BalancePair isBalancedOptimized(node*root){
	BalancePair val;

	if(root==NULL){
		val.height = -1;
		val.isBalanced = true;
		return val;
	}

	BalancePair left = isBalancedOptimized(root->left);
	BalancePair right = isBalancedOptimized(root->right);

	val.height = max(left.height,right.height) + 1;

	if(abs(left.height - right.height)<=1 and left.isBalanced and right.isBalanced){
		val.isBalanced = true;
	}else{
		val.isBalanced = false;
	}

	return val;
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

int preorder_count = 0;

node* buildTreeFromInOrderPreOrder(int pre[],int in[],int s,int e){
	if(s>e){
		return NULL;
	}

	node* root = new node(pre[preorder_count]);

	int index = -1;

	for(int i=s;i<=e;i++){
		if(in[i]==pre[preorder_count]){
			index = i;
			break;
		}
	}

	preorder_count++;
	root->left = buildTreeFromInOrderPreOrder(pre,in,s,index-1);
	root->right = buildTreeFromInOrderPreOrder(pre,in,index+1,e);
	return root;

}

int main(){

	// node* root = buildTree();

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

	// cout<<diameter(root)<<endl;

	// if(isBalanced(root)){
	// 	cout<<"Balanced"<<endl;
	// }else{
	// 	cout<<"Not Balanced"<<endl;
	// }

	// L2 pair = diameterOptimized(root);
	// cout<<pair.diameter<<endl;
	// cout<<pair.height<<endl;

	// BalancePair val = isBalancedOptimized(root);
	// cout<<val.height<<endl;
	// cout<<val.isBalanced<<endl;

	// int arr[]= {1,2,3,4,5,6,7};
	// node* root = buildTreeFromArray(arr,0,6);

	// displayInOrder(root);
	// cout<<endl;

	int pre[] = {1,2,4,5,3,6,7};
	int in[] = {4,2,5,1,6,3,7};
	node* root = buildTreeFromInOrderPreOrder(pre,in,0,6);

	displayInOrder(root);
	cout<<endl;

	return 0;
}

// 4 2 1 -1 -1 3 -1 -1 6 5 -1 -1 7 -1 -1
// 1 -1 2 -1 3 -1 -1

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