/*
You have N books, each with A[i] number of pages. M students need to be allocated contiguous books, with each student getting 
at least one book.
Out of all the permutations, the goal is to find the permutation where the sum of maximum number of pages in a book allotted 
to a student should be minimum, out of all possible permutations.

Note: Return -1 if a valid assignment is not possible, and allotment should be in contiguous order (see the explanation 
for better understanding).

Example 1:

Input:
N = 4
A[] = {12,34,67,90}
M = 2
Output:113
Explanation:Allocation can be done in 
following ways:
{12} and {34, 67, 90} Maximum Pages = 191
{12, 34} and {67, 90} Maximum Pages = 157
{12, 34, 67} and {90} Maximum Pages =113.
Therefore, the minimum of these cases is 113,
which is selected as the output.

Example 2:

Input:
N = 3
A[] = {15,17,20}
M = 2
Output:32
Explanation: Allocation is done as
{15,17} and {20}
Your Task:
You don't need to read input or print anything. Your task is to complete the function findPages() which takes 2 Integers N, 
and m and an array A[] of length N as input and returns the expected answer.

Expected Time Complexity: O(NlogN)
Expected Auxilliary Space: O(1)

Constraints:
1 <= N <= 105
1 <= A [ i ] <= 106
1 <= M <= 105

  */

// Solution-> We use Binary Search from low=max of elements to sum; Then we check if it is poosible to distribute to 
// M students. We have to check that if number of students<=target student means that the number of pages considered is 
// high and so we can move r=m-1 and ans=m
// Example-> arr= 1,2,3,4,100; M=5 student; then we return min page as 100 ans; for same if M=2 then 
// also minimum page is 10, 100 so 100 is answer. So from Binary Search we have to consider ans=m and r=m-1

class Solution 
{
    public:
    //Function to find minimum number of pages.
    int solve(int a[], int n, int target)
    {
        int page=0, c=1;
        for(int i=0; i<n; i++)
        {
            if(page+a[i]<=target)
            {
                page+=a[i];
            }
            else
            {
                c++;
                page=a[i];
            }
        }
        return c;
    }
    int findPages(int a[], int N, int M) 
    {
        //code here
        if(M>N)
            return -1;
        int mx=INT_MIN;
        long long sum=0;
        for(int i=0; i<N; i++)
        {
            mx=max(mx, a[i]);
            sum+=a[i];
        }
        int l=mx, r=sum;
        int ans=-1;
        while(l<=r)
        {
            int m=l+(r-l)/2;
            int tmp=solve(a, N, m);
            if(tmp<=M)
            {
                ans=m;
                r=m-1;
            }
            else
            {
                l=m+1;
            }
        }
        return ans;
    }
};

// Solution-> We start from low=max of elements to sum; Then we check if it is poosible to distribute to M students.

class Solution 
{
    public:
    //Function to find minimum number of pages.
    int solve(int a[], int n, int target)
    {
        int page=0, c=1;
        for(int i=0; i<n; i++)
        {
            if(page+a[i]<=target)
            {
                page+=a[i];
            }
            else
            {
                c++;
                page=a[i];
            }
        }
        return c;
    }
    int findPages(int a[], int N, int M) 
    {
        //code here
        if(M>N)
            return -1;
        int mx=INT_MIN;
        long long sum=0;
        for(int i=0; i<N; i++)
        {
            mx=max(mx, a[i]);
            sum+=a[i];
        }
        for(int i=mx; i<=sum; i++)
        {
            int ct=solve(a, N, i);
            //cout<<i<<" "<<ct<<endl;
            if(ct<=M)
            {
                return i;
            }
                
        }
        return 0;
    }
};
