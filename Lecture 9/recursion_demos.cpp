#include<iostream>
#include <cstring>

using namespace std;

int powerFast(int n,int p){
	if(p==0){
		return 1;
	}

	if(p%2==0){
		int temp = powerFast(n,p/2);
		return temp*temp;
	}else{
		int temp = powerFast(n,p/2);
		return temp*temp*n;
	}
}

int main(){

	// cout<<powerFast(2,10)<<endl;
	string s = to_string(12);
	cout<<s<<endl;
	return 0;
}