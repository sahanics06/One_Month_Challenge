/*
Given an integer array nums, return the length of the longest strictly increasing 
subsequence.

Example 1:

Input: nums = [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
Example 2:

Input: nums = [0,1,0,3,2,3]
Output: 4
Example 3:

Input: nums = [7,7,7,7,7,7,7]
Output: 1
 

Constraints:

1 <= nums.length <= 2500
-104 <= nums[i] <= 104
  */


// Solution using Binary Search. We take an empty vector tmp and push first value in it. Now we iterate from i=1 to n and if tmp.back()<nums[i] then push in it and 
// if not then we find index in tmp whose value is less than equal to or just greater than nums[i] using lower_bound() function. T.C- O(NlogN)

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>tmp;
        tmp.push_back(nums[0]);
        for(int i=1; i<nums.size(); i++)
        {
            if(tmp.back()<nums[i])
            {
                tmp.push_back(nums[i]);
            }
            else
            {
                int idx = lower_bound(tmp.begin(), tmp.end(), nums[i])-tmp.begin();
                tmp[idx] = nums[i];
            }
        }
        return tmp.size();
    }
};


// Solution using DP and memoization. TLE. T.C- O(N*N)

class Solution {
public:
    int solve(int i, vector<int>&nums, int prev, vector<vector<int>>&dp)
    {
        if(i>=nums.size())
            return 0;
        int taken = 0, not_taken = 0;
        if(dp[i][prev+1]!=-1)
            dp[i][prev+1];
        if(prev==-1 || nums[i]>nums[prev])
        {
            taken = 1+solve(i+1, nums, i, dp);
        }
        not_taken = solve(i+1, nums, prev, dp);
        return dp[i][prev+1] = max(taken, not_taken);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        // since prev=-1 index so we shift by 1 for prev index
        vector<vector<int>>dp(n, vector<int>(n+1, -1));
        return solve(0, nums, -1, dp);
    }
};
