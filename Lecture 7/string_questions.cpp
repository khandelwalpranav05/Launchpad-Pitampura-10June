#include<iostream>
#include <climits>

using namespace std;

void reverse(){
	string str = "Pranav";

	int left = 0;
	int right = str.length() - 1;

	while(left<=right){
		char ch = str[left];
		str[left] = str[right];
		str[right] = ch;
		left++;
		right--;
	}

	cout<<str<<endl;
}

bool isPalindrome(){
	string str = "naman";

	int left = 0;
	int right = str.length() - 1;

	while(left<=right){
		if(str[left]!=str[right]){
			return false;
		}

		left++;
		right--;
	}

	return true;
}

void toggleCharacter(){
	string str = "HeLlo";

	for(int i=0;i<str.length();i++){
		if(str[i]<='Z' and str[i]>='A'){
			str[i] = str[i] + 'a' - 'A';
		}else{
			str[i] = str[i] + 'A' - 'a';
		}
	}

	cout<<str<<endl;
}

int maxCharacter(){
	string str = "aaabbaaccddde";
	int freq[256] = {0};

	for(int i=0;i<str.length();i++){
		char ch = str[i];

		freq[ch]++;
	}

	int max = INT_MIN;

	for(int i=0;i<256;i++){
		if(freq[i]>max){
			max = freq[i];
		}
	}

	return max;
}

void substrings(){
	string str = "Hello";

	// cout<<str.substr(1,3)<<endl;

	for(int i=0;i<str.length();i++){
		for(int j=1;j<=str.length()-i;j++){
			cout<<str.substr(i,j)<<endl;
		}
	}
}

int main(){

	// reverse();
	// cout<<isPalindrome()<<endl;
	// toggleCharacter();
	// cout<<maxCharacter()<<endl;
	substrings();
	return 0;
}