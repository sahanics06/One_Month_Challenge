/*
Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.

You must do it in place.

Example 1:

Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
Output: [[1,0,1],[0,0,0],[1,0,1]]
Example 2:

Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]] 

Constraints:

m == matrix.length
n == matrix[0].length
1 <= m, n <= 200
-231 <= matrix[i][j] <= 231 - 1

  */

// Solution using constant space. Keeping in mind that (0,0) will be common for first row and first column. So to mark first column we store in different variable "col"
// and in (0,0) we keep the marking for (0,i). While feeling the first row and first column we first feel the row starting from extreme end because if we first fill the 
// first column then we might fill (0,0) and because of this while filling the first row it will make all values of first row as 1.

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix[0].size(), m = matrix.size(), col=1;
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(matrix[i][j]==0)
                {
                    matrix[i][0]=0;
                    if(j!=0)
                    {
                        matrix[0][j]=0;
                    }
                    else
                    {
                        col=0;
                    }
                }
            }
        }
        // for(int i=0; i<n; i++)
        // {
        //     if(matrix[i][0]==0)
        //     {
        //         col=0;
        //         break;
        //     }
        // }

        for(int i=m-1; i>0; i--)
        {
            for(int j=n-1; j>0; j--)
            {
                if(matrix[0][j]==0 || matrix[i][0]==0)
                {
                    matrix[i][j]=0;
                }
            }
        }

        for(int i=n-1; i>0; i--)
        {
            if(matrix[0][0]==0)
            {
                matrix[0][i]=0;
            }
        }
        if(col==0)
        {
            for(int i=0; i<m; i++)
            {
                matrix[i][0]=0;
            }
        }
    }
};

// Solution using space to keep column and row marking.

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix[0].size(), m = matrix.size();
        vector<int>col(n, 0), row(m, 0);
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(matrix[i][j]==0)
                {
                    col[j]=1;
                    row[i]=1;
                }
            }
        }

        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(col[j])
                {
                    matrix[i][j]=0;
                }
                if(row[i])
                {
                    matrix[i][j]=0;
                }
            }
        }
    }
};
