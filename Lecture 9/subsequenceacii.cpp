#include<iostream>
#include <sstream>
using namespace std;
string IntToString(int a)
{
    ostringstream temp;
    temp << a;
    return temp.str();
}

void subseq(string str, string ans){
	if(str.length()==0){
		cout<<ans<<endl;
		return;
	}

	char ch = str[0];
	string ros = str.substr(1);

	subseq(ros, ans+ch);
	subseq(ros, ans);
	//subseq(ros, ans+ to_string((int)ch));
	subseq(ros, ans+ IntToString((int)ch));


}

int main(int argc, char const *argv[])
{	
	subseq("ab","");
	
	return 0;
}