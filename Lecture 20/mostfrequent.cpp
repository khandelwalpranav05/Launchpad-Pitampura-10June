#include<bits/stdc++.h>
#include <unordered_map>
using namespace std;
int main(int argc, char const *argv[])
{
	int arr[15] ={1,2,3,1,4,2,5,6,1,2,1,4,5,2,3};
	unordered_map<int, int> m;
	for (int i = 0; i < 15; ++i)
	{
		m[arr[i]]++;
	}
	int max=0; int key = -1; int value = 0;
	for (auto it : m)
	{
		if(it.second > max){
			key = it.first;
			value = it.second;
			max = it.second;
		}
	}
	cout<< key<<" "<<value<<endl;

	return 0;
}