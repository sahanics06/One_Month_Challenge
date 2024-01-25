/*
Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

0 <= a, b, c, d < n
a, b, c, and d are distinct.
nums[a] + nums[b] + nums[c] + nums[d] == target
You may return the answer in any order.

Example 1:

Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
Example 2:

Input: nums = [2,2,2,2,2], target = 8
Output: [[2,2,2,2]] 

Constraints:

1 <= nums.length <= 200
-109 <= nums[i] <= 109
-109 <= target <= 109

  */

// Solution most optimised. Sort the array. Keeping i and j as constant and using left right pointer. If there is duplicate elements then we skip it

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n=nums.size();
        vector<vector<int>>ans;
        sort(nums.begin(), nums.end());
        for(int i=0; i<n; i++)
        {
            if(i>0 &&  nums[i]==nums[i-1])
                continue;
            for(int j=i+1; j<n; j++)
            {
                if(j>i+1 && nums[j]==nums[j-1])
                    continue;
                int l=j+1; 
                int r=n-1;
                while(l<r)
                {
                    long long sum = nums[i]+nums[j];
                    sum+=nums[l];
                    sum+=nums[r];
                    if(sum==target)
                    {
                        ans.push_back({nums[i],  nums[j], nums[l], nums[r]});
                        r--;
                        l++;
                        while(r>l && nums[r]==nums[r+1])
                        {
                            r--;
                        }
                        while(l<r && nums[l]==nums[l-1])
                        {
                             l++;
                        }
                    }
                    else if(sum>target)
                    {
                        r--;
                    }
                    else
                    {
                        l++;
                    }
                }
            }
        }
        return ans;
    }
};



// Here we optimise O(N^4) by creating a set after 2nd loop i.e between j and k. we find tmp=target-num[i]-nums[j]-nums[k] in set. If tmp is not present then we insert
// in set. We keep element between j and k only Since we need to have distinct elements.
// T.C- O(N^3 * log(M)) log (M) for keeping elements in set.

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n=nums.size();
        set<vector<int>>st;
        for(int i=0; i<n; i++)
        {
            long long t1 = target-nums[i];
            for(int j=i+1; j<n; j++)
            {
                set<long long>hashSet;
                long long t2 = t1-nums[j];
                for(int k=j+1; k<n; k++)
                {
                    long long sum = nums[i]+nums[j];
                    sum+=nums[k];
                    long long tmp = target-sum;
                    if(hashSet.find(tmp)!=hashSet.end())
                    {
                        vector<int>vec={(int)nums[i], (int)nums[j], (int)nums[k], (int)tmp};
                        sort(vec.begin(), vec.end());
                        st.insert(vec);
                    }
                    hashSet.insert(nums[k]);
                }
            }
        }
        vector<vector<int>>ans(st.begin(), st.end());
        return ans;
    }
};
