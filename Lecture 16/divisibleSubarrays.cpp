#include<bits/stdc++.h>

using namespace std;
int main(int argc, char const *argv[])
{
	int n =5;
	//cin>>n;
	int arr[5]={5, 5, 5, 5, 5};
	int cum[6]={0};
	for(int i=1;i<6;i++){
		cum[i] = cum[i-1]+arr[i-1];
		cum[i] = cum[i]%n;
	}
	int freq[5]={0};

	for (int i = 0; i < 6; ++i)
	{
		freq[cum[i]]++;
	}

	int goodsubarrays =0;
	for (int i = 0; i < n; i++)
	{
		int x = freq[i];
		int comb = (x*(x-1))/2;
		goodsubarrays+=comb;
	}
	cout<<goodsubarrays<<endl;


	return 0;
}