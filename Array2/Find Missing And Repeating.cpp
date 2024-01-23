/*
Given an unsorted array Arr of size N of positive integers. One number 'A' from set {1, 2,....,N} is missing and 
one number 'B' occurs twice in array. Find these two numbers.

Example 1:

Input:
N = 2
Arr[] = {2, 2}
Output: 2 1
Explanation: Repeating number is 2 and 
smallest positive missing number is 1.
Example 2:

Input:
N = 3
Arr[] = {1, 3, 3}
Output: 3 2
Explanation: Repeating number is 3 and 
smallest positive missing number is 2.
Your Task:
You don't need to read input or print anything. Your task is to complete the function findTwoElement() which takes the array 
of integers arr and n as parameters and returns an array of integers of size 2 denoting the answer 
( The first index contains B and second index contains A.)

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)

Constraints:
2 ≤ N ≤ 105
1 ≤ Arr[i] ≤ N

*/

// Solution using sum of N natural numbers and sum of square of N natural numbers

class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, int n) {
        long long s1=0, s2=0, sn=0, s2n=0;
        // long long s2=0;
        // long long sn=0;
        // long long s2n=0;
        // long long n=N;
        sn=((long long)n*(long long)(n+1))/2;
        s2n=((long long)n*(long long)(n+1)*((long long)2*n+1))/6;
        for(int i=0; i<n; i++)
        {
            s1+=arr[i];
            s2+=(long long )arr[i]*(long long)arr[i];
        }
        // x is repeating and y is missing
        long long val1=0;
        long long val2=0;
        val1 = sn-s1; // y-x
        val2 = s2n-s2; // y^2-x^2;
        val2 = val2/val1; // y+x
        
        long long missing = (val1+val2)/2;
        long long repeating = missing - val1;
        return {(int)repeating, (int)missing};
    }
};
