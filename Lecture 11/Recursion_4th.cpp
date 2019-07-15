#include<iostream>
#include<algorithm>

using namespace std;

void merge(int arr[],int s,int e){

	int mid = (s+e)/2;
	int i = s;
	int j = mid+1;

	int temp[e-s+1];
	int k = 0;

	while(i<=mid and j<=e){
		if(arr[i]<arr[j]){
			temp[k] = arr[i];
			i++;
			k++;
		}else{
			temp[k++] = arr[j++];
		}
	}

	while(i<=mid){
		temp[k++] = arr[i++];
	}

	while(j<=e){
		temp[k++] = arr[j++];
	}

	int p=0;
	for(int x=s;x<=e;x++){
		arr[x] = temp[p];
		p++;
	}

	// for(int x = 0;x <=e-s;x++){
	// 	arr[x + s] = temp[x]; 
	// }
}


void mergeSort(int arr[],int s,int e){
	if(s>=e){
		return;
	}

	int mid = (s + e)/2;

	mergeSort(arr,s,mid);
	mergeSort(arr,mid+1,e);

	merge(arr,s,e);
}

void mappedString(char arr[],int i,string ans){
	if(arr[i]=='\0'){
		cout<<ans<<endl;
		return;
	}

	char ch = arr[i];
	int ch_int = ch - '0';

	ch =ch - '0' + 'A' - 1;
	mappedString(arr,i+1,ans+ch);

	if(arr[i+1]!='\0'){
		char second_ch = arr[i+1];
		int second_int = second_ch - '0';

		int two_digit = ch_int*10 + second_int;

		if(two_digit<= 26){

			char two_char = two_digit + 'A' - 1;
			mappedString(arr,i+2,ans + two_char);
		}
	}

}

int binarySearch(int arr[],int size,int data){
	int s = 0;
	int e = size-1;

	while(s<=e){
		int mid = (s+e)/2;

		if(arr[mid]==data){
			return mid;
		}else if(arr[mid]>data){
			e = mid - 1;
		}else{
			s = mid+1;
		}
	}

	return -1;
}

float squareRoot(int n,int p){
	int s = 0;
	int e = n;
	float ans;

	while(s<=e){
		int mid = (s+e)/2;

		if(mid*mid==n){
			ans = mid;
			return ans;
		}else if(mid*mid>n){
			e = mid-1;
		}else{
			ans = mid;
			s = mid+1;
		}
	}

	float inc = 0.1;

	while(p!=0){
		ans+=inc;

		while(ans*ans<=n){
			ans+=inc;
		}

		ans= ans-inc;
		inc = inc/10;
		p--;
	}
	
	return ans;
}

bool isSumSet(int arr[],int n,int sum){
	
}

int main(){

	// int arr[] = {6,5,4,3,2,1};
	// sort(arr,arr+4);

	// for(int i=0;i<6;i++){
	// 	cout<<arr[i]<<" ";
	// }
	// cout<<endl;

	// mergeSort(arr,0,5);

	// for(int i=0;i<6;i++){
	// 	cout<<arr[i]<<" ";
	// }
	// cout<<endl;

	// char ch = '2';

	// if(ch){
	// 	cout<<"YEs"<<endl;
	// }

	// char c = '0';

	// if(c){
	// 	cout<<"NO"<<endl;
	// }

	// char arr[] = "123";
	// mappedString(arr,0,"");

	// int arr[] = {1,2,3,4,5,6,7};
	// int data = 5;

	// cout<<binarySearch(arr,7,5)<<endl;

	cout<<squareRoot(10,3)<<endl;
	return 0;
}