/*
Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

Example 1:

Input: nums = [3,2,3]
Output: [3]
Example 2:

Input: nums = [1]
Output: [1]
Example 3:

Input: nums = [1,2]
Output: [1,2]
 
Constraints:

1 <= nums.length <= 5 * 104
-109 <= nums[i] <= 109

  */

// Solution

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int c1=1, c2=0, n1=nums[0], n2, i=1, n=nums.size();
        while(i<n) // get count and values of n1 and n2
        {
            if(n1!=nums[i])
            {
                c2=1;
                n2=nums[i];
                i++;
                break;
            }
            c1++;
            i++;
        }

        while(i<n)
        {
            if(c1==0 && nums[i]!=n2) // 2nd condition is to check n1 and n2 doesnot become same
            {
                c1++;
                n1=nums[i];
            }
            else if(c2==0 && nums[i]!=n1)
            {
                c2++;
                n2=nums[i];
            }
            else if(nums[i]==n1)
            {
                c1++;
            }
            else if(nums[i]==n2)
            {
                c2++;
            }
            else
            {
                c1--;
                c2--;
            }
            i++;
        }
        vector<int>ans(2);
        c1=0;
        c2=0;
        for(int i=0; i<n; i++)
        {
            if(nums[i]==n1)
            {
                c1++;
            }
            else if(nums[i]==n2)
            {
                c2++;
            }
        }
        cout<<n1<<" "<<n2<<endl;
        if(c1>n/3 && c2>n/3)
            return {n1,n2};
        if(c1>n/3)
            return {n1};
        if(c2>n/3)
            return {n2};
        return {};
    }
};
