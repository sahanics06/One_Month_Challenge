/*
Given an array of size N-1 such that it only contains distinct integers in the range of 1 to N. Find the missing element.

Example 1:

Input:
N = 5
A[] = {1,2,3,5}
Output: 4
Example 2:

Input:
N = 10
A[] = {6,1,2,8,3,4,7,10,5}
Output: 9

Your Task :
You don't need to read input or print anything. Complete the function MissingNumber() that takes array and N as input  
parameters and returns the value of the missing number.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)

Constraints:
1 ≤ N ≤ 106
1 ≤ A[i] ≤ 106

*/

// Solution using efficient XOR

class Solution{
  public:
    int missingNumber(vector<int>& array, int n) {
        int xr=0;
        for(int i=0; i<n-1; i++) // loop will run from 0 to n-1 for n
        {
            xr^=array[i];
            xr^=(i+1);
        }
        return xr^n; // here at last we have done xor with n
    }
};


// Solution using XOR

class Solution{
  public:
    int missingNumber(vector<int>& array, int n) {
        int xr=0, xr1=0;
        for(int i=0; i<n-1; i++)
        {
            xr^=array[i];
        }
        for(int i=1; i<=n; i++)
        {
            xr1^=i;
        }
        return xr^xr1;
    }
};


// Solution using sum of natural number formula

class Solution{
  public:
    int missingNumber(vector<int>& array, int n) {
        // Your code goes here
        long long ans = n*(n+1)/2;
        long long sum=0;
        for(int i=0; i<n-1; i++)
        {
            sum+=array[i];
        }
        return ans-sum;
    }
};
