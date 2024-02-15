/*
You are given an array consisting of n integers which denote the position of a stall. You are also given an integer k 
which denotes the number of aggressive cows. You are given the task of assigning stalls to k cows such that the minimum 
distance between any two of them is the maximum possible.
The first line of input contains two space-separated integers n and k.
The second line contains n space-separated integers denoting the position of the stalls.

Example 1:

Input:
n=5 
k=3
stalls = [1 2 4 8 9]
Output:
3
Explanation:
The first cow can be placed at stalls[0], 
the second cow can be placed at stalls[2] and 
the third cow can be placed at stalls[3]. 
The minimum distance between cows, in this case, is 3, 
which also is the largest among all possible ways.
Example 2:

Input:
n=5 
k=3
stalls = [10 1 2 7 5]
Output:
4
Explanation:
The first cow can be placed at stalls[0],
the second cow can be placed at stalls[1] and
the third cow can be placed at stalls[4].
The minimum distance between cows, in this case, is 4,
which also is the largest among all possible ways.
Your Task:
Complete the function int solve(), which takes integer n, k, and a vector stalls with n integers as input and returns the 
largest possible minimum distance between cows.

Expected Time Complexity: O(n*log(10^9)).
Expected Auxiliary Space: O(1).

Constraints:
2 <= n <= 10^5
2 <= k <= n
0 <= stalls[i] <= 10^9

  */

//Solution-> Sort the array. We need to find max of minimum.The minimum distance between cows will be between adjacent cows.
//We take dist=1 to INT_MAX and find if that distance is possible to keep n cows at distance dist between them.
// Optimised will be to take dist using Binary Search

class Solution {
public:
    int count(vector<int>&stalls, int tmp)
    {
        int c=1, dist=stalls[0];
        for(int i=1; i<stalls.size(); i++)
        {
            if(stalls[i]-dist>=tmp)
            {
                c++;
                dist=stalls[i];
            }
        }
        return c;
    }
    int solve(int n, int k, vector<int> &stalls) {
        
        sort(stalls.begin(), stalls.end());
        int ans=1;
        int l=1, r=stalls[n-1];
        while(l<=r)
        {
            int mid = l+(r-l)/2;
            int tmp = count(stalls, mid);
            //cout<<mid<<" "<<tmp<<endl;
            if(tmp>=k)
            {
                ans=mid;
                l=mid+1;
            }
            else
            {
                r=mid-1;
            }
        }
        return ans;
    }
};

// Solution Sort the array. We need to find max of minimum. The minimum distance between cows will be between adjacent cows.
//We take dist=1 to INT_MAX and find if that distance is possible to keep n cows at distance dist between them.

class Solution {
public:
    int count(vector<int>&stalls, int tmp)
    {
        int c=1, dist=stalls[0];
        for(int i=1; i<stalls.size(); i++)
        {
            if(stalls[i]-dist>=tmp)
            {
                c++;
                dist=stalls[i];
            }
        }
        return c;
    }
    int solve(int n, int k, vector<int> &stalls) {
        
        sort(stalls.begin(), stalls.end());
        int ans=1;
        for(int i=1; i<1e9+8; i++)
        {
            int tmp = count(stalls, i);
            //cout<<tmp<<endl;
            if(tmp>=k)
            {
                ans=i;
            }
            else
            {
                break;
            }
        }
        return ans;
    }
};
