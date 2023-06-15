#include <bits/stdc++.h>
using namespace std;
///////////////////////////////////_________->>>>>>>>>>>>>>>>not a optimal one
class Solution {
public:


    bool isSafe(int row, int col, vector<string> &board, int n){
        int duprow= row;
        int dupcol= col;


        ///////////////////////for left upper diag
        while(row>=0 and col>=0){
            if(board[row][col]=='Q')
            return false;

            row--;
            col--;
        }


        ///////////////////////for left side of row
        col= dupcol;
        row= duprow;
        while(col>=0){
            if(board[row][col]=='Q')
            return false;

            col--;
        }

        ///////////////////////fow left lower diag 
        col= dupcol;
        row= duprow;
        while(col>=0 and row<n){
            if(board[row][col]=='Q')
            return false;
            row++;
            col--;
        }

        return true;
    }

    void f(int col, vector<vector<string>>&ans, vector<string>&board, int n){
        if(col==n){
            ans.push_back(board);
            return;
        }

        for(int row=0; row<n; row++){
            if(isSafe(row,col,board,n)){
                board[row][col]= 'Q';
                f(col+1, ans,board, n);
                board[row][col]= '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n, '.');
        for(int i=0; i<n; i++)
        board[i]= s;

        f(0, ans, board,n);
        return ans;
    }
};











#include <bits/stdc++.h>
using namespace std;
///////////////////////////////////_________->>>>>>>>>>>>>>>> optimal 

class Solution {
public:


 
    void f(int col, vector<vector<string>>&ans, vector<string>&board, vector<int> &leftrow, 
    vector<int> &uppdiag,vector<int> &lowdiag,  int n){
        if(col==n){
            ans.push_back(board);
            return;
        }

        for(int row=0; row<n; row++){
            if(leftrow[row]==0 and lowdiag[row+col]==0 and uppdiag[((n-1) + (col-row))]==0 ){
                board[row][col]= 'Q';
                leftrow[row]=1;
                lowdiag[row+col]=1;
                uppdiag[((n-1) + (col-row))]=1;
                f(col+1, ans,board,leftrow, uppdiag, lowdiag, n);
                board[row][col]= '.';
                leftrow[row]=0;
                lowdiag[row+col]=0;
                uppdiag[((n-1) + (col-row))]=0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n, '.');
        for(int i=0; i<n; i++)
        board[i]= s;

        vector<int> leftrow(n,0); vector<int> uppdiag(2*n-1,0); vector<int> lowdiag(2*n-1);
        f(0, ans, board,leftrow, uppdiag, lowdiag,n);
        return ans;
    }
};