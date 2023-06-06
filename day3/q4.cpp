/////////////////////////extended version of Moores voting algorithm
#include<bits/stdc++.h>
using namespace std;
vector<int> majorityElementII(vector<int> &arr)
{
    // Write your code here
    int n= arr.size();
    int cnt1=0, cnt2=0;
    int ele1, ele2;

    for(int i=0; i<n; i++){
        if(cnt1==0 and arr[i] != ele2){
            cnt1=1;
            ele1= arr[i];
        }

        else if(cnt2==0 and arr[i] != ele1){
            cnt2=1;
            ele2= arr[i];
        }

        else if(ele1== arr[i]) cnt1++;
        else if( ele2== arr[i]) cnt2++;

        else {
            cnt1--;
            cnt2--;
        }

    }

    int cntck1=0;
    int cntck2=0;
    vector<int> ls;
    for(int i=0; i<n; i++){
        if(arr[i]== ele1)
        cntck1++;

         if(arr[i]== ele2)
        cntck2++;
    }

    int mini= (int)(n/3) +1;
    if(cntck1>= mini) ls.push_back(ele1);
    if(cntck2>= mini) ls.push_back(ele2);
    sort(ls.begin(), ls.end());
    return ls;
    // return {0,0};

}