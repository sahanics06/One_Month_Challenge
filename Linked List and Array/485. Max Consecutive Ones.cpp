/*
Given a binary array nums, return the maximum number of consecutive 1's in the array.

Example 1:

Input: nums = [1,1,0,1,1,1]
Output: 3
Explanation: The first two digits or the last three digits are consecutive 1s. The maximum number of consecutive 1s is 3.
Example 2:

Input: nums = [1,0,1,1,0,1]
Output: 2
 
Constraints:

1 <= nums.length <= 105
nums[i] is either 0 or 1.

  */

// Solution using one loop; c=0 if nums[i]==1; c++; ans=max(ans, c); else c=0;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n=nums.size(), ans=0, c=0;
        for(int i=0; i<n; i++)
        {
            if(nums[i]==1)
            {
                c++;
                ans=max(c, ans);
            }
            else
            {
                c=0;
            }
        }
        
        return ans;
    }
};


// Solution

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int l=0, r=0, n=nums.size(), ans=0;
        while(r<n)
        {
            if(nums[r]==1)
            {
                l=r;
                while(r<n && nums[r]==1)
                {
                    ans=max(ans, r-l+1);
                    r++;
                }
            }
            r++;
        }
        return ans;
    }
};

