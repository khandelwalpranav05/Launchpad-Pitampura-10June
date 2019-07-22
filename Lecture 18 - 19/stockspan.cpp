#include<iostream>
#include <stack>
using namespace std;

void stockSpan(int arr[7], int n){
	int *result = new int[n];
	stack<int> st;

	for (int day = 0; day < n; day++)
	{	int curr_val = arr[day];

		while(!st.empty() &&  curr_val > arr[st.top()]){
			st.pop();
		}
		
		int betterDay = st.empty()? day : st.top();
		result[day] =  day- betterDay;
		st.push(day);
	}

	for (int i = 0; i < n; ++i)
	{
		cout<<result[i]<<" ";
	}
	cout<<endl;
}

int main(int argc, char const *argv[])
{
	int arr[7] = {100, 50, 40, 60, 30, 10, 90};
	int n = 7;
	stockSpan(arr, n);
	return 0;
}