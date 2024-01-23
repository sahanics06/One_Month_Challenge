/*
Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

Example 1:

Input: nums = [3,2,3]
Output: 3
Example 2:

Input: nums = [2,2,1,1,1,2,2]
Output: 2 

Constraints:

n == nums.length
1 <= n <= 5 * 104
-109 <= nums[i] <= 109

  */

// Solution

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size(), c=1, ans=nums[0];
        for(int i=1; i<n; i++)
        {
            if(c==0)
            {
                ans=nums[i];
                c++;
            }
            else if(ans==nums[i])
            {
                c++;
            }
            else
            {
                c--;
            }
        }
        return ans;
    }
};
