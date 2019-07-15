#include<iostream>
#include <stack>
using namespace std;

int main(int argc, char const *argv[])
{
	stack<int> s;
	s.push(100);
	s.push(200);
	s.push(300);
	s.push(400);
	cout<<s.empty()<<endl;
	cout<<s.top()<<endl;
	s.pop();
	cout<<s.top()<<endl;
	s.pop();
	cout<<s.top()<<endl;
	s.pop();
	cout<<s.top()<<endl;
	s.pop();
	cout<<s.empty()<<endl;
	return 0;
}


