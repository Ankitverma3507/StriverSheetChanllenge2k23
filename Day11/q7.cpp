#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template in C++

class Solution
{

public:
    bool allocationisPossible(int A[], int pages, int students, int n)
    {
        int cnt = 0;
        int sumAllocated = 0;
        for (int i = 0; i < n; i++)
        {
            if (sumAllocated + A[i] > pages)
            {
                cnt++;
                sumAllocated = A[i];
                if (sumAllocated > pages)
                    return false;
            }
            else
            {
                sumAllocated += A[i];
            }
        }
        if (cnt < students)
            return true;
        return false;
    }
    // Function to find minimum number of pages.
    int findPages(int A[], int N, int M)
    {
        // code here
        if (M > N)
            return -1;
        int low = A[0];
        int high = 0;

        for (int i = 0; i < N; i++)
        {
            high += A[i];
            low = min(low, A[i]);
        }

        while (low <= high)
        {
            int mid = (low + high) >> 1;

            if (allocationisPossible(A, mid, M, N))
            {
                high = mid - 1;
            }
            else
                low = mid + 1;
        }
        return low;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int A[n];
        for (int i = 0; i < n; i++)
        {
            cin >> A[i];
        }
        int m;
        cin >> m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends