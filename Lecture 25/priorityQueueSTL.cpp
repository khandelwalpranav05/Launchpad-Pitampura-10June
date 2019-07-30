#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	//priority_queue<int> qu;
	priority_queue<int, vector<int>, greater<int> > qu;
	qu.push(10);
	qu.push(20);
	qu.push(30);
	qu.push(40);
	while (!qu.empty())
	{
		cout<<qu.top()<<endl;
		qu.pop();
	}
	


	return 0;
}