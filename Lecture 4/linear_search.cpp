#include <iostream>
#include <climits>

using namespace std;

int main(){
	
	int size;
	cin>>size;

	int arr[size];

	for(int i=0;i<size;i++){
		cin>>arr[i];
	}

	int item;
	cin>>item;

	int counter = 0;
	while(counter<size){
		if(arr[counter]==item){
			cout<<"Found at "<<counter<<endl;
			break;
		}
		counter++;
	}

	if(counter==size){
		cout<<"Not Found"<<endl;
	}
}