/*
Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0.

A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the 
remaining characters.

For example, "ace" is a subsequence of "abcde".
A common subsequence of two strings is a subsequence that is common to both strings.

Example 1:

Input: text1 = "abcde", text2 = "ace" 
Output: 3  
Explanation: The longest common subsequence is "ace" and its length is 3.
Example 2:

Input: text1 = "abc", text2 = "abc"
Output: 3
Explanation: The longest common subsequence is "abc" and its length is 3.
Example 3:

Input: text1 = "abc", text2 = "def"
Output: 0
Explanation: There is no such common subsequence, so the result is 0.

Constraints:

1 <= text1.length, text2.length <= 1000
text1 and text2 consist of only lowercase English characters.

  */

// Solution using DP and tabular way

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.length(), m=text2.length();
        vector<vector<int>>dp(n+1, vector<int>(m+1, 0));
        // When in recursion we have base case as i<0 || j<0 so to check in vector we cannot go to 
        // -1 index so we shift index for better coding and no confusion
        for(int i=0; i<=n; i++)
        {
            for(int j=0; j<=m; j++)
            {
                if(i==0)
                    dp[i][j] = 0;
                if(j==0)
                    dp[i][j] = 0;
            }
        }

        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                if(text1[i-1]==text2[j-1])
                {
                    dp[i][j] = 1+dp[i-1][j-1];
                }
                else
                {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[n][m];
    }
}; 



// Solution using recursion and memoization. Here we are moving i=n-1 to 0 to j=m-1 to 0

class Solution {
public:
    int solve(int i, int j, string a, string b, vector<vector<int>>&dp)
    {
        if(i<0 || j<0)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(a[i]==b[j])
            return dp[i][j] = 1+solve(i-1, j-1, a, b, dp);
        return dp[i][j] = max(solve(i-1, j, a, b, dp), solve(i, j-1, a, b, dp));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.length(), m=text2.length();
        vector<vector<int>>dp(n, vector<int>(m, -1));

        return solve(n-1, m-1, text1, text2, dp);
    }
}; 


// Solution using DP and memoization. TLE

class Solution {
public:
    int solve(int i, int j, string a, string b, vector<vector<int>>&dp)
    {
        if(i>=a.length() || j>=b.length())
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(a[i]==b[j])
            return dp[i][j] = 1+solve(i+1, j+1, a, b, dp);
        return dp[i][j] = max(solve(i+1, j, a, b, dp), solve(i, j+1, a, b, dp));
    }
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>>dp(text1.length(), vector<int>(text2.length(), -1));
        return solve(0, 0, text1, text2, dp);
    }
}; 
