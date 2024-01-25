/*
Given an array containing N integers and an integer K., Your task is to find the length of the longest Sub-Array with the sum of the elements equal to the given value K.

Example 1:

Input :
A[] = {10, 5, 2, 7, 1, 9}
K = 15
Output : 4
Explanation:
The sub-array is {5, 2, 7, 1}.
Example 2:

Input : 
A[] = {-1, 2, 3}
K = 6
Output : 0
Explanation: 
There is no such sub-array with sum 6.
Your Task:
This is a function problem. The input is already taken care of by the driver code. You only need to complete the function lenOfLongSubarr() that takes an array 
(A), sizeOfArray (n),  sum (K)and returns the required length of the longest Sub-Array. The driver code takes care of the printing.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

Constraints:
1<=N<=105
-105<=A[i], K<=105

  */

// Solution using two pointers. Best solution O(N) if array elements >=0.

int longestSubarrayWithSumK(vector<int> a, long long k) {
    // Write your code here
    int ans=0, n=a.size();
    long long sum=0;
    int i=0, j=0;
    while(i<n)
    {
        sum+=a[i];
        if(sum==k)
        {
            ans = max(ans, i-j+1);
        }
        if(sum>k)
        {
            while(sum>k)
            {
                sum-=a[j];
                j++;
            }
            if(sum==k)
            {
                ans= max(ans, i-j+1);
            }
        }
        i++;
    }
    return ans;
}

// Solution, best solution if array contains both negative and positive numbers.
// if sum==k update answer; if sum-k is present in map then answer=max(answer, i-mp[sum-k]); if sum-k is not present in map then mp[sum-k]=i

class Solution{
    public:
    int lenOfLongSubarr(int arr[],  int n, int k) 
    { 
        int ans=0, sum=0;
        
        unordered_map<int,int>mp;
        
        for(int i=0; i<n; i++)
        {
            sum+=arr[i];
            if(sum==k)
            {
                ans=max(ans, i+1);
            }
            int rem = sum-k;
            
            if(mp.find(rem)!=mp.end())
            {
                ans=max(ans, i-mp[rem]);
            }
            if(mp.find(sum)==mp.end())
            {
                mp[sum]=i;
            }
        }
        return ans;
    } 

};
