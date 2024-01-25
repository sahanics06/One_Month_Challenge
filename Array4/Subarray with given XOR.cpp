/*
Problem Description
 
Given an array of integers A and an integer B.

Find the total number of subarrays having bitwise XOR of all elements equals to B.

Problem Constraints
1 <= length of the array <= 105

1 <= A[i], B <= 109

Input Format
The first argument given is the integer array A.

The second argument given is integer B.

Output Format
Return the total number of subarrays having bitwise XOR equals to B.

Example Input
Input 1:

 A = [4, 2, 2, 6, 4]
 B = 6
Input 2:

 A = [5, 6, 7, 8, 9]
 B = 5


Example Output
Output 1:

 4
Output 2:

 2

Example Explanation
Explanation 1:

 The subarrays having XOR of their elements as 6 are:
 [4, 2], [4, 2, 2, 6, 4], [2, 2, 6], [6]
Explanation 2:

 The subarrays having XOR of their elements as 5 are [5] and [5, 6, 7, 8, 9]

*/

// Solution storing the frequency of xor in map. x=xr^k , if x is present in map then ans+=mp[x]

int Solution::solve(vector<int> &a, int b) {
    unordered_map<int,int>mp;
    int n=a.size();
    int xr=0, ans=0;
    mp[xr]++;
    for(int i=0; i<n; i++)
    {
        xr^=a[i];
        int x=xr^b;
        ans+=mp[x];
        mp[xr]++;
    }
    return ans;    
}
