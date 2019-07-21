#include<bits/stdc++.h>
using namespace std;
#include "hashmap.h"

int main(int argc, char const *argv[])
{
	hashTable<int> h;

	h.insert("mango", 100); 
	h.insert("apple", 200); 
	h.insert("pear", 300); 
	h.insert("kiwi", 400); 
	h.print();

	if(h.search("pear")){
		cout<<h.search("pear")<<endl;
		cout<<"found"<<endl;
	}
	else{
		cout<<"not found"<<endl;
	}
	
	return 0;
}