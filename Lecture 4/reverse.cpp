#include <iostream>
#include <climits>

using namespace std;


void swap(int arr[],int i,int j){
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
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

void display(int arr[],int size){
	for(int i=0;i<size;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}


int main(){

	int arr[] = {1,2,3,4,5,6};
	display(arr,6);
	reverse(arr,6);
	display(arr,6);

	return 0;

}