#include <iostream>
#include<vector>
#include<stack>
using namespace std;
///////////////////////////////////////////////optimised
vector<int> prevSmaller(vector<int> &A) {
    int n= A.size();
    stack<int>st;
    vector<int>ans(n);
    
    for(int i=0; i<n; i++){
        while(!st.empty() and st.top()>= A[i])
        st.pop();
        
        if(i<n){
            if(st.empty()==false){
                ans[i]= st.top();
            }
            
            else{
                ans[i]= -1;
            }
        }
        st.push(A[i]);
    }
    return ans;
}
