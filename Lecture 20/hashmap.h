#include<bits/stdc++.h>
using namespace std;

template<typename T>
class node
{
	public:
		string key;
		T value;
		node<T> *next;
	node(string k, T v){
		key = k;
		value = v;
		next = NULL;
	}

	~node(){
		if(next!=NULL){
			delete next;
		}
	}
};

template<typename T>
class hashTable{
	int currSize;
	int maxSize;
	node<T>** bucket;

	int hashfunc(string key){
		int l =key.length();
		int idx = 0;
		int mulFactor = 1;
		for (int i = 0; i < l; ++i)
		{
			idx += key[l-i-1]*mulFactor;
			idx %= maxSize;
			mulFactor*=37;
			mulFactor %= maxSize;
		}

		return idx;
	}

	void rehash(){
		int oldsize = maxSize;
		maxSize = 2*maxSize;
		node<T>** oldbucket = bucket;

		bucket = new node<T>*[maxSize];
		for (int i = 0; i < maxSize; i++)
		{
			bucket[i] = NULL;
		}
		currSize =0;

		for (int i = 0; i < oldsize; ++i)
		{
			node<T>* temp = oldbucket[i];
			while(temp!=NULL){
				insert(temp->key, temp->value);
				temp = temp->next;
			}
			delete oldbucket[i];
		}
		delete[] oldbucket;
	}

public:
	hashTable(int default_size = 7){
		maxSize = default_size;
		bucket = new node<T>*[maxSize];
		currSize =0;

		for (int i = 0; i < maxSize; i++)
		{
			bucket[i] = NULL;
		}
	}

	void insert(string key, T value){
		int idx = hashfunc(key);

		node<T>* newNode = new node<T>(key, value);
		newNode->next = bucket[idx];
		bucket[idx] = newNode;
		currSize++;

		float loadFactor = (float)currSize/(float)maxSize;

		if(loadFactor>0.7){

			cout<<"load factor is"<<loadFactor<<endl;
			cout<<"rehash"<<endl;
			rehash();
		}


	}

	void print(){
		for (int i = 0; i < maxSize; i++)
		{
			node<T>* temp = bucket[i];
			while(temp!=NULL){
				cout<< temp->key<<" - "<<temp->value <<"-->";
				temp = temp->next; 
			}
			cout<<endl;
		}
	}

	T* search(string key){
		int idx = hashfunc(key);
		node<T>* temp = bucket[idx];
		while(temp!=NULL){
			if(temp->key == key){
				//cout<<temp->value<<endl;
				return &(temp->value);
			}
			temp = temp->next;
		}
		return NULL;

	}

	void erase(string key){
		int idx = hashfunc(key);
		node<T>* temp = bucket[idx];
		if(search(key)==NULL){
			return;
		}
		if(temp->key == key){
			node<T>* tobeDeleted = temp;
			bucket[idx]=temp->next;
			tobeDeleted->next = NULL;
			delete tobeDeleted;
			return;
		}
		while(temp->next->key != key){
			temp=temp->next;
		}
		node<T>* tobeDeleted = temp->next;
		temp->next = temp->next->next;
		tobeDeleted->next = NULL;
		delete tobeDeleted;
		return;
	}

	T& operator[](string key){
		T* add = NULL;
		if(search(key) != NULL){
			 add =  search(key);
		}
		else{
			T val;
			insert(key, val);
			add = search(key);
		}
		return *add;
	}
};
























