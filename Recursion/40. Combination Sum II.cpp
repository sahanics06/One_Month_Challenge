/*
Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in 
candidates where the candidate numbers sum to target.

Each number in candidates may only be used once in the combination.

Note: The solution set must not contain duplicate combinations.

Example 1:

Input: candidates = [10,1,2,7,6,1,5], target = 8
Output: 
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]
Example 2:

Input: candidates = [2,5,2,1,2], target = 5
Output: 
[
[1,2,2],
[5]
]
 

Constraints:

1 <= candidates.length <= 100
1 <= candidates[i] <= 50
1 <= target <= 30

  */

// Solution 

class Solution {
public:
    void solve(vector<int> &nums, vector<vector<int>>&ans, vector<int> tmp, int target, int idx, int sum)
    {
        if(idx==nums.size() || sum==target)
        {
            if(sum==target)
            {
                ans.push_back(tmp);
            }
            return;
        }
        for(int i=idx; i<nums.size(); i++)
        {
            if(i>idx && nums[i]==nums[i-1])
                continue;
            if(sum+nums[i]>target)
                break;
            tmp.push_back(nums[i]);
            solve(nums, ans, tmp, target, i+1, sum+nums[i]);
            tmp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        vector<vector<int>>ans;
        sort(nums.begin(), nums.end());
        vector<int>tmp;
        solve(nums, ans, tmp, target, 0, 0);
        return ans;
    }
};
