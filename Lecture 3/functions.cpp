#include <iostream>

using namespace std;

int factorial(int n){
	int result = 1;
	for(int i=1;i<=n;i++){
		result = result*i;
	}

	return result;
}

int main(){

	int n;
	cin>>n;
	int r;
	cin>>r;

	int nfact = 1;

	for(int i = 1;i<=n;i++){
		nfact = nfact*i;
	}

	int rfact = 1;
	for(int i= 1;i<=r;i++){
		rfact = rfact*i;
	}

	int nrfact = 1;
	for(int i=1;i<=(n-r);i++){
		nrfact = nrfact*i;
	}

	int sum = nfact/(rfact*nrfact);

	// cout<<sum<<endl;

	int sum = factorial(n)/(factorial(r)*factorial(n-r));
	cout<<sum<<endl;

	// cout<<mul<<endl;


	return 0;
}