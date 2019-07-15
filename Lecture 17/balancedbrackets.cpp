#include<iostream>
#include <stack>
using namespace std;

bool isbalanced(string str){
	stack<char> st;
	for (int i = 0; i < str.size(); i++)
	{
		char ch = str[i];
		if(ch == '('){
			st.push(ch);
		}
		else{

			if(ch == ')'){
				if(st.empty()){
					return false;
				}
				st.pop();
			}
		}
	}

	return st.empty();
}


int main(int argc, char const *argv[])
{	
	string str;
	str = "((a+b)+(c+d))";
	string str2 = ")(())()";
	string str3 = "(())(()";

	if(isbalanced(str3)){
		cout<<str3<<" is balanced"<<endl;
	}
	else{
		cout<<str3<<" is not balanced"<<endl;
	}
	
	return 0;
}