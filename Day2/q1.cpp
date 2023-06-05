#include <bits/stdc++.h>
using namespace std;
////////////////////////////////////////optimal approach
class Solution {

    private:
    void transpose(vector<vector<int>>& matrix){
        int n= matrix.size();
        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        return ;
    }
public:
    void rotate(vector<vector<int>>& matrix) {
        transpose(matrix);
        int n= matrix.size();
        for(int i=0; i<n; i++){
            reverse(matrix[i].begin(), matrix[i].end());
        }
        return;
    }
};