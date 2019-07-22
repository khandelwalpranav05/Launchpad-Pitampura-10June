#include<iostream>
#include <unordered_map>
using namespace std;
int main(int argc, char const *argv[])
{
	unordered_map<string, int> m;
   
	m["mango"] = 200;

	pair <string,int> foo("grapes",500);
	m.insert(foo);
    string a ="pear";
	m.insert(make_pair(a,600));

	for(auto i = m.begin(); i!=m.end(); i++){
		cout<<i->first<<" "<<i->second<<endl;
	}
	return 0;
}
