#include<iostream>

using namespace std;

int sumTilln(int n){
	if(n==0){
		return 0;
	}

	int sumTilln1 = sumTilln(n-1);

	int total_sum = sumTilln1 + n;
	return total_sum;
}

int factorial(int n){
	if(n==0){
		return 1;
	}

	int factorialn1 = factorial(n-1);
	int total_fact = n*factorialn1;
	return total_fact;
}

int fibonacci(int n){
	if(n==1 || n==0){
		return n;
	}

	int fn1 = fibonacci(n-1);
	int fn2 = fibonacci(n-2);

	int fn = fn1 + fn2;
	return fn;
}

void printD(int n){
	if(n==0){
		return;
	}

	cout<<n<<endl;
	printD(n-1);
}

void printI(int n){
	if(n==0){
		return;
	}

	printI(n-1);
	cout<<n<<endl;
}

void printID(int n){
	if(n==0){
		return;
	}

	cout<<n<<endl;
	printID(n-1);
	cout<<n<<endl;
}

int power(int n,int p){
    if(p==0){
        return 1;
    }

    int powern1 = power(n,p-1);
    int total_power = n*powern1;
    return total_power;
}

//bool isSorted(int arr[],int size,int idx){
//
//    if(idx==(size-1)){
//        return true;
//    }
//
//    bool restArr = isSorted(arr,size,idx+1);
//
//    if(arr[idx]<arr[idx+1] and restArr==true){
//        return true;
//    }
//
//    return false;
//}

bool isSorted(int *arr,int size){
    if(size==1){
        return true;
    }

    bool restArr = isSorted(arr+1,size-1);

    if(arr[0]<arr[1] and restArr){
        return true;
    }

    return false;
}

int linearSearch(int arr[],int size,int i,int data){
	if(i==size){
		return -1;
	}

	if(arr[i]==data){
		return i;
	}

	int rest = linearSearch(arr,size,i+1,data);
	return rest;
}

int lastIndex(int arr[],int size,int i,int data){
	if(i==size){
		return -1;
	}

	int rest = lastIndex(arr,size,i+1,data);

	if(rest!=-1){
		return rest;
	}else{
		if(arr[i]==data){
			return i;
		}else{
			return -1;
		}
	}
}

int main(){

	// cout<<sumTilln(4)<<endl;

	// cout<<factorial(5)<<endl;

	// cout<<fibonacci(4)<<endl;

	// printD(5);
	// printI(5);
	// printID(5);

	// int n=5;
 	// int p = 3;
	// cout<<power(n,p)<<endl;

    // int arr[] = {1,2,3,4,5};
    // cout<<isSorted(arr,5)<<endl;

    // int arr[] = {12,15,48,86,13};
    // int data = 86;
    // int size = 5;
	// cout<<linearSearch(arr,size,0,data)<<endl;
	
	// int arr[] = {12,15,86,15,11};
	// int size= 5;
	// int data = 15;
	// cout<<lastIndex(arr,size,0,data)<<endl;

	return 0;
}