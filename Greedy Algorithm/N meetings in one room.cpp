/*
There is one meeting room in a firm. There are N meetings in the form of (start[i], end[i]) where start[i] is start time of meeting i and end[i] is finish time of meeting i.
What is the maximum number of meetings that can be accommodated in the meeting room when only one meeting can be held in the meeting room at a particular time?

Note: Start time of one chosen meeting can't be equal to the end time of the other chosen meeting.

Example 1:

Input:
N = 6
start[] = {1,3,0,5,8,5}
end[] =  {2,4,6,7,9,9}
Output: 
4
Explanation:
Maximum four meetings can be held with
given start and end timings.
The meetings are - (1, 2),(3, 4), (5,7) and (8,9)
Example 2:

Input:
N = 3
start[] = {10, 12, 20}
end[] = {20, 25, 30}
Output: 
1
Explanation:
Only one meetings can be held
with given start and end timings.

Your Task :
You don't need to read inputs or print anything. Complete the function maxMeetings() that takes two arrays start[] and end[] along with their size N as input parameters 
and returns the maximum number of meetings that can be held in the meeting room.

Expected Time Complexity : O(N*LogN)
Expected Auxilliary Space : O(N)

Constraints:
1 ≤ N ≤ 105
0 ≤ start[i] < end[i] ≤ 105

  */

// Solution using creating a structure to keep start, end and index of the elements. Sort by end. If end time is same then keep the element occuring first in the array 
// as first i.e. keep the order. Now use a loop and find the add in answer if end time is smaller than the present start time.

class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    struct meeting
    {
      int start;
      int end;
      int index;
    };
    static bool comp(struct meeting a, struct meeting b)
    {
        if(a.end<b.end)
            return true;
        else if(a.end>b.end)
            return false;
        else if(a.index<b.index)
            return true;
        return false;
    }
    int maxMeetings(int start[], int end[], int n)
    {
        struct meeting tmp[n];
        for(int i=0; i<n; i++)
        {
            tmp[i].start= start[i];
            tmp[i].end=end[i];
            tmp[i].index = i;
        }
        sort(tmp, tmp+n, comp);
        int ans=1;
        int cur=tmp[0].end;
        for(int i=1; i<n; i++)
        {
            if(cur<tmp[i].start)
            {
                ans++;
                cur=tmp[i].end;
            }
        }
        return ans;
    }
};
