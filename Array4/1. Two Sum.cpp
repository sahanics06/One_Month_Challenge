/*
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]
Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]

Constraints:

2 <= nums.length <= 104
-109 <= nums[i] <= 109
-109 <= target <= 109
Only one valid answer exists.

  */

// Solution using map. if target-nums[i] is in map then return ans. Approximate T.C- O(N)

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mp;
        int n=nums.size();
        for(int i=0; i<n; i++)
        {
            if(mp.find(target-nums[i])!=mp.end())
            {
                return {i, mp[target-nums[i]]};
            }
            mp[nums[i]]=i;
        }
        return {};
    }
};


// Solution keeping in different vector of pair and then sorting and then finding the target-vec[i] using binary search.
// T.C- O(NlogN)

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        vector<pair<int,int>>vec;
        for(int i=0; i<n; i++)
            vec.push_back({nums[i], i});
        sort(vec.begin(), vec.end());
        for(int i=0; i<n; i++)
        {
            int l=i+1, r=n-1, tmp=target-vec[i].first;
            while(l<=r)
            {
                int m = l+(r-l)/2;
                if(tmp==vec[m].first)
                {
                    //cout<<nums[i]<<" "<<nums[m]<<endl;
                    return {vec[i].second, vec[m].second};

                }
                else if(tmp<vec[m].first)
                {
                    r=m-1;
                }
                else
                {
                    l=m+1;
                }
            }
        }
        return {};
    }
};

// Solution using T.C- N*N 

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        for(int i=0; i<n; i++)
        {
            int tmp=target-nums[i];
            for(int j=i+1; j<n; j++)
            {
                if(tmp==nums[j])
                    return {i,j};
            }
        }
        return {};
    }
};
