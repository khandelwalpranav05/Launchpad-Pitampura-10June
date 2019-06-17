#include <iostream>

using namespace std;

void increment(int* a){
	*a = *a + 1;
	cout<<"Inside Function "<<(*a)<<endl;
}

int main(){

	int a = 10;
	increment(&a);
	cout<<"Inside Main "<<a<<endl;

	// int x = 10;
	// int &z = x;

	// cout<<z<<endl;
	// cout<<x<<endl;

	// z++;

	// cout<<x<<endl;
	// cout<<z<<endl;
	return 0;
}