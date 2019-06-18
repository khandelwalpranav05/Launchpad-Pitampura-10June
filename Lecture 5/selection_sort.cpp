#include<iostream>
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

int main(){
	int arr[] = {5,4,3,2,1};

	// cout<<(sizeof(arr)/sizeof(int))<<endl;

	display(arr,5);

	for(int i=0;i<4;i++){
		for(int j=i+1;j<5;j++){
			//comparison
			if(arr[i] > arr[j]){
				swap(arr,i,j);
			}
		}

		display(arr,5);
		cout<<"*****************"<<endl;
	}

	return 0;
}