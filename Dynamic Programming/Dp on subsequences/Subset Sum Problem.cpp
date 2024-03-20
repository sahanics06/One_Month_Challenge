/*
Given an array of non-negative integers, and a value sum, determine if there is a subset of the given set with sum equal 
to given sum. 


Example 1:

Input:
N = 6
arr[] = {3, 34, 4, 12, 5, 2}
sum = 9
Output: 1 
Explanation: Here there exists a subset with
sum = 9, 4+3+2 = 9.
Example 2:

Input:
N = 6
arr[] = {3, 34, 4, 12, 5, 2}
sum = 30
Output: 0 
Explanation: There is no subset with sum 30.

Your Task:  
You don't need to read input or print anything. Your task is to complete the function isSubsetSum() which takes the array 
arr[], its size N and an integer sum as input parameters and returns boolean value true if there exists a subset with given 
sum and false otherwise.
The driver code itself prints 1, if returned value is true and prints 0 if returned value is false.
 

Expected Time Complexity: O(sum*N)
Expected Auxiliary Space: O(sum*N)
 

Constraints:
1 <= N <= 100
1<= arr[i] <= 100
1<= sum <= 104

*/


// Solution using tabulation by following bottom up recursion steps.

class Solution{   
public:
    bool isSubsetSum(vector<int>arr, int sum){
        int n = arr.size();
        vector<vector<bool>>dp(n, vector<bool>(sum+1, false));
        for(int i=0; i<n; i++)
        {
            dp[i][0]=true;
        }
        dp[0][arr[0]] = true; // since if i==0 return sum==arr[i] i.e return true if sum==arr[i] therefor dp[0][sum]=true
        
        for(int i=1; i<n; i++)
        {
            for(int j=1; j<=sum; j++)
            {
                bool taken = false, not_taken = false;
                if(j-arr[i]>=0)
                {
                    taken = dp[i-1][j-arr[i]];
                }
                not_taken = dp[i-1][j];
                dp[i][j] = taken || not_taken;
            }
        }
        return dp[n-1][sum];
    }
};


// Solution using recursion and memoization

class Solution{   
public:
    bool solve(vector<int>&arr, int i, int sum, vector<vector<int>>&dp)
    {
        if(sum==0)
            return true;
        if(i==0)
        {
            return sum==arr[i];
        }
        if(dp[i][sum]!=-1)
            return dp[i][sum];
        bool taken = false, not_taken = false;
        if(sum-arr[i]>=0)
        {
            taken = solve(arr, i-1, sum-arr[i], dp);
        }
        not_taken = solve(arr, i-1, sum, dp);
        return dp[i][sum] = taken || not_taken;
    }
    bool isSubsetSum(vector<int>arr, int sum){
        int n = arr.size();
        vector<vector<int>>dp(n, vector<int>(sum+1, -1));
        return solve(arr, n-1, sum, dp);
    }
};
