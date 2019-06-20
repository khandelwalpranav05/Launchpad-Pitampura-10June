#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int arr[13] = {2,4,5,2,3,2,1,3,2,6,2,1,3};
	//int arrLen = sizeof(arr)/sizeof(arr[0]);
	int arrLen =13;
	int leftMax[arrLen];
	int rightMax[arrLen];
	int left = arr[0];
	int right = arr[arrLen-1];
	for (int i = 0; i < arrLen; ++i)
	{	if(left < arr[i]){
			left = arr[i];
		}
		leftMax[i] = left;
	}
	for (int i = arrLen-1; i >=0; i--)
	{	if(right < arr[i]){
			right = arr[i];
		}
		rightMax[i] = right;
	}
	int water = 0;
	for (int i = 0; i < arrLen; ++i)
	{
		water+= min(leftMax[i],rightMax[i])-arr[i];
	}

	cout<<water<<endl;
	return 0;
	
	}
	
