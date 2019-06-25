#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int arr[] ={1,2,3,2,9,7,3,1,7};

	int length = sizeof(arr)/sizeof(arr[0]);
	int Xor = arr[0];
	for (int i = 1; i < length; i++)
	{
		Xor = Xor^arr[i];
	}
	cout<<Xor<<endl;
	return 0;
}