/*
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, 
and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets. 

Example 1:

Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Explanation: 
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
The distinct triplets are [-1,0,1] and [-1,-1,2].
Notice that the order of the output and the order of the triplets does not matter.
Example 2:

Input: nums = [0,1,1]
Output: []
Explanation: The only possible triplet does not sum up to 0.
Example 3:

Input: nums = [0,0,0]
Output: [[0,0,0]]
Explanation: The only possible triplet sums up to 0.

Constraints:

3 <= nums.length <= 3000
-105 <= nums[i] <= 105

  */

// Solution using sorting the array. then looping in i and using two pointer concept taking j=i+1 and k=n-1 

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>ans;
        sort(nums.begin(), nums.end());
        for(int i=0; i<n; i++)
        {           
            if(i>0 && nums[i]==nums[i-1])
            {
                continue;
            }
            int tmp=0-nums[i];
            int j=i+1, k=n-1;
            while(j<k)
            {
                int sum=nums[j]+nums[k];
                if(sum==tmp)
                {
                    ans.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                    while(j<k && nums[j]==nums[j-1])
                    {
                        j++;
                    }
                    while(j<k && nums[k]==nums[k+1])
                    {
                        k--;
                    }
                }
                else if(sum<tmp)
                {
                    j++;
                }
                else
                {
                    k--;
                }

            }
        }
        return ans;
    }
};


// Using map to keep elements between i and j and find the remaining sum in the map

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>ans;
        set<vector<int>>st;
        for(int i=0; i<n; i++)
        {
            unordered_map<int, int>mp;
            for(int j=i+1; j<n; j++)
            {
                int tmp=nums[i]+nums[j];
                tmp*=(-1);
                if(mp.find(tmp)!=mp.end())
                {
                    vector<int>t={nums[i], nums[j], tmp};
                    sort(t.begin(), t.end());
                    st.insert(t);
                }
                mp[nums[j]]=1;
            }
        }
        for(auto it:st)
        {
            ans.push_back(it);
        }
        return ans;
    }
};


// Brute force

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>ans;
        set<vector<int>>st;
        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                for(int k=j+1; k<n; k++)
                {
                    long long tmp=nums[i]+nums[j];
                    tmp+=nums[k];
                    vector<int>t;
                    if(tmp==0)
                    {
                        t.push_back(nums[i]);
                        t.push_back(nums[j]);
                        t.push_back(nums[k]);
                        sort(t.begin(), t.end());
                        st.insert(t);
                    }
                }
            }
        }
        for(auto it:st)
        {
            ans.push_back(it);
        }
        return ans;
    }
};
