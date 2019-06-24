#include <bits/stdc++.h>
using namespace std;

void swap(int arr[], int i, int j){
	int temp = arr[i];
	arr[i]=arr[j];
	arr[j]=temp;
}
int main(int argc, char const *argv[])
{
	int arr[9] = {0,1,0,2,1,0,2,1,0};
	int low =0, mid =0;
	int high = 8;

	while(mid<=high){
		if(arr[mid]==0){
			swap(arr,mid,low);
			low++;
			mid++;
		}
		else if(arr[mid]==1){
			mid++;
		}
		else if(arr[mid]==2){
			swap(arr,mid,high);
			high--;
		}
	}

	for (int i = 0; i < 9; ++i)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;


	return 0;
}