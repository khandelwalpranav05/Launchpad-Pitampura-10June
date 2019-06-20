#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int arr[5][6] = {{1,2,3,4,5,6},
					 {11,12,13,14, 15, 16},
					 {21,22,23, 24, 25, 26},
					 {31, 32, 33, 34, 35, 36},
					 {41,42,43,44,45,46}
					};


	for (int row = 0; row <5 ; row++)
	{
		for (int col = 0; col < 6; col++)
		{
			cout<<arr[row][col]<<" ";
		}
		cout<<endl;
	}
	cout<<"---------------------------"<<endl;

// spiral print
	int frow = 0, lrow=4, fcol=0, lcol = 5;


	while(frow <= lrow && fcol <= lcol){
		//print first row;
		for (int i = fcol; i <= lcol; i++)
		{
			cout<<arr[frow][i]<<", ";
		}
		frow++;
		// print last col
		for (int i = frow; i <= lrow; i++)
		{
			cout<<arr[i][lcol]<<", ";
		}
		lcol--;

		// print last row
          if(frow<lrow){
		for (int i = lcol; i >= fcol; i--)
		{
			cout<<arr[lrow][i]<<", ";
		}
		lrow--;
          }

		// print first col
        if(fcol<lcol){
		for (int i = lrow; i >=frow; i--)
		{
			cout<<arr[i][fcol]<<", ";
		}fcol++;
        }
        
	}

}