/*
You are given an m x n integer matrix matrix with the following two properties:

Each row is sorted in non-decreasing order.
The first integer of each row is greater than the last integer of the previous row.
Given an integer target, return true if target is in matrix or false otherwise.

You must write a solution in O(log(m * n)) time complexity.

Example 1:

Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
Output: true
Example 2:

Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
Output: false 

Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 100
-104 <= matrix[i][j], target <= 104

  */

// Binary Search using only while

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size()-1, n=matrix[0].size()-1;
        int l=0, r=m;
        while(l<=r)
        {
            int mid = l+(r-l)/2;
            if(matrix[mid][n]>=target && matrix[mid][0]<=target)
            {
                int low=0, high = n;
                while(low<=high)
                {
                    int middle = low+(high-low)/2;
                    if(matrix[mid][middle]==target)
                        return true;
                    else if(matrix[mid][middle]>target)
                    {
                        high = middle-1;
                    }
                    else
                    {
                        low = middle+1;
                    }

                }
                return false;
            }
            else if(matrix[mid][n]>target)
            {
                r=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
        return false;
    }
};

// Solution using Binary Search. Using function to search.

class Solution {
public:
    bool solve(vector<vector<int>>& mat, int m, int n, int target)
    {
        int l=0, r=n;
        while(l<=r)
        {
            int mid=l+(r-l)/2;
            if(mat[m][mid]==target)
                return true;
            else if(mat[m][mid]>target)
            {
                r=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size()-1, n=matrix[0].size()-1;
        int l=0, r=m;
        while(l<=r)
        {
            int mid = l+(r-l)/2;
            if(matrix[mid][n]>=target && matrix[mid][0]<=target)
            {
                bool ans = solve(matrix, mid, n, target);
                    return ans;
            }
            else if(matrix[mid][n]>target)
            {
                r=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
        return false;
    }
};
