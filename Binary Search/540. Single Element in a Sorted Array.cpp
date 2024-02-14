/*
You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once.

Return the single element that appears only once.

Your solution must run in O(log n) time and O(1) space.

Example 1:

Input: nums = [1,1,2,3,3,4,4,8,8]
Output: 2
Example 2:

Input: nums = [3,3,7,7,10,11,11]
Output: 10
 
Constraints:

1 <= nums.length <= 105
0 <= nums[i] <= 105

  */

// Solution-> Finding in which part the single element is; the mid can be either odd or even; 
// if(mid is odd and nums[mid-1] || mid is even and nums[mid+1]==nums[mid]) then we are in left part and answer is in right.

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        if(n==1)
            return nums[0];
        if(nums[0]!=nums[1])
            return nums[0];
        if(nums[n-1]!=nums[n-2])
            return nums[n-1];
        int l=1, r=n-2;
        while(l<=r)
        {
            int m=l+(r-l)/2;
            if(nums[m]!=nums[m-1] && nums[m]!=nums[m+1])
                return nums[m];
            if(m%2==1 && nums[m]==nums[m-1] || m%2==0 && nums[m]==nums[m+1]) // we are in the left half and answer is in right half
            {
                l=m+1;
            }
            else
            {
                r=m-1;
            }
        }
        return 0;
    }
};
