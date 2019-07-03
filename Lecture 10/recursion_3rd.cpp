#include<iostream>

using namespace std;
void subseq(string str,string ans)
{
	if(str.length()==0)
	{
		cout<<ans<<endl;
		return;
	}
	char ch=str[0];
	string ros=str.substr(1);
	subseq(ros,ans);
	subseq(ros,ans+ch);
}

string removeDuplicate(string str){
	if(str.length()==0){
		return "";
	}

	char ch = str[0];
	string ros = str.substr(1);
	string recursion_result = removeDuplicate(ros);

	if(ch==recursion_result[0]){
		return recursion_result;
	}

	return ch + recursion_result;
}

string moveXToEnd(string str){
	if(str.length()==0){
		return "";
	}

	char ch = str[0];
	string ros = str.substr(1);
	string recursion_result = moveXToEnd(ros);

	if(ch=='x'){
		return recursion_result + ch;
	}else{
		return ch + recursion_result;
	}
}

int countBoardPath(int start,int end){

	if(start==end){
		return 1;
	}

	if(start>end){
		return 0;
	}

	int count = 0;

	for(int i=1;i<=6;i++){
		count+=countBoardPath(start+i,end);
	}

	return count;	
}

int countMazePath(int sr,int sc,int er,int ec){
	if(sr==er and sc==ec){
		return 1;
	}

	if(sr>er or sc>ec){
		return 0;
	}

	int count =0;

	count+= countMazePath(sr+1,sc,er,ec);
	count+=countMazePath(sr,sc+1,er,ec);

	return count;
}

void printPermutations(string ques,string ans){
	if(ques.length()==0){
		//base case
		cout<<ans<<endl;
		return;
	}

	//Recursion Case

	for(int i=0;i<ques.length();i++){
		char ch = ques[i];
		string ros = ques.substr(0,i) + ques.substr(i+1);

		printPermutations(ros,ans+ch);
	}
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

// void mappedString(char ques[],string ans){
// 	if(){
// 		//Base Case

// 	}

// 	//Recursion Case
// 	char ch = ques[0];

// }

int main(){
// subseq("abc","");

	// cout<<removeDuplicate("aaabbbcccd")<<endl;
	// cout<<removeDuplicate("eaaabbcc")<<endl;

	// cout<<moveXToEnd("xababbaxbhxx")<<endl;

	// cout<<countBoardPath(0,3)<<endl;

	// cout<<countMazePath(0,0,2,2)<<endl;

	// printPermutations("abc","");

	char ch = '2';
	int ch_int = ch - '0';
	cout<<ch_int<<endl; // Output 2

	char alpha_ch = '2';
	alpha_ch = alpha_ch - '0' + 'A' - 1;
	cout<<alpha_ch<<endl; // Output B

	return 0;
}