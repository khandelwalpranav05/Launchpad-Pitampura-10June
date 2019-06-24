#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int arr[4][3] = {{1,2,3},
					 {11,12,13},
					 {21,22,23},
					 {31, 32, 33}};

// Wave Print

	for (int row = 0; row <4 ; row++)
	{
		if(row%2==0){
			for (int col = 0; col < 3; col++)
			{
				cout<<arr[row][col]<<" ";
			}

		}
		else{
			for (int col = 2; col>=0 ; col--)
			{
				cout<<arr[row][col]<<" ";
			}
		}
		cout<<endl;
	}

	return 0;
}