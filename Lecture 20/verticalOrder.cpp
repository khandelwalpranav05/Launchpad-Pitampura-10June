#include<bits/stdc++.h>
#include <unordered_map>

using namespace std;

class node{
public:
	int data;
	node* left;
	node*right;

	node(int d){
		data = d;
		left = right = NULL;
	}

};

void verticalOrder(node* root, int dis, unordered_map<int,vector<int> > &umap ){
	if(root == NULL){
		return;
	}
	umap[dis].push_back(root->data);
	verticalOrder(root->left, dis-1, umap);
	verticalOrder(root->right, dis+1, umap);

}

int main(int argc, char const *argv[])
{

	node* root = new node(1);
	root->left = new node(2);
	root->right = new node(3);
	root->left->left = new node(4);
	root->left->right = new node(5);
	root->right->left = new node(6);
	root->right->right = new node(7);
	unordered_map<int,vector<int> > umap;
	verticalOrder(root, 0, umap);

	int minkey = INT_MAX;
	int maxkey = INT_MIN;

	for (auto i = umap.begin();i != umap.end() ; i++)
	{
		minkey = min(minkey, i->first);
		maxkey = max(maxkey, i->first);
	}

	for (int i = minkey; i <= maxkey; i++)
	{	
		cout<<i<<" --> ";
		for (int val = 0; val < umap[i].size(); val++)
		{
			cout<<umap[i][val]<<", ";
		}
		cout<<endl;
	}



	return 0;
}




