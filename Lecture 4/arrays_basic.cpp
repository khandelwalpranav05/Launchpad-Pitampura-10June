#include <iostream>
#include <climits>

using namespace std;

void swap(int arr[],int i,int j){
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

void display(int arr[],int size){
	for(int i=0;i<size;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}

void reverse(int arr[],int size){
	int left = 0;
	int right = size-1;

	while(left<=right){
		swap(arr,left,right);
		left++;
		right--;
	}
}

int main(){

	// int arr[10];
	// cout<<sizeof(arr)<<endl;

	// int arr[5] = {1,2,3,4,5};
	// cout<<arr[2]<<endl;

	// cout<<arr<<endl;
	// cout<<(arr+1)<<endl;

	// int arr[] = {1,2,3,4,5,6,7,8,9};

	// cout<<sizeof(arr)<<endl;

	// int arr[5] = {1,2,3,4,5,6}; // Error

	// int a = 23;
	// int b = 46;

	// int temp = a;
	// a = b;
	// b = temp;

	// cout<<"a is "<<a<<endl;
	// cout<<"b is "<<b<<endl;

	// int arr[] = {1,2,3,4,5};

	// display(arr,5);
	// swap(arr,0,4);
	// display(arr,5);


	return 0;
}