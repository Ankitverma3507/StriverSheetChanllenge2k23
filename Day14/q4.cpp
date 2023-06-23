#include <bits/stdc++.h>
using namespace std;
// Brute Force Approach to find largest rectangle area in Histogram
int largestarea(int arr[], int n) {
  int maxArea = 0;
  for (int i = 0; i < n; i++) {
    int minHeight = INT_MAX;
    for (int j = i; j < n; j++) {
      minHeight = min(minHeight, arr[j]);
      maxArea = max(maxArea, minHeight * (j - i + 1));
    }
  }
  return maxArea;
}
int main() {
  int arr[] = {2, 1, 5, 6, 2, 3, 1};
  int n = 7;
  cout << "The largest area in the histogram is " << largestarea(arr, n); // Printing the largest rectangle area
  return 0;
}









//////////////////////////////////////better solution
//IF INTERVIEWER TELL YOU TO OPTIMISE IT FURTHER THAN ONLY TELL HIM NEXT SOLTN OTHERWISE NOT
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n= heights.size();
        vector<int> leftsmall(n), rightsmall(n);
        stack<int>st;

        for(int i=0; i<n; i++){
            while(!st.empty() and heights[st.top()]>= heights[i])
            st.pop();

            if(st.empty())
            {leftsmall[i]=0;}
            else
            {
                leftsmall[i]= st.top()+1;
            }
            st.push(i);
        }

        while(!st.empty()) st.pop();

        for(int i=n-1; i>=0; i--){
            while(!st.empty() and heights[st.top()]>= heights[i]){
                st.pop();
            }

            if(st.empty())
            rightsmall[i]= n-1;
            else{
                rightsmall[i]= st.top()-1;
            }
            st.push(i);
        }


        int maxans=0; 
        for(int i=0 ;i <n; i++){
            maxans= max(maxans, heights[i]*(rightsmall[i]- leftsmall[i] +1));
        }
        return maxans;
    }
};











//////////////////////////////////////optimise solution
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int>st;
        int maxA=0;
        int n= heights.size();
        for(int i=0; i<=n; i++){
            while(!st.empty() and (i==n or heights[st.top()]>= heights[i])){
                int height= heights[st.top()];
                st.pop();
                int width;
                if(st.empty()){
                    width=i;
                }
                else{
                    width= i-st.top() -1;
                }
                maxA= max(maxA, width*height);
            }
            st.push(i);
        }
        return maxA;
    }
};