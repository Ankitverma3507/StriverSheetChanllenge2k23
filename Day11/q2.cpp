#include <bits/stdc++.h>
using namespace std;
////////////////////////////////////////////////////--brute force approach
int Findmedian(int arr[3][3], int row, int col)
{
    int median[row * col];
    int index = 0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            median[index] = arr[i][j];
            index++;
        }
    }

    return median[(row * col) / 2];
}
int main()
{
    int row = 3, col = 3;
    int arr[3][3] = {{1, 3, 8},
                     {2, 3, 4},
                     {1, 2, 5}};
    cout << "The median of the row-wise sorted matrix is: " << Findmedian(arr, row, col) << endl;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
////////////////////////////////////////////////////--optimal approach
class Solution
{

    int findlessnos(int assumedmedian, vector<vector<int>> &matrix)
    {
        int noOfsmallerele = 0;
        for (int i = 0; i < matrix.size(); i++)
        {
            int st = 0;
            int end = matrix[0].size() - 1;

            while (st <= end)
            {
                int mid = st + (end - st) / 2;
                if (matrix[i][mid] <= assumedmedian)
                {
                    st = mid + 1;
                }
                else
                    end = mid - 1;
            }
            noOfsmallerele += st;
        }
        return noOfsmallerele;
    }

public:
    int median(vector<vector<int>> &matrix, int R, int C)
    {
        // code here
        int n = R * C;
        int medianindex = n / 2;

        int st = 1;
        int end = 2000;

        while (st <= end)
        {
            int assumedmedian = st + (end - st) / 2;
            int lessernos = findlessnos(assumedmedian, matrix);
            if (lessernos <= medianindex)
            {
                st = assumedmedian + 1;
            }
            else
                end = assumedmedian - 1;
        }
        return st;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int r, c;
        cin >> r >> c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for (int i = 0; i < r; ++i)
            for (int j = 0; j < c; ++j)
                cin >> matrix[i][j];
        Solution obj;
        int ans = -1;
        ans = obj.median(matrix, r, c);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends