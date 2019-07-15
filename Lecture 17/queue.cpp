#include<iostream>
using namespace std;

template<typename T>
class Queue{
	T* arr;
	int front;
	int rear;
	int curr_size;
	int max_size;
public:
	Queue(int d_size = 5){
		front = 0;
		max_size = d_size;
		rear = max_size-1;
		arr = new T[max_size];
		curr_size = 0;
	}

	bool isFull(){
		//return curr_size==max_size;
		if(curr_size==max_size){
			return true;
		}
		return false;
	}
	void push(T data){
		if(isFull()){
			cout<<"queue is full"<<endl;
			return;
		}
		rear = (rear+1)% max_size;
		arr[rear] = data;
		curr_size++;
	}

	bool isempty(){
		//return curr_size==0;
		if(curr_size==0){
			return true;
		}
		return false;
	}
	void pop(){
		if(isempty()){
			cout<<"queue is empty"<<endl;
			return;
		}
		arr[front] = 0; //optional
		front = (front+1)%max_size;
		curr_size--;
	}
	T getFront(){
		return arr[front];
	}
};

int main(int argc, char const *argv[])
{
	Queue<int> s(20);
	s.push(100);
	s.push(200);
	s.push(300);
	s.push(400);
	s.push(500);
	cout<<s.isFull()<<endl;
	cout<<s.isempty()<<endl;
	cout<<s.getFront()<<endl;
	s.pop();
	cout<<s.getFront()<<endl;
	s.pop();
	cout<<s.getFront()<<endl;
	s.pop();
	cout<<s.isFull()<<endl;
	cout<<s.getFront()<<endl;
	s.pop();

	return 0;
}














