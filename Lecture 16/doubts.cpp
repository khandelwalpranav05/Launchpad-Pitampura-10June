#include<iostream>
#include <algorithm>

using namespace std;

void printPermutationsNoDuplicates(string ques,string ans){
	if(ques.length()==0){
		cout<<ans<<endl;
		return;
	}

	for(int i=0;i<ques.length();i++){
		char ch = ques[i];
		string ros = ques.substr(0,i) + ques.substr(i+1);

		bool flag = true;

		for(int j= i+1;j< ques.length(); j++){
			if(ques[j]==ch){
				flag = false;
			}
		}

		if (flag){
			printPermutationsNoDuplicates(ros,ans+ch);
		}

	}
}

void printLexicographicalNumber(int c,int n){
	if(c>n){
		return;
	}

	cout<<c<<endl;


	if(c==0){
		for(int i=1;i<=9;i++){
			printLexicographicalNumber(10*c + i,n);
		}
	}else{
		for(int i=0;i<=9;i++){
			printLexicographicalNumber(10*c + i,n);
		}
	}
}

int sanketAndStrings(string str, int k){
	int left = 0;
	int ans = 0;

	int count[2] = {0};

	for(int i=0;i<str.length();i++){
		count[str[i]-'a']++;

		if(min(count[0],count[1]) > k){
			count[str[left] - 'a']--;
			left++;
		}else{
			ans++;
		}
	}

	return ans;
}

int uniqueNumber3(int arr[],int n){
	int count[32] = {0};

	for(int i=0;i<n;i++){

		int j = 0;
		int no = arr[i];

		while(no!=0){
			count[j]+=(no&1);
			no = no>>1;

			j++;
		}
	}

	int pow = 1;
	int ans = 0;
	for(int i=0;i<32;i++){
		count[i] %= 3;

		ans += count[i]*pow;
		pow = pow*2;
	}

	return ans;
}

int numberCompare(string x,string y){

	string one = x+y;
	string two = y + x;

	if(one>two){
		return 1;
	}else{
		return 0;
	}
}

void largestNumber(string arr[],int n){
	sort(arr,arr+n,numberCompare);

	for(int i=0;i<n;i++){
		cout<<arr[i];
	}
	cout<<endl;
}

int main(){

	// printPermutationsNoDuplicates("caa","");

	// printLexicographicalNumber(0,23);

	// cout<<sanketAndStrings("ababa",2)<<endl;

	// int arr[] = {1,1,1,2,2,2,3};
	// int n = 7;

	// cout<<uniqueNumber3(arr,n)<<endl;

	string arr[] ={"9","98"};
	largestNumber(arr,2);
	return 0;
}