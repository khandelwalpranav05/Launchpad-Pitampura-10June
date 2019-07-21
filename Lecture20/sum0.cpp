#include<bits/stdc++.h>
#include <unordered_map>
using namespace std;
int main(int argc, char const *argv[])
{
	int arr[9] = {1,2,3,-1,4,-5,-3,4,6};

	unordered_map<int,int>m;

	for (int i = 0; i < 9; ++i)
	{
		m.insert(make_pair(arr[i],1));
	}

	int countPair =0 ;

	for (int i = 0; i < 9; ++i)
	{
		int x = arr[i];
		int y = 0 - arr[i];

		if(m.count(y)>0){
			cout<<x<<" "<<y<<endl;
			countPair++;

		}
	}
	countPair/=2;
	cout<<countPair<<endl;

}







