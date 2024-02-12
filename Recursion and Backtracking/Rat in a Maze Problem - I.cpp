/*
Consider a rat placed at (0, 0) in a square matrix of order N * N. It has to reach the destination at (N - 1, N - 1). 
Find all possible paths that the rat can take to reach from source to destination. The directions in which the rat can move 
are 'U'(up), 'D'(down), 'L' (left), 'R' (right). Value 0 at a cell in the matrix represents that it is blocked and rat cannot
move to it while value 1 at a cell in the matrix represents that rat can be travel through it.
Note: In a path, no cell can be visited more than one time. If the source cell is 0, the rat cannot move to any other cell.

Example 1:

Input:
N = 4
m[][] = {{1, 0, 0, 0},
         {1, 1, 0, 1}, 
         {1, 1, 0, 0},
         {0, 1, 1, 1}}
Output:
DDRDRR DRDDRR
Explanation:
The rat can reach the destination at 
(3, 3) from (0, 0) by two paths - DRDDRR 
and DDRDRR, when printed in sorted order 
we get DDRDRR DRDDRR.
Example 2:
Input:
N = 2
m[][] = {{1, 0},
         {1, 0}}
Output:
-1
Explanation:
No path exists and destination cell is 
blocked.
Your Task:  
You don't need to read input or print anything. Complete the function printPath() which takes N and 2D array m[ ][ ] as 
input parameters and returns the list of paths in lexicographically increasing order. 
Note: In case of no path, return an empty list. The driver will output "-1" automatically.

Expected Time Complexity: O((3N^2)).
Expected Auxiliary Space: O(L * X), L = length of the path, X = number of paths.

Constraints:
2 ≤ N ≤ 5
0 ≤ m[i][j] ≤ 1

  */

// Solution-> Create a recursion function; if (x and y ==n-1) then push string in ans; else iterate in loop and if that 
// index is poosible then add the character in string and solve for next index.

class Solution{
    public:
    void solve(vector<vector<int>> &m, vector<string>&ans, vector<vector<int>>&vis, int dx[4], int dy[4], char dc[4], 
                int n, int x, int y, string tmp)
    {
        if(x==n-1 && y==n-1)
        {
            ans.push_back(tmp);
            return;
        }
        vis[y][x]=1; // mark as visited
        for(int i=0; i<4; i++)
        {
            int tx= x+dx[i];
            int ty= y+dy[i];
            if(tx<n && ty<n && tx>=0 && ty>=0 && m[ty][tx]==1 && vis[ty][tx]==0)
            {
                tmp.push_back(dc[i]);
                solve(m, ans, vis, dx, dy, dc, n, tx, ty, tmp);
                tmp.pop_back();
            }
        }
        vis[y][x]=0; // mark as unvisited
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        if(m[0][0]==0)
            return {};
        vector<vector<int>>vis(n, vector<int>(n, 0));
        int dx[]={0, 1, 0, -1};
        int dy[]={1, 0, -1, 0};
        char dc[]={'D', 'R', 'U', 'L'};
        vector<string>ans;
        string tmp="";
        solve(m, ans, vis, dx, dy, dc, n, 0, 0, tmp);
        return ans;
    }
};
