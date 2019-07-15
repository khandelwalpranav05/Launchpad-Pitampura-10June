#include<iostream>
#include <stack>
using namespace std;

void transfer(stack<char> &s1,stack<char> &s2, int num){
	for (int i = 0; i < num; i++)
	{
		s2.push(s1.top());
		s1.pop();
	}
}
void reverseStack(stack<char> &st){

	stack<char> st_helper;
	int n = st.size();
	for (int i = 0; i < n; i++)
	{
		char top_member = st.top();
		st.pop();

		int left_members = n - 1 - i;

		transfer(st, st_helper, left_members);
		st.push(top_member);
		transfer(st_helper, st, left_members);

	}
}



int main(int argc, char const *argv[])
{
	stack<char> st;
	st.push('a');
	st.push('b');
	st.push('c');
	st.push('d');
	reverseStack(st);

	cout<<st.top()<<endl;
	st.pop();
	cout<<st.top()<<endl;
	st.pop();
	cout<<st.top()<<endl;
	st.pop();
	cout<<st.top()<<endl;
	st.pop();
	return 0;
}















