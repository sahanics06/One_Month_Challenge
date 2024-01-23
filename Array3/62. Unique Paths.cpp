/*
There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner 
(i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the bottom-right corner.

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

// Solution using permutation and combination

class Solution {
public:
    int uniquePaths(int m, int n) {
        int N=m+n-2; // total number of directions we can move including right and down
        double ans=1;
        int r=m-1; // we need to go m-1 time down;
        // So now find NCr
        for(int i=1; i<=r; i++)
        {
            ans=ans*(N-r+i)/i;
        }
        return (int)ans;
    }
};

// Solution using recursion and memoization.

class Solution {
public:
    int ans=0;
    int solve(int i, int j, int m, int n, vector<vector<int>>& dp)
    {
        if(i==m-1 && j==n-1)
            return 1;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int taken=0, not_taken=0;
        if(i+1<m)
        {
            taken=solve(i+1, j, m, n, dp);
        }
        if(j+1<n)
        {
            not_taken=solve(i, j+1, m, n, dp);
        }
        return dp[i][j]=taken+not_taken;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m, vector<int>(n,-1));
        return solve(0,0,m,n, dp);
        //return ans;
    }
};
