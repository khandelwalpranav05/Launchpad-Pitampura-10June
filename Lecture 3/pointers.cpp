#include <iostream>

using namespace std;

int main(){

	// int x = 10;
	// cout<<(&x)<<endl;

	// int* xptr = &x;
	// cout<<xptr<<endl;

	// cout<<x<<endl;
	// cout<<*xptr<<endl;

	// *xptr = *xptr + 1;
	// cout<<x<<endl;


	// int x = 30;
	// int* xptr = &x;

	// cout<<x<<endl;
	// cout<<*xptr<<endl;

	// cout<<&x<<endl;
	// cout<<xptr<<endl;

	// cout<<*(&x)<<endl;
	// cout<<&(*xptr)<<endl;

	float y = 10.5;
	int x = 5;

	int* xptr = &x;
	cout<<xptr<<endl;

	xptr = &y;
	cout<<xptr<<endl;

	// char a = 'A';
	// int check = a;
	// cout<<check<<endl;
	return 0;
}