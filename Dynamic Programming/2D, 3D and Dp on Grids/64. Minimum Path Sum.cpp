/*
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum 
of all numbers along its path.

Note: You can only move either down or right at any point in time.

Example 1:

Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
Output: 7
Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.
Example 2:

Input: grid = [[1,2,3],[4,5,6]]
Output: 12

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 200
0 <= grid[i][j] <= 200

  */


// Solution using Dp and tabular way

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>dp(m, vector<int>(n, 0));
        dp[0][0]=grid[0][0];
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(i==0 && j==0)
                {
                    dp[i][j]=grid[i][j];
                }
                else
                {
                    int up=0;
                    if(i>0)
                    {
                        up= dp[i-1][j];
                    }
                    else
                    {
                        up=INT_MAX;
                    }
                    int left=0;
                    if(j>0)
                    {
                        left= dp[i][j-1];
                    }
                    else
                    {
                        left=INT_MAX;
                    }
                    dp[i][j] = grid[i][j]+min(left, up);
                }
            }
        }
        return dp[m-1][n-1];
    }
};


class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>dp(m, vector<int>(n, 0));
        dp[0][0]=grid[0][0];
        for(int i=1; i<m; i++)
        {
            dp[i][0] = grid[i][0]+dp[i-1][0];
        }
        for(int i=1; i<n; i++)
        {
            dp[0][i] = grid[0][i]+dp[0][i-1];
        }
        for(int i=1; i<m; i++)
        {
            for(int j=1; j<n; j++)
            {
                dp[i][j] = grid[i][j] + min(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[m-1][n-1];
    }
};


// Solution using Recursion and memoization

class Solution {
public:
    int solve(int m, int n, vector<vector<int>>&grid, vector<vector<int>>&dp)
    {
        if(m==0 && n==0)
        {
            //cout<<m<<" "<<n<<" "<<grid[m][n]<<endl;
            return grid[m][n];
        }
        if(dp[m][n]!=-1)
            return dp[m][n];
        int taken_x = INT_MAX, taken_y = INT_MAX;
        if(m-1>=0)
        {
            taken_x = solve(m-1, n, grid, dp);
        }
        if(n-1>=0)
        {
            taken_y = solve(m, n-1, grid, dp);
        }
        //cout<<m<<" "<<n<<" "<<grid[m][n]+min(taken_x, taken_y)<<endl;
        return dp[m][n] = grid[m][n]+min(taken_x, taken_y);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>dp(m, vector<int>(n, -1));
        return solve(m-1, n-1, grid, dp);
    }
};
