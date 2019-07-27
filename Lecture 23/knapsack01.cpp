#include <bits/stdc++.h>
using namespace std;

int knapsack(int wt[3],int val[3],int capacity){

	int dp[4][capacity+1];
	for (int i = 0; i < 4; ++i)
	{
		for (int w = 0; w <= capacity; w++)
		{
			if(i==0 || w==0){
				dp[i][w]=0;
			}

			else if(w < wt[i-1]){
				dp[i][w]=dp[i-1][w];
			}

			else{
				int without_including = dp[i-1][w];
				int including = dp[i-1][w-wt[i-1]]+val[i-1];

				dp[i][w] = max(including, without_including);
			}
			cout<<dp[i][w]<<" ";


		}
		cout<<endl;
	}
	return dp[3][capacity];


}


int main(int argc, char const *argv[])
{
	int wt[3] = {1,2,3};
	int val[3] = {30,50,60};
	int W = 5;

	int result = knapsack(wt,val,W);
	cout<<result<<endl;

	return 0;
}