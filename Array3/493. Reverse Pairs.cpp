/*
Given an integer array nums, return the number of reverse pairs in the array.

A reverse pair is a pair (i, j) where:

0 <= i < j < nums.length and
nums[i] > 2 * nums[j].

Example 1:

Input: nums = [1,3,2,3,1]
Output: 2
Explanation: The reverse pairs are:
(1, 4) --> nums[1] = 3, nums[4] = 1, 3 > 2 * 1
(3, 4) --> nums[3] = 3, nums[4] = 1, 3 > 2 * 1
Example 2:

Input: nums = [2,4,3,5,1]
Output: 3
Explanation: The reverse pairs are:
(1, 4) --> nums[1] = 4, nums[4] = 1, 4 > 2 * 1
(2, 4) --> nums[2] = 3, nums[4] = 1, 3 > 2 * 1
(3, 4) --> nums[3] = 5, nums[4] = 1, 5 > 2 * 1
 
Constraints:

1 <= nums.length <= 5 * 104
-231 <= nums[i] <= 231 - 1

  */

// Solution using merge sort

class Solution {
public:
    void merge(vector<int>&nums, int low, int mid, int high)
    {
        int right=mid+1, left=low;
        vector<int>tmp;
        while(left<=mid && right<=high)
        {
            if(nums[left]<=nums[right])
            {
                tmp.push_back(nums[left++]);
            }
            else
            {
                tmp.push_back(nums[right++]);
            }
        }
        while(left<=mid)
        {
            tmp.push_back(nums[left++]);
        }
        while(right<=high)
        {
            tmp.push_back(nums[right++]);
        }
        for(int i=low; i<=high; i++)
        {
            nums[i]=tmp[i-low];
        }
    }

    int count(vector<int>&nums, int l, int m, int r)
    {
        int j=m+1, ans=0;
        while(l<=m)
        {
            while(j<=r && nums[l]>2LL*nums[j])
            {
                j++;
            }
            ans= ans+(j-m-1);
            l++;
        }
        return ans;
    }

    int mergeSort(vector<int>&nums, int l, int r)
    {
        if(l>=r)
            return 0;
        int ans=0;
        int m=l+(r-l)/2;
        ans += mergeSort(nums, l, m);
        ans += mergeSort(nums, m+1, r);
        ans += count(nums, l, m, r);
        merge(nums, l, m, r);
        return ans;
    }
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size()-1);
//        return ans;
    }
};


// Solution using merge Sort and counting inside the merge function befor merging.

class Solution {
public:
    int merge(vector<int>&nums, int l, int mid, int r)
    {
        long long count=0;
        
        int j=mid+1;
        for(int i=l; i<=mid; i++)
        {
    //        cout<<nums[i]<<" ";
            while(j<=r && nums[i]>2LL*nums[j])
            {
                j++;
            }
            count+=j-(mid+1);
        }
        vector<int>tmp;
        int left=l,right=mid+1;
        while(left<=mid && right<=r)
        {
            if(nums[left]<=nums[right])
            {
                tmp.push_back(nums[left++]);
                
            }
            else
            {
                tmp.push_back(nums[right++]);
            }
        }
        while(left<=mid)
        {
            tmp.push_back(nums[left++]);
        }
        while(right<=r)
        {
            tmp.push_back(nums[right++]);
        }
        for(int i=l; i<=r; i++)
        {
            nums[i]=tmp[i-l];
        }
        return count;
    }
    
    int inv(vector<int>&v, int l, int r)
    {
        long long res=0;
        if(l>=r) return 0;
        
            int mid=l+(r-l)/2;
            res+=inv(v,l,mid);
            res+=inv(v,mid+1,r);
            res+=merge(v,l,mid,r);
           
        
        return res;
    }
    
    int reversePairs(vector<int>& nums) {
        return inv(nums,0,nums.size()-1);
    }
};
