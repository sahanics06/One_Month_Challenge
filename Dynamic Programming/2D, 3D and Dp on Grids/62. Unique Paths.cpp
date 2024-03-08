/*
There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). 
The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right 
at any point in time.

Given the two integers m and n, return the number of possible unique paths that the robot can take to reach 
the bottom-right corner.

The test cases are generated so that the answer will be less than or equal to 2 * 109.

Example 1:

Input: m = 3, n = 7
Output: 28
Example 2:

Input: m = 3, n = 2
Output: 3
Explanation: From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -> Down -> Down
2. Down -> Down -> Right
3. Down -> Right -> Down

Constraints:

1 <= m, n <= 100

  */

// Solution using DP and tabular way

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m, vector<int>(n,0));
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(i==0)
                    dp[i][j]=1;
                if(j==0)
                    dp[i][j]=1;
            }
        }
        for(int i=1; i<m; i++)
        {
            for(int j=1; j<n; j++)
            {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};


// Solution using recursion and memoization

class Solution {
public:    
    int solve(int m, int n, vector<vector<int>>&dp)
    {
        if(m==0 && n==0)
        {
            return 1;
        }
        if(dp[m][n]!=-1)
            return dp[m][n];
        int taken_x=0, taken_y=0;
        if(m-1>=0)
        {
            taken_x=solve(m-1, n, dp);
        }
        if(n-1>=0)
        {
            taken_y=solve(m, n-1, dp);
        }
        return dp[m][n] = taken_x+taken_y;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m, vector<int>(n,-1));
        return solve(m-1, n-1, dp);
    }
};
