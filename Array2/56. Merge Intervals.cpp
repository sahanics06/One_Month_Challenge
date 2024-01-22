/*
Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the 
non-overlapping intervals that cover all the intervals in the input.

Example 1:

Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].
Example 2:

Input: intervals = [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.
 
Constraints:

1 <= intervals.length <= 104
intervals[i].length == 2
0 <= starti <= endi <= 104

  */

// Solution optimised T.C- NlogN + N

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>ans;
        sort(intervals.begin(), intervals.end());
        int n = intervals.size();
        for(int i=0; i<n; i++)
        {
            // if ans is empty or new interval range has come then we enter that in ans
            if(ans.empty() || ans.back()[1]< intervals[i][0])
            {
                ans.push_back(intervals[i]);
            }
            else
            {
                //if merge range than update the second value to max value
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            }
        }
        return ans;
    }
};

// Solution T.C- Nlog + 2N

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>ans;
        sort(intervals.begin(), intervals.end());
        int n = intervals.size();
        for(int i=0; i<n; i++)
        {
            int l=intervals[i][0];
            int r=intervals[i][1];

          // take every interval and check whethter it is in answer or not
            if(!ans.empty() && ans.back()[1]>=r)
                    continue;
            for(int j=i+1; j<n; j++)
            {
                if(intervals[j][0]<=r)
                {
                    r=max(r, intervals[j][1]);
                }
                else
                {
                    break;
                }
            }
            ans.push_back({l,r});
        }
        return ans;
    }
};
