#include <bits/stdc++.h> 
using namespace std;
//////////////////////////optimal for both varity 1 and varity 2
string read(int n, vector<int> book, int target)
{
    // Write your code here.
    unordered_map<int,int>mpp;
    for(int i=0; i<n; i++){
        int no= book[i];
        int nedeed= target-no;
        if(mpp.find(nedeed) != mpp.end())
        return "YES";

        mpp[no]=i;
    }
    return "NO";
}




#include <bits/stdc++.h> 
using namespace std;
//////////////////////////optimal for only varity1 TWO POINTER APPROACH

string read(int n, vector<int> book, int target)
{
    // Write your code here.
    sort(book.begin(), book.end());
    int left=0; int right= n-1;
    while(left<right){
        if(book[left]+ book[right] == target) return "YES";
        else if(book[left]+ book[right] < target){
            left++;
        }

        else{
            right--;
        }
    }
    return "NO";
}
