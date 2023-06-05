#include <bits/stdc++.h>
using namespace std;
/////////////////////////////////better approach
pair<int,int> missingAndRepeating(vector<int> &a, int n)
{
	//  int n= A.size();
//    int n = a.size(); // size of the array
    int hash[n + 1] = {0}; // hash array

    //update the hash array:
    for (int i = 0; i < n; i++) {
        hash[a[i]]++;
    }

    //Find the repeating and missing number:
    int repeating = -1, missing = -1;
    for (int i = 1; i <= n; i++) {
        if (hash[i] == 2) repeating = i;
        else if (hash[i] == 0) missing = i;

        if (repeating != -1 && missing != -1)
            break;
    }
    return {missing, repeating};
}








#include <bits/stdc++.h>
using namespace std;
/////////////////////////////////optimal app1

pair<int,int> missingAndRepeating(vector<int> &arr, int m)
{
	// Write your code here 
    long long n= arr.size();
    long long SN= (n*(n+1))/2;
    long long SN2= (n*(n+1)* (2*n+1))/6;
    long long s=0, s2=0;
    for(int i=0; i<n; i++){
        s += arr[i];
        s2+= (long long)arr[i] *(long long)arr[i];
    }

    long long val1= s-SN;
    long long val2= s2- SN2;
     val2= val2/ val1;
     
     long long x= (val1+ val2)/2;
     long long y= x-val1;
     return {(int)y, (int)x};
	
}
