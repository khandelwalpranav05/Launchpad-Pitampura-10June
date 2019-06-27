#include<iostream>
#include <sstream>
using namespace std;

string keypad[] = {"yz",".","abc","def","ghi","jkl","mno","pqrs","tuv","wx"};

void phoneKeypad(string str, string ans){
	if (str.length()==0)
	{
		cout<<ans<<endl;
		return;
	}

	char ch = str[0];
	string code = keypad[ch-'0'];
	string ros = str.substr(1);
	for (int i = 0; i < code.length(); i++)
	{
		phoneKeypad(ros, ans+code[i]);
	}

}

int main(int argc, char const *argv[])
{
	phoneKeypad("23","");
	return 0;
}