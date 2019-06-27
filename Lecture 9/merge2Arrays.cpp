#include<iostream>
using namespace std;

void merge(int* a, int *b, int ea, int eb){
	int c[1000]={0};
	int a1 = 0, b1=0, c1=0;
	while(a1<ea && b1< eb){
		if(a[a1]<=b[b1]){
			c[c1]=a[a1];
			a1++;
			c1++;
		}
		else{
			c[c1]=b[b1];
			c1++;
			b1++;
		}
	}

	while(a1<ea){
		c[c1]=a[a1];
		a1++;
		c1++;
	}
	while(b1<eb){
		c[c1]=b[b1];
		b1++;
		c1++;
	}
	for (int i = 0; i < c1; i++)
	{
		cout<<c[i]<<" ";
	}


}
int main(int argc, char const *argv[])
{
	int a[5] = {1,2,6,9,12};
	int b[7] = {1,5,7,13,16, 19, 20};
	merge(a,b, 5,7);

	return 0;
}