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

	// int max = INT_MIN;

	// int currSum = arr[0];

	// for(int i=1;i<5;i++){

	// }

	display(arr,5);
	int counter = 1;

	while(counter<5){
		for(int i=0;i<5 - counter;i++){
			if(arr[i]>arr[i+1]){
				swap(arr,i,i+1);
			}
		}

		display(arr,5);
		cout<<"*********************"<<endl;
		counter++;
	}


	return 0;
}