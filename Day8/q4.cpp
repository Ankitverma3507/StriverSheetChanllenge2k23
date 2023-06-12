//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


// } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    
    static bool comp(Item a, Item b){
        double ra= (double)a.value/(double) a.weight;
        double rb= (double)b.value/(double) b.weight;
        return ra>rb;
        
        
    }
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        sort(arr, arr+n,comp);
        
        int currentwt=0;
        double ans=0.0;
        for(int i=0; i<n; i++){
            if(currentwt + arr[i].weight<= W ){
                currentwt+= arr[i].weight;
                ans+= arr[i].value;
            }
            
            else {
                int remain= W- currentwt;
                ans += (arr[i].value/(double) arr[i].weight) *(double) remain;
                break;
            }
        }
        return ans;
    }
        
};


//{ Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}
// } Driver Code Ends