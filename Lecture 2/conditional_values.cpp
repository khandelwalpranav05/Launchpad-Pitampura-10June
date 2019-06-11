#include <iostream>

using namespace std;

int main(){

	// int x=5;

	// // cout<<(x>=5)<<endl;

	// if(x==5){
	// 	cout<<"Hi"<<endl;
	// }else{
	// 	cout<<"Bye"<<endl;
	// }


	int a,b,c;

	cin>>a>>b>>c;

	if(a>b && a>c){
		cout<<"A"<<endl;
	}else if(b>a && b>c){
		cout<<"B"<<endl;
	}else{
		cout<<"C"<<endl;
	}

	return 0;
}