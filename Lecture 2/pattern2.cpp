#include <iostream>

using namespace std;

int main(){

int user_row,val=1;
cin>>user_row;
for(int row=1; row<=user_row; row++){

	for (int col = 1; col <= row; col++){
		cout<<val<<" ";
		val++;
	}
	
	cout<<endl;
}

	return 0;

	// int mul = 1;

	// for(int i=1;i<=y;i++){
	// 	mul = mul*x;
	// }

	// cout<<mul<<endl;

	// int n = 4;

	// for(int row=1;row<=n;row++){
	// 	for(int col=1;col<=row;col++){
	// 		cout<<col<<" ";
	// 	}

	// 	cout<<endl;
	// }
}