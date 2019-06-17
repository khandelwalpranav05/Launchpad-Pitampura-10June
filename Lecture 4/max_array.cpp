#include <iostream>
#include <climits>

using namespace std;

void display(int arr[],int size){
	for(int i=0;i<size;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}

int main(){
	
	int arr[] = {1,2,3,56,5};

	display(arr,5);

	int max = INT_MIN;

	for(int i=0;i<5;i++){
		if(max<arr[i]){
			max = arr[i];
		}
	}

	cout<<"Max value is "<<max<<endl;
}