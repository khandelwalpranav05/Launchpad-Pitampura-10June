#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int arr[6] = {1,-2,8,-4,-1,7};
	int cumSum[6]={0};
	cumSum[0]=arr[0];
	int max = INT_MIN;
	for (int i = 1; i < 6; i++)
	{
		cumSum[i]=cumSum[i-1]+arr[i];
	}
	for (int i = 0; i < 6; i++)
	{
		for (int j = i; j < 6; j++)
		{	int sum =cumSum[j];
			if(i>0){
				sum = cumSum[j]-cumSum[i-1];
			}
			if (sum>max)
			{
				max=sum;
			}

		}
	}
	cout<<max<<endl;

	return 0;
}