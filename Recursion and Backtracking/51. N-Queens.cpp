/*
The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.

Example 1:

Input: n = 4
Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above
Example 2:

Input: n = 1
Output: [["Q"]]

Constraints:

1 <= n <= 9

  */

// Solution we check every col and for every col we check row =0 to n-1 and if possible then solve for next col,
// we have used hashing for checking the Queens in left diagonal up, left diagonal down, left rows. 

class Solution {
public:
    void solve(int col, vector<string>&mat, vector<vector<string>>&ans, int n, vector<int>&up, vector<int>&down, vector<int>&samelevel)
    {
        if(col==n)
        {
            ans.push_back(mat);
            return ;
        }
        for(int row=0; row<n; row++)
        {
            if(up[row+col]==0 && down[n-1+col-row]==0 && samelevel[row]==0)
            {
                up[row+col]=1;
                down[n-1+col-row]=1;
                samelevel[row]=1;
                mat[row][col]='Q';
                solve(col+1, mat, ans, n, up, down, samelevel);
                mat[row][col]='.';
                up[row+col]=0;
                down[n-1+col-row]=0;
                samelevel[row]=0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>mat(n);
        vector<int>up(2*n-1, 0), down(2*n-1, 0), samelevel(n, 0);
        string s(n, '.');
        for(int i=0; i<n; i++)
        {
            mat[i]=s;
        }
        solve(0, mat, ans, n, up, down, samelevel);
        return ans;
    }
};



// Solution Brute force- we check every col and for every col we check row =0 to n-1 and if possible then solve for next col

class Solution {
public:
    bool possible(int col, int row, int n, vector<string>&mat)
    {
        int c=col, r=row;
        while(col>=0 && row>=0)
        {
            if(mat[row][col]=='Q')
                return false;
            col--;
            row--;
        }
        col=c;
        row=r;

        while(col>=0)
        {
            if(mat[row][col]=='Q')
                return false;
            col--;
        }

        col=c;

        while(col>=0 && row<n)
        {
            if(mat[row][col]=='Q')
                return false;
            col--;
            row++;
        }
        return true;
    }
    void solve(int col, vector<string>&mat, vector<vector<string>>&ans, int n)
    {
        if(col==n)
        {
            ans.push_back(mat);
            return ;
        }
        for(int row=0; row<n; row++)
        {
            if(possible(col, row, n, mat))
            {
                mat[row][col]='Q';
                solve(col+1, mat, ans, n);
                mat[row][col]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>mat(n);
        string s(n, '.');
        for(int i=0; i<n; i++)
        {
            mat[i]=s;
        }
        solve(0, mat, ans, n);
        return ans;
    }
};
