#include<iostream>

using namespace std;

int sumTilln(int n){
	if(n==0){
		return 0;
	}

	int sumTilln1 = sumTilln(n-1);

	int total_sum = sumTilln1 + n;
	return total_sum;
}

int factorial(int n){
	if(n==0){
		return 1;
	}

	int factorialn1 = factorial(n-1);
	int total_fact = n*factorialn1;
	return total_fact;
}

int main(){

	// cout<<sumTilln(4)<<endl;
	// cout<<factorial(5)<<endl;
	return 0;
}