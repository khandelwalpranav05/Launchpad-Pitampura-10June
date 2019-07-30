#include <iostream>
#include <vector>
using namespace std;

class Heap
{
	vector<int> v;
	bool minheap;

	bool compare(int parentData, int childData){
		if(minheap){
			return parentData>childData;
		}
		else{
			return parentData<childData;
		}

	}
	void heapify(int i){
		int left = i*2;
		int right = left+1;

		int minIdx = i;
		if(left<v.size() && !compare(v[left],v[i])){
			minIdx = left;
		}
		if(right<v.size() && !compare(v[right],v[minIdx])){
			minIdx = right;
		}

		if(minIdx != i){
			swap(v[minIdx], v[i]);
			heapify(minIdx);
		}
		
	}

public:
	Heap(bool type=true){
		minheap = type;
		v.push_back(-1);
	}
	void insert(int data){
		v.push_back(data);

		int child = v.size()-1;
		int parent = child/2;

		while(compare(v[parent],v[child]) && child>1){
			swap(v[parent], v[child]);
			child = parent;
			parent = child/2;

		}
	}

	bool empty(){
		return v.size() <= 1;
	}
	int top(){
		if(empty()){
			return -1;
		}
		return v[1];
	}

	void pop(){
		int last =v.size()-1;
		swap(v[last], v[1]);
		v.pop_back();
		heapify(1);
	}

	
};

int main(int argc, char const *argv[])
{
	Heap h(false);
	h.insert(5);
	h.insert(10);
	h.insert(15);
	cout<<h.top()<<endl;
	h.pop();
	cout<<h.top()<<endl;

	return 0;
}







