/*
Given a triangle array, return the minimum path sum from top to bottom.

For each step, you may move to an adjacent number of the row below. More formally, if you are on index i on the current row, you may move to either index i or index i + 1 
on the next row.

Example 1:

Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
Output: 11
Explanation: The triangle looks like:
   2
  3 4
 6 5 7
4 1 8 3
The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11 (underlined above).
Example 2:

Input: triangle = [[-10]]
Output: -10
 
Constraints:

1 <= triangle.length <= 200
triangle[0].length == 1
triangle[i].length == triangle[i - 1].length + 1
-104 <= triangle[i][j] <= 104

Follow up: Could you do this using only O(n) extra space, where n is the total number of rows in the triangle?

  */

// Solution using tabulation bottom up, space optimization. Here we just need two rows for calculation, one is the down row and the current row.

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m=triangle.size();
        int n=triangle[m-1].size();
        vector<int>front(n,0), cur(n,0);
        for(int i=m-1; i>=0; i--)
        {
            front[i] = triangle[m-1][i];
        }

        for(int i=m-2; i>=0; i--)
        {
            for(int j=i; j>=0; j--)
            {
                int diag = triangle[i][j] + front[j+1];
                int d = triangle[i][j] + front[j];
                cur[j] = min(d, diag);
            }
            front = cur;
        }
        return front[0];
    }
};




// Solution using tabulation bottom up

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m=triangle.size();
        int n=triangle[m-1].size();
        vector<vector<int>>dp(m, vector<int>(n, 0));
        for(int i=m-1; i>=0; i--)
        {
            dp[m-1][i] = triangle[m-1][i];
        }

        for(int i=m-2; i>=0; i--)
        {
            for(int j=i; j>=0; j--)
            {
                int diag = triangle[i][j] + dp[i+1][j+1];
                int d = triangle[i][j] + dp[i+1][j];
                dp[i][j] = min(d, diag);
            }
        }
        return dp[0][0];
    }
};



// Solution using recusion and memoization. Top down approach

class Solution {
public:
    int solve(int i, int j, int m, vector<vector<int>>&tri, vector<vector<int>>&dp)
    {
        if(i==m)
            return tri[i][j];
        if(dp[i][j]!=-1)
            return dp[i][j];
        int down = INT_MAX, diag = INT_MAX;
        down = solve(i+1, j, m, tri, dp);
        diag = solve(i+1, j+1, m, tri, dp);
        return dp[i][j] = tri[i][j] + min(down, diag);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int m=triangle.size();
        int n=triangle[m-1].size();
        vector<vector<int>>dp(m, vector<int>(n, -1));
        return solve(0, 0, m-1, triangle, dp);
    }
};



// Solution using recursion and memoization bootom up

class Solution {
public:
    int solve(int m, int n, vector<vector<int>>&triangle, vector<vector<int>>&dp)
    {
        if(m==0)
            return triangle[0][0];
        if(dp[m][n]!=-1)
            return dp[m][n];
        int taken_left=INT_MAX, taken_right=INT_MAX;
        if(n>0)
        {
            taken_left = solve(m-1, n-1, triangle, dp);
        }
        if(n<m)
        {
            taken_right = solve(m-1, n, triangle, dp);
        }
        return dp[m][n]=triangle[m][n]+min(taken_left, taken_right);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int m=triangle.size();
        int n=triangle[m-1].size();
        int ans=INT_MAX;
        vector<vector<int>>dp(m, vector<int>(n, -1));
        for(int i=0; i<triangle[m-1].size(); i++)
        {
            ans = min(ans,solve(m-1, i, triangle, dp));
        }
        return ans;
    }
};
