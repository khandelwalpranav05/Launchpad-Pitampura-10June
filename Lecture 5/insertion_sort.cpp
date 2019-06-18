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

	int arr[] = {5,3,2,1,4};

	int counter = 1;
	while(counter<5){
		for(int i=counter;i>0;i--){
			if(arr[i-1]>arr[i]){
				swap(arr,i-1,i);
			}else{
				break;
			}
		}

		counter++;
	}

	cout<<(sizeof(arr)/sizeof(int))<<endl;

	return 0;
}