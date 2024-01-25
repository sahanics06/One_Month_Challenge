/*
Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

You must write an algorithm that runs in O(n) time.

Example 1:

Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
Example 2:

Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9

Constraints:

0 <= nums.length <= 105
-109 <= nums[i] <= 109

  */

// Solution- We insert all the elements in unordered_set. We find for nums[i], if nums[i]-1 is present in set then we dont proceed. 
// We start from value which is the start of sequence. And from start value we find the next element in the set.

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size(), ans=INT_MIN;
        if(n==0)
            return 0;
        unordered_set<int>st;
        for(int i=0; i<n; i++)
        {
            st.insert(nums[i]);
        }

        for(auto it:st)
        {
            int c=0;
            if(st.find(it-1)==st.end())
            {
                c=1;
                int x=it;
                while(st.find(x+1)!=st.end())
                {
                    x++;
                    c++;
                }
            }
            ans=max(ans, c);
        }
        return ans;
    }
};


// Solution using sort. keeping track of previous number, left=INT_MIN. if(nums[i]-1==left) then c++ and left =nums[i]

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n=nums.size();
        if(n==0)
            return 0;
        int left = INT_MIN, c=0, ans=INT_MIN;
        for(int i=0; i<n; i++)
        {
            if(nums[i]==left)
                continue;
            if(nums[i]-1==left)
            {
                left = nums[i];
                c++;
            }
            else
            {
                left=nums[i];
                c=1;
            }
            ans=max(ans, c);
        }
        return ans;
    }
};

// Solution TLE
// for every element x in array we will find x+1 using Linear search. T.C- O(N*N)

class Solution {
public:
    bool ls(int x, vector<int>& nums)
    {
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i]==x)
                return true;
        }
        return false;
    }
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        if(n==0)
            return 0;
        int ans=1;
        for(int i=0; i<n; i++)
        {
            int x= nums[i], c=1;
            while(ls(x+1, nums))
            {
                x+=1;
                c++;
            }
            ans = max(ans, c);
        }
        return ans;
    }
};
