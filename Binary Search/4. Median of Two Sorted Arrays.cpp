/*
Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).

Example 1:

Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.
Example 2:

Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
 
Constraints:

nums1.length == m
nums2.length == n
0 <= m <= 1000
0 <= n <= 1000
1 <= m + n <= 2000
-106 <= nums1[i], nums2[i] <= 106

  */

// Solution using Binary Search. Use Binary Search on the smallest arrays. 
// Partition and find the appropriate left half,  we find left by n+m+1/2

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size(), m=nums2.size();
        if(n>m)
            return findMedianSortedArrays(nums2, nums1);
        int l=0, r=n;
        int left = (n+m+1)/2;
        int t=n+m;
        while(l<=r)
        {
            int mid1=l+(r-l)/2;
            int mid2=left-mid1;
            int l1=INT_MIN, l2=INT_MIN;
            int r1=INT_MAX, r2=INT_MAX;
            if(mid1<n)  r1=nums1[mid1];
            if(mid2<m)  r2=nums2[mid2];
            if(mid1-1>=0)   l1=nums1[mid1-1];
            if(mid2-1>=0)   l2=nums2[mid2-1];
            if(l1<=r2 && l2<=r1)
            {
                if(t%2)
                    return max(l1,l2);
                else
                {
                    return (double)(max(l1,l2)+min(r1,r2))/2.0;
                }
            }
            if(l1>r2)
            {
                r=mid1-1;
            }
            else
            {
                l=mid1+1;
            }
        }
        return -1;
    }
};

// Solution Better

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;
        int i=0, j=0, n=nums1.size(), m=nums2.size();
        int idx1, idx2, c=0, e1, e2;
        idx1=(n+m)/2;
        idx2=(n+m)/2 -1;
        while(i<n && j<m)
        {
            if(nums1[i]<=nums2[j])
            {
                if(idx1==c)
                    e1=nums1[i];
                if(idx2==c)
                    e2=nums1[i];
                i++;
            }
            else
            {
                if(idx1==c)
                    e1=nums2[j];
                if(idx2==c)
                    e2=nums2[j];
                j++;
            }
            c++;
        }
        while(i<n)
        {
            if(idx1==c)
                e1=nums1[i];
            if(idx2==c)
                e2=nums1[i];
            i++;
            c++;
        }
        while(j<m)
        {
            if(idx1==c)
                e1=nums2[j];
            if(idx2==c)
                e2=nums2[j];
            j++;
            c++;
        }
        int t=n+m;
        if(t%2)
            return e1;
        else
        {
            return (double)(e1+e2)/2;
        }
    }
};


// Solution- Brute Force

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;
        int i=0, j=0, n=nums1.size(), m=nums2.size();
        while(i<n && j<m)
        {
            if(nums1[i]<=nums2[j])
            {
                ans.push_back(nums1[i]);
                i++;
            }
            else
            {
                ans.push_back(nums2[j]);
                j++;
            }
        }
        while(i<n)
        {
            ans.push_back(nums1[i]);
            i++;
        }
        while(j<m)
        {
            ans.push_back(nums2[j]);
            j++;
        }
        int t=n+m;
        if(t%2)
            return ans[t/2];
        else
        {
            return (double)(ans[t/2]+ans[t/2 -1])/2;
        }
    }
};

