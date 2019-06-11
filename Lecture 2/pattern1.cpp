#include <iostream>

using namespace std;

int main(){
int user_row;
cin>>user_row;
for(int row=1; row<=user_row; row++){
	for (int col = 1; col <= row; col++)
	{
		cout<<col;
	}
	cout<<endl;
}

	return 0;
}