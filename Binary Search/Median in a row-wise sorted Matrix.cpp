/*
Given a row wise sorted matrix of size R*C where R and C are always odd, find the median of the matrix.

Example 1:

Input:
R = 3, C = 3
M = [[1, 3, 5], 
     [2, 6, 9], 
     [3, 6, 9]]
Output: 5
Explanation: Sorting matrix elements gives 
us {1,2,3,3,5,6,6,9,9}. Hence, 5 is median.  

Example 2:

Input:
R = 3, C = 1
M = [[1], [2], [3]]
Output: 2
Explanation: Sorting matrix elements gives 
us {1,2,3}. Hence, 2 is median.

Your Task:  
You don't need to read input or print anything. Your task is to complete the function median() which takes the integers R and C along with the 2D matrix as input 
parameters and returns the median of the matrix.

Expected Time Complexity: O(32 * R * log(C))
Expected Auxiliary Space: O(1)

Constraints:
1 <= R, C <= 400
1 <= matrix[i][j] <= 2000

  */

// Solution-> We find elements less than target; target= (R*C)/2; We will use binary search in l=min, r=high, m=(l+r)/2; we find elements less than m; 
// We find the partition till when elements is less than target

class Solution{   
public:
    int countUpper(vector<int>&mat, int C, int target)
    {
        int ans=C;
        int l=0, r=C-1;
        while(l<=r)
        {
            int mid=l+(r-l)/2;
            if(mat[mid]>target)
            {
                ans=mid;
                r=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
        return ans;
    }
    int count(vector<vector<int>>&mat, int R, int C, int target)
    {
        int c=0;
        for(int i=0; i<R; i++)
        {
            c+=countUpper(mat[i], C, target);
        }
        return c; 
    }
    int median(vector<vector<int>> &matrix, int R, int C){
        // code here     
        int l=INT_MAX, r=INT_MIN;
        for(int i=0; i<R; i++)
        {
            for(int j=0; j<C; j++)
            {
                l=min(l, matrix[i][j]);
                r=max(r, matrix[i][j]);
            }
        }
        int med = (R*C)/2;
        while(l<=r)
        {
            int m = l+(r-l)/2;
            int small_equals = count(matrix, R, C, m);
            if(small_equals<=med)
            {
                l=m+1;
            }
            else
            {
                r=m-1;
            }
        }
        return l;
    }
};
