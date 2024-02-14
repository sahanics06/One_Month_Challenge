/*
Given two sorted arrays arr1 and arr2 of size N and M respectively and an element K. 
The task is to find the element that would be at the kth position of the final sorted array. 

Example 1:

Input:
arr1[] = {2, 3, 6, 7, 9}
arr2[] = {1, 4, 8, 10}
k = 5
Output:
6
Explanation:
The final sorted array would be -
1, 2, 3, 4, 6, 7, 8, 9, 10
The 5th element of this array is 6.
Example 2:
Input:
arr1[] = {100, 112, 256, 349, 770}
arr2[] = {72, 86, 113, 119, 265, 445, 892}
k = 7
Output:
256
Explanation:
Final sorted array is - 72, 86, 100, 112,
113, 119, 256, 265, 349, 445, 770, 892
7th element of this array is 256.

Your Task:  
You don't need to read input or print anything. Your task is to complete the function kthElement() which takes the arrays 
arr1[], arr2[], its size N and M respectively and an integer K as inputs and returns the element at the Kth position.

Expected Time Complexity: O(Log(N) + Log(M))
Expected Auxiliary Space: O(Log (N))

Constraints:
1 <= N, M <= 106
0 <= arr1i, arr2i < INT_MAX
1 <= K <= N+M

*/

// Solution-> Using Binary Search. 
// Use Binary Search on the smallest array. Partition and find the appropriate left half,  we find left by n+m+1/2
// Here we have to check for atleast minimum elements to be consider for 'l' and max element for 'r'

class Solution{
    public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        if(n>m)
            return kthElement(arr2, arr1, m, n, k);
        int t=n+m;
        int l=max(0, k-m), r=min(n,k);
        while(l<=r)
        {
            int mid1=l+(r-l)/2;
            int mid2=k-mid1;
            int l1=INT_MIN, l2=INT_MIN;
            int r1=INT_MAX, r2=INT_MAX;
            if(mid1<n)  r1=arr1[mid1];
            if(mid2<m)  r2=arr2[mid2];
            if(mid1-1>=0)   l1=arr1[mid1-1];
            if(mid2-1>=0)   l2=arr2[mid2-1];
            if(l1<=r2 && l2<=r1)
                return max(l1,l2);
            if(l1>r2)
            {
                r=mid1-1;
            }
            else
            {
                l=mid1+1;
            }
        }
        return 0;
    }
};
