#include<iostream>
using namespace std;

const int N = 5;

template<typename T>
class Stack{

	T *arr;
	int top;
public:
	Stack(){
		top=0;
		arr = new T[N];
	}
	void push(T data){
		if(top==N){
			cout<<"stack is already full"<<endl;
			return;
		}

		arr[top] = data;
		top++;
	}
	void pop(){
		if(top==0){
			cout<<"stack is empty"<<endl;
			return;
		}
		cout<<arr[top-1]<<endl;
		top--;
	}
	bool empty(){
		//return top==0;
		if(top==0){
			return true;
		}
		return false;
	}
	bool isfull(){
		//return top==N;
		if(top==N){
			return true;
		}
		return false;
	}
};
int main(int argc, char const *argv[])
{
	Stack<string> st;

	st.push("abc");
	st.push("def");
	st.push("ghi");
	st.push("jkl");
	st.push("mno");
	st.push("pqr");
	st.pop();
	st.pop();
	st.pop();
	st.pop();
	st.pop();
	st.pop();



	return 0;
}











