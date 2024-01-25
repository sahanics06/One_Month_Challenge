/*
Given an array having both positive and negative integers. The task is to compute the length of the largest subarray with sum 0.

Example 1:

Input:
N = 8
A[] = {15,-2,2,-8,1,7,10,23}
Output: 5
Explanation: The largest subarray with
sum 0 will be -2 2 -8 1 7.
Your Task:
You just have to complete the function maxLen() which takes two arguments an array A and n, where n is the size of the array A and returns the length of the 
largest subarray with 0 sum.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

Constraints:
1 <= N <= 105
-1000 <= A[i] <= 1000, for each valid i

*/

// Solution using Hashmap. we store presum value in map[sum]=i . if we find remaining sum in hashmap then we update answe by i- mp[remainder].


class Solution{
    public:
    int maxLen(vector<int>&a, int n)
    {   
        // Your code here
        int ans=0, sum=0;
        unordered_map<int,int>mp;
        for(int i=0; i<n; i++)
        {
            sum+=a[i];
            if(sum==0)
                ans=max(ans, i+1);
            if(mp.find(sum)!=mp.end())
            {
                ans = max(ans, i-mp[sum]);
            }
            else
            {
                mp[sum]=i;
            }
        }
        return ans;
    }
};

// Solution using T.C- O(N*N) adding within for(j=i to n) since every time just one element s keeps adding.

class Solution{
    public:
    int maxLen(vector<int>&a, int n)
    {   
        // Your code here
        int ans=0, sum=0;
        for(int i=0; i<n; i++)
        {
            int sum=0;
            for(int j=i; j<n; j++)
            {
                sum+=a[j];
                if(sum==0)
                    ans = max(ans, j-i+1);
            }
        }
        return ans;
    }
};


// Solution using T.C- O(N*N*N) adding inside loop k=i to j for every subarray and updating answer = max(answer, j-i+1) 

class Solution{
    public:
    int maxLen(vector<int>&a, int n)
    {   
        // Your code here
        int ans=0;
        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                int sum=0;
                for(int k=i; k<=j; k++)
                {
                    sum+=a[k];
                }
                if(sum==0)
                    ans = max(ans, j-i+1);
            }
        }
        return ans;
    }
};
