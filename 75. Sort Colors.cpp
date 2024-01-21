/*
Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, 
and blue.

We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

You must solve this problem without using the library's sort function.

Example 1:

Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
Example 2:

Input: nums = [2,0,1]
Output: [0,1,2]
 
Constraints:

n == nums.length
1 <= n <= 300
nums[i] is either 0, 1, or 2.

  */

// Most optimised solution using low, mid and high index. DUTCH national flag algorithm

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int l=0, m=0, h=nums.size()-1;
        while(m<=h)
        {
            if(nums[m]==0)
            {
                swap(nums[l], nums[m]);
                l++;
                m++;
            }
            else if(nums[m]==1)
            {
                m++;
            }
            else
            {
                swap(nums[h], nums[m]);
                h--;
            }
        }
    }
};

// Solution using counting the frequency of 0, 1, 2 and then inserting values of 0,1,2 according to frequency.

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int one=0, zero=0, two=0;
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i]==0)
            {
                zero++;
            }
            else if(nums[i]==1)
            {
                one++;
            }
            else
            {
                two++;
            }
        }
        cout<<zero<<" "<<one<<" "<<two<<" "<<endl;
        int i=0, j=0;
        while(j<zero)
        {
            nums[i]=0;
            i++;
            j++;
        }
        j=0;
        while(j<one)
        {
            nums[i]=1;
            i++;
            j++;
        }
        j=0;
        while(j<two)
        {
            nums[i]=2;
            i++;
            j++;
        }
    }
};
