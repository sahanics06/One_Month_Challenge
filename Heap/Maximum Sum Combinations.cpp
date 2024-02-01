/*
Problem Description
 
Given two equally sized 1-D arrays A, B containing N integers each.

A sum combination is made by adding one element from array A and another element of array B.

Return the maximum C valid sum combinations from all the possible sum combinations.

Problem Constraints
1 <= N <= 105

1 <= A[i] <= 105

1 <= C <= N

Input Format
First argument is an one-dimensional integer array A of size N.

Second argument is an one-dimensional integer array B of size N.

Third argument is an integer C.

Output Format
Return a one-dimensional integer array of size C denoting the top C maximum sum combinations.

NOTE:

The returned array must be sorted in non-increasing order.

Example Input
Input 1:

 A = [3, 2]
 B = [1, 4]
 C = 2
Input 2:

 A = [1, 4, 2, 3]
 B = [2, 5, 1, 6]
 C = 4

Example Output
Output 1:

 [7, 6]
Output 1:

 [10, 9, 9, 8]

Example Explanation
Explanation 1:

 7     (A : 3) + (B : 4)
 6     (A : 2) + (B : 4)
Explanation 2:

 10   (A : 4) + (B : 6)
 9   (A : 4) + (B : 5)
 9   (A : 3) + (B : 6)
 8   (A : 3) + (B : 5)

  */

// Solution- Efficient approach; We first sort both the array in decescending order. We use prirority queue to find the top element and indexes of sum we got from. 
// For every insert in PQ we have two options (i+1,j) and (i, j+1);   T.C- O(ClogN), Space- O(2N) for priority queue

vector<int> Solution::solve(vector<int> &a, vector<int> &b, int c) {
    sort(a.begin(), a.end(), greater<int>());
    sort(b.begin(), b.end(), greater<int>());
    priority_queue<pair<int, pair<int,int>>>pq;
    vector<int>ans;
    set<pair<int,int>>st;
    int n=a.size(), m=b.size();
    pq.push({a[0]+b[0], {0,0}});
    st.insert({0,0});
    for(int k=0; k<c; k++)
    {
        pair<int, pair<int,int>>tmp=pq.top();
        int sum=tmp.first;
        ans.push_back(sum);
        int i=tmp.second.first;
        int j=tmp.second.second;
        pq.pop();
        if(i+1<n && st.find({i+1, j})==st.end())
        {
            pq.push({a[i+1]+b[j], {i+1, j}});
            st.insert({i+1,j});
        }
        if(j+1<m && st.find({i, j+1})==st.end())
        {
            pq.push({a[i]+b[j+1], {i, j+1}});
            st.insert({i, j+1});
        }
    }
    return ans;
}
