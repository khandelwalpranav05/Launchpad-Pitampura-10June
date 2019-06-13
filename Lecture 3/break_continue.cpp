#include <iostream>

using namespace std;

int main(){

	// int i = 1;

	// while(i<=10){
	// 	cout<<i<<endl;

	// 	if(i==5){
	// 		cout<<"END!"<<endl;
	// 		i++;
	// 		continue;
	// 	}

	// 	i++;
	// }

	int n;
	cin>>n;

	int check = 2;
	bool flag = false;
	while(check*check<=n){
		if(n%check==0){
			cout<<"Not Prime"<<endl;
			flag = true;
			break;
		}

		check++;

	}

	if(flag==false){
		cout<<"Prime"<<endl;
	}

	return 0;
}
//   *   *   *   *
//  * * * * * * * *
// *   *   *   *   *