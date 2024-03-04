/*
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, 
the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and 
it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob 
tonight without alerting the police.

Example 1:

Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.
Example 2:

Input: nums = [2,7,9,3,1]
Output: 12
Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
Total amount you can rob = 2 + 9 + 1 = 12.

Constraints:

1 <= nums.length <= 100
0 <= nums[i] <= 400

  */

// Solution using DP and tabular way using the recursive function below.

class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
            return nums[0];
        vector<int>dp(n, -1);
        dp[0]=nums[0];
        dp[1]=max(nums[0], nums[1]);
        for(int i=2; i<nums.size(); i++)
        {
            int taken = dp[i-1];
            int not_taken = 0;
            if(i-2>=0)
            {
                not_taken = nums[i]+dp[i-2];
            }
            dp[i]=max(taken, not_taken);
        }
        return dp[n-1];
    }
};


// Solution using recursion and memoization

class Solution {
public:
    int solve(int n, vector<int>&nums, vector<int>&dp)
    {
        if(n==0)
            return nums[n]; // Since not taken when i=1; because least taken is i=2 and i-2=0
        if(n<0) // recursion is callled from i=1;
            return 0;
        if(dp[n]!=-1)
            return dp[n];
        int taken = 0, not_taken = 0;

        taken = nums[n]+solve(n-2, nums, dp);
        not_taken = solve(n-1, nums, dp);
        return dp[n] = max(taken, not_taken);

    }
    int rob(vector<int>& nums) {
        vector<int>dp(nums.size(), -1);
        return solve(nums.size()-1, nums, dp);
    }
};
