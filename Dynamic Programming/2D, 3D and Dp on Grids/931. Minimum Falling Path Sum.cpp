/*
Given an n x n array of integers matrix, return the minimum sum of any falling path through matrix.

A falling path starts at any element in the first row and chooses the element in the next row that is either directly below 
or diagonally left/right. Specifically, the next element from position (row, col) will be (row + 1, col - 1), 
(row + 1, col), or (row + 1, col + 1).


Example 1:


Input: matrix = [[2,1,3],[6,5,4],[7,8,9]]
Output: 13
Explanation: There are two falling paths with a minimum sum as shown.
Example 2:


Input: matrix = [[-19,57],[-40,-5]]
Output: -59
Explanation: The falling path with a minimum sum is shown.
 

Constraints:

n == matrix.length == matrix[i].length
1 <= n <= 100
-100 <= matrix[i][j] <= 100

  */

// Solution using tabulation from following recursion steps.

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size(), ans=INT_MAX;
        vector<vector<int>>dp(n, vector<int>(n, 0));
        for(int i=0; i<n; i++)
        {
            dp[0][i]=matrix[0][i];
        }

        for(int i=1; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                int l=INT_MAX, r=INT_MAX, u=INT_MAX;
                if(j-1>=0)
                {
                    l = dp[i-1][j-1];
                }
                if(j+1<n)
                {
                    r = dp[i-1][j+1];
                }
                u = dp[i-1][j];
                dp[i][j] = matrix[i][j]+min({l,r,u});
            }
        }
        for(int i=0; i<n; i++)
        {
            ans = min(ans, dp[n-1][i]);
        }
        return ans;
    }
};


// Solution using recursion and memoization. TLE

class Solution {
public:
    int solve(int m, int n, vector<vector<int>>&mat, int N, vector<vector<int>>&dp)
    {
        if(m==0)
            return mat[m][n];
        if(dp[m][n]!=-1)
            return dp[m][n];
        int l=INT_MAX, r=INT_MAX, u=INT_MAX;
        if(n-1>=0)
        {
            l = solve(m-1, n-1, mat, N, dp);
        }
        if(n+1<=N)
        {
            r = solve(m-1, n+1, mat, N, dp);
        }
        u = solve(m-1, n, mat, N, dp);
        return dp[m][n] = mat[m][n]+min({l, r, u});
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size(), ans=INT_MAX;
        vector<vector<int>>dp(m, vector<int>(m, -1));
        for(int i=0; i<m; i++)
        {
            ans = min(ans, solve(m-1, i, matrix, m-1, dp));
        }
        return ans;
    }
};
