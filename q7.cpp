#include <bits/stdc++.h> 
using namespace std;
void insert(stack<int> &st, int temp){
	if(st.size()==0 or st.top()<= temp){
		st.push(temp);
		return;
	}

	int val= st.top();
	st.pop();
	insert(st,temp);
	st.push(val);
	return;
}
void sortStack(stack<int> &st)
{
	// Write your code here
	if(st.size()==1) return;

	int temp= st.top();
	st.pop();
	sortStack(st);
	insert(st,temp);
	return;

}