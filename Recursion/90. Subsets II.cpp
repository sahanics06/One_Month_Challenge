/*
Given an integer array nums that may contain duplicates, return all possible 
subsets
 (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

Example 1:

Input: nums = [1,2,2]
Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
Example 2:

Input: nums = [0]
Output: [[],[0]]
 
Constraints:

1 <= nums.length <= 10
-10 <= nums[i] <= 10

  */

// Solution using recursion

class Solution {
public:
    void solve(vector<int>&nums, vector<vector<int>>& ans, int idx, vector<int>& tmp)
    {
        if(idx>=nums.size())
        {
            ans.push_back(tmp);
            return;
        }
        ans.push_back(tmp);
        for(int i=idx; i<nums.size(); i++)
        {
            if(i!=idx && nums[i]==nums[i-1]) // ignore duplicates
                continue;
            tmp.push_back(nums[i]);
            solve(nums, ans, i+1, tmp);
            tmp.pop_back();
        }
        return ;
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>ans;
        sort(nums.begin(), nums.end());
        int n=nums.size();
        vector<int>tmp;
        solve(nums, ans, 0, tmp);
        return ans;
    }
};
