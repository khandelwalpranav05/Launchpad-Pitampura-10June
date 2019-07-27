#include <bits/stdc++.h>
#include <math.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int C[n];
		int L[n];

		for (int i = 0; i < n; i++)
		{	int cost;
			cin>>cost;
			C[i] = cost;
			
		}
		for (int i = 0; i < n; i++)
		{	int petrol;
			cin>>petrol;
			L[i] = petrol;
			
		}
		int minCost = C[0];
		long long int val =0;
		for (int i = 0; i < n; i++)
		{
			minCost = min(minCost, C[i]);
			val += minCost*L[i]; 
			//cout<<val<<endl;
		}

		cout<<val<<endl;

	}
	return 0;
}



