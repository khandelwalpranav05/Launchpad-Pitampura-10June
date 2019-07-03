#include<iostream>
using namespace std;
int main(int argc, char const *argv[])
{	int n=101;
	int sieve[101] = {0};
	for(int i=1; i<n; i=i+2){
		sieve[i]=1;
	}
	sieve[0]=0;
	sieve[1]=0;
	sieve[2]=1;

	for (int i = 3; i < 10; i+=2)
	{	if(sieve[i]!=0){
			for (int j = i*2; j < n; j+=i)
			{
				sieve[j]=0;
			}
		}
		
	}

//optimization
	for (int i = 3; i < 10; i+=2)
	{	if(sieve[i]!=0){
			for (int j = i*i; j < n; j+=i*2)
			{
				sieve[j]=0;
			}
		}
		
	}

// print prime no. from a to b

	int a, b;
	a = 30;
	b = 90;
	for (int i = a; i <=b ; ++i)
	{
		if(sieve[i]){
			cout<<i<<" ";
		}
	}

	return 0;
}