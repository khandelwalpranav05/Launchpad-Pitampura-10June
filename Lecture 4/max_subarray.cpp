#include <iostream>
#include <climits>

using namespace std;

int main(){
		int arr[4] = {-1,2,3,-4,4};

	int max= INT_MIN;

	for(int i=0;i<4;i++){
		for(int j=i;j<4;j++){
			int sum = 0;
			for(int k=i;k<=j;k++){
				// cout<<arr[k]<<" ";

				sum+=arr[k]
			}

			if(max<sum){
				max = sum;
			}

			// cout<<endl;
		}
	}

	cout<<"Max is "<<max<<endl;
}