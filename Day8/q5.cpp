//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
/////////////////////////////////////////dp solution
// } Driver Code Ends
class Solution
{

public:
	int f(int ind, int coins[], int M, int V, vector<vector<int>> &dp)
	{
		if (ind == M or V < 0)
			return 1e9;
		if (V == 0)
			return 0;
		if (dp[ind][V] != -1)
			return dp[ind][V];

		// int pick, notpick;
		int maxi = 1e9;
		if (V >= coins[ind])
		{
			int pick = 1 + f(ind, coins, M, V - coins[ind], dp);
			maxi = min(maxi, pick);
		}

		int notpick = 0 + f(ind + 1, coins, M, V, dp);

		return dp[ind][V] = min(maxi, notpick);
	}
	int minCoins(int coins[], int M, int V)
	{
		// Your code goes here
		// sort(coins, coins,M);

		vector<vector<int>> dp(M + 1, vector<int>(V + 1, -1));
		if (f(0, coins, M, V, dp) >= 1e9)
			return -1;
		return f(0, coins, M, V, dp);
	}
};

//{ Driver Code Starts.
int main()
{

	int t;
	cin >> t;
	while (t--)
	{
		int v, m;
		cin >> v >> m;

		int coins[m];
		for (int i = 0; i < m; i++)
			cin >> coins[i];

		Solution ob;
		cout << ob.minCoins(coins, m, v) << "\n";
	}
	return 0;
}

// } Driver Code Ends