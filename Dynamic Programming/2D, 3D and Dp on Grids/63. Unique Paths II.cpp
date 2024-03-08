/*
You are given an m x n integer array grid. There is a robot initially located at the top-left corner (i.e., grid[0][0]). 
The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right 
at any point in time.

An obstacle and space are marked as 1 or 0 respectively in grid. A path that the robot takes cannot include any square 
that is an obstacle.

Return the number of possible unique paths that the robot can take to reach the bottom-right corner.

The testcases are generated so that the answer will be less than or equal to 2 * 109.

Example 1:

Input: obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
Output: 2
Explanation: There is one obstacle in the middle of the 3x3 grid above.
There are two ways to reach the bottom-right corner:
1. Right -> Right -> Down -> Down
2. Down -> Down -> Right -> Right
Example 2:

Input: obstacleGrid = [[0,1],[0,0]]
Output: 1

Constraints:

m == obstacleGrid.length
n == obstacleGrid[i].length
1 <= m, n <= 100
obstacleGrid[i][j] is 0 or 1.

  */


// Solution using DP and tabular way with the help of recursion statement from recursion and memoization.

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& oGrid) {
        int m= oGrid.size();
        int n= oGrid[0].size();
        if(oGrid[m-1][n-1]==1 || oGrid[0][0]==1)
            return 0;
        vector<vector<int>>dp(m, vector<int>(n, 0));
        for(int i=0; i<m; i++)  // base case
        {
            if(oGrid[i][0]==0)
            {
                dp[i][0]=1;
            }
            else
                break;
        }
        for(int i=0; i<n; i++)
        {
            if(oGrid[0][i]==0)
            {
                dp[0][i]=1;
            }
            else
                break;
        }
        for(int i=1; i<m; i++)
        {
            for(int j=1; j<n; j++)
            {
                if(oGrid[i][j]==0)
                {
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
            }
        }
        return dp[m-1][n-1];
    }
};


// Solution using Recursion and memoization

class Solution {
public:
    int solve(int m, int n, vector<vector<int>>&arr, vector<vector<int>>&dp)
    {
        if(m==0 && n==0)
            return 1;
        if(dp[m][n]!=-1)
            return dp[m][n];
        int taken_x=0, taken_y=0;
        if(m-1>=0 && arr[m-1][n]==0)
        {
            taken_y = solve(m-1, n, arr, dp);
        }
        if(n-1>=0 && arr[m][n-1]==0)
        {
            taken_x = solve(m, n-1, arr, dp);
        }
        return dp[m][n] = taken_x+taken_y;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& oGrid) {
        int m= oGrid.size();
        int n= oGrid[0].size();
        if(oGrid[m-1][n-1]==1) // edge case
            return 0;
        vector<vector<int>>dp(m, vector<int>(n, -1));
        return solve(m-1, n-1, oGrid, dp);
    }
};
