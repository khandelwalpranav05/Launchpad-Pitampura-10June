#include <iostream>

using namespace std;

int main(){

	// int count = 1;
	// while(count<=5){
	// 	cout<<count<<endl;
	// 	count = count+2;
	// }
	// cout<<"Count";
	// cout<<count<<endl;

	// int a = 0;
	// // cin>>a;

	// while(a!=-1){
	// 	cin>>a;
	// 	cout<<"Output "<<a<<endl;
	// }

	// return 0;

int x,y;
cin>>x>>y;

int exp=1;
for(int i=1; i<=y; i++){
	exp =exp*x;
}
cout<<exp<<endl;
return 0;

}