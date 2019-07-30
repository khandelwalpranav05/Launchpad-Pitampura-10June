#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void print(priority_queue<int, vector<int>, greater<int> > q){
	while(!q.empty()){
		cout<<q.top()<<endl;
		q.pop();
	}
}
int main(int argc, char const *argv[])
{
	priority_queue<int, vector<int>, greater<int> > qu;
	int k;
	cin>>k;
	int num;
	int cs =0;
	//scanf("%d", &num) != EOF
	cin>>num;
	while(num != -100){
		if(num == -1){
			print(qu);
		}
		else if(cs<k){
			qu.push(num);
			cs++;
		}
		else{
			if(num>qu.top()){
				qu.pop();
				qu.push(num);
			}
		}

	}
	return 0;
}