/*
You are given 2 numbers (n , m); the task is to find n√m (nth root of m).
 
Example 1:

Input: n = 2, m = 9
Output: 3
Explanation: 32 = 9
Example 2:

Input: n = 3, m = 9
Output: -1
Explanation: 3rd root of 9 is not
integer.

Your Task:
You don't need to read or print anyhting. Your task is to complete the function NthRoot() which takes n and m as input parameter and returns the nth root of m. 
If the root is not integer then returns -1.
 
Expected Time Complexity: O(n* log(m))
Expected Space Complexity: O(1)

Constraints:
1 <= n <= 30
1 <= m <= 109

*/

// Solution

class Solution{
	public:
	int power(int mid, int n, int m)
	{
	    long long ans=1;
	    for(int i=1; i<=n; i++)
	    {
	        ans*=mid;
	        if(ans>m)
	            return 2;
	    }
	    if(ans==m)
	        return 1;
	   return 0; // if ans<m
	}
	int NthRoot(int n, int m)
	{
	    // Code here.
	    if(n==1 || m==1)
	        return m;
	    int i=1, j=m;
	    while(i<=j)
	    {
	        int mid= i+(j-i)/2;
	        int t=power(mid, n, m);
	        if(t==1)
	            return mid;
	        else if(t==0)
	        {
	            i=mid+1;
	        }
	        else
	        {
	            j=mid-1;
	        }
	    }
	    return -1;
	}  
};
