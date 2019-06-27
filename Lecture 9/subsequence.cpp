#include<iostream>

using namespace std;

void subseq(string str, string ans){
	if(str.length()==0){
		cout<<ans<<endl;
		return;
	}

	char ch = str[0];
	string ros = str.substr(1);

	subseq(ros, ans+ch);
	subseq(ros, ans);

}

int main(int argc, char const *argv[])
{	
	subseq("abc","");
	
	return 0;
}