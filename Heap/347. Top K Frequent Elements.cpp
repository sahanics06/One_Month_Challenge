/*
Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

Example 1:

Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]
Example 2:

Input: nums = [1], k = 1
Output: [1]

Constraints:

1 <= nums.length <= 105
-104 <= nums[i] <= 104
k is in the range [1, the number of unique elements in the array].
It is guaranteed that the answer is unique.
 

Follow up: Your algorithm's time complexity must be better than O(n log n), where n is the array's size.

  */


// Solution using storing the frequency in map and then using min heap priority queue of pairs and storing priority queueu 
// of size k

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        vector<int>ans;
        int n=nums.size();
        vector<vector<int>>tmp(n+1);
        for(int i=0; i<n; i++)
        {
            mp[nums[i]]++;
        }
        for(auto it:mp)
        {
            tmp[it.second].push_back(it.first);
        }
        for(auto it:mp)
        {
            if(pq.size()<k)
            {
                pq.push({it.second, it.first});
            }
            else
            {
                if(pq.top().first<it.second)
                {
                    pq.pop();
                    pq.push({it.second, it.first});
                }
            }
        }
        while(!pq.empty())
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};


// Solution using bucket sort

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        vector<int>ans;
        int n=nums.size();
        vector<vector<int>>tmp(n+1);
        for(int i=0; i<n; i++)
        {
            mp[nums[i]]++;
        }
        for(auto it:mp)
        {
            tmp[it.second].push_back(it.first);
        }
        for(int i=n; i>0; i--)
        {
            if(tmp[i].size()==0)
                continue;
            int t=0;
            while(t<tmp[i].size() && k)
            {
                ans.push_back(tmp[i][t]);
                t++;
                k--;
            }
        }
        return ans;
    }
};
