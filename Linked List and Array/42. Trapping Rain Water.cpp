/*
Given n non-negative integers representing an elevation map where the width of each bar is 1, 
compute how much water it can trap after raining.

Example 1:

Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. 
In this case, 6 units of rain water (blue section) are being trapped.
Example 2:

Input: height = [4,2,0,3,2,5]
Output: 9

Constraints:

n == height.length
1 <= n <= 2 * 104
0 <= height[i] <= 105

  */


// Solution using two pointer concept. 

class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size(), ans=0;
        int left=0, right=n-1;
        int mxleft=0, mxright=0;
        while(left<=right)
        {
            if(height[left]<=height[right]) // this check the condition that there is a block greater than 
                                            // left so now we can store the water;
            {
                if(height[left]>mxleft)
                {
                    mxleft=height[left];
                }
                else
                {
                    ans+=(mxleft-height[left]);
                }
                left++;
            }
            else
            {
                if(height[right]>mxright)
                {
                    mxright=height[right];
                }
                else
                {
                    ans+=(mxright-height[right]);
                }
                right--;
            }
        }
        return ans;
    }
};


// Solution- Using two vector to keep the left max  and right max height of indexes. 
// T.C- O(N), Space- O(2N)

class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size(), ans=0;
        vector<int>left(n), right(n);
        int mx=0;
        for(int i=0; i<n; i++)
        {
            mx=max(height[i], mx);
            left[i]=mx;
        }
        mx=0;
        for(int i=n-1; i>=0; i--)
        {
            mx=max(height[i], mx);
            right[i]=mx;
        }
        for(int i=1; i<n-1; i++)
        {
            ans+=(min(left[i], right[i])-height[i]);
        }
        return ans;
    }
};




// Brute Force
// Solution - for every index from i=1 to i<n-1 we find the maximum height towards its left and maximum height towards 
// its right then ans+=min(leftHeight, rightHeight)-height[i]

class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size(), ans=0;
        for(int i=1; i<n-1; i++)
        {
            int j=0, k=n-1;
            int mn=0, mx=0;
            while(j<=i)
            {
                mn=max(height[j], mn);
                j++;
            }
            while(k>=i)
            {
                mx=max(height[k], mx);
                k--;
            }
            ans+=(min(mn, mx)-height[i]);
        }
        return ans;
    }
};
