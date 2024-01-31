/*
Given a set of N jobs where each jobi has a deadline and profit associated with it.

Each job takes 1 unit of time to complete and only one job can be scheduled at a time. We earn the profit associated with job if and only if the job is completed by 
its deadline.

Find the number of jobs done and the maximum profit.

Note: Jobs will be given in the form (Jobid, Deadline, Profit) associated with that Job. Deadline of the job is the time before which job needs to be completed to 
earn the profit.

Example 1:

Input:
N = 4
Jobs = {(1,4,20),(2,1,10),(3,1,40),(4,1,30)}
Output:
2 60
Explanation:
Job1 and Job3 can be done with
maximum profit of 60 (20+40).
Example 2:

Input:
N = 5
Jobs = {(1,2,100),(2,1,19),(3,2,27),
        (4,1,25),(5,1,15)}
Output:
2 127
Explanation:
2 jobs can be done with
maximum profit of 127 (100+27).

Your Task :
You don't need to read input or print anything. Your task is to complete the function JobScheduling() which takes an integer N and an array of 
Jobs(Job id, Deadline, Profit) as input and returns the count of jobs and maximum profit as a list or vector of 2 elements.

Expected Time Complexity: O(NlogN)
Expected Auxilliary Space: O(N)

Constraints:
1 <= N <= 105
1 <= Deadline <= N
1 <= Profit <= 500

  */

// Solution- Sort the arr according to profit; we find the maximum deadline mx from the array and create an array of size slot(mx+1,-1); We add the job at the maximum 
// of its deadline possible because then only we can add more jobs within that range. Then we loop from j=arr[i].dead to j>0 if(slot[j]==-1) 
// then we add profit and slot[j]=arr[i].id and break;

class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    static bool comp(Job a, Job b)
    {
        return a.profit>b.profit;
    }
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        sort(arr, arr+n, comp);
        int mx=0;
        for(int i=0; i<n; i++)
            mx=max(mx, arr[i].dead);
        int profit=0, job=0;
        vector<int>slot(mx+1, -1);
        for(int i=0; i<n; i++)
        {
            for(int j=arr[i].dead; j>0; j--)
            {
                if(slot[j]==-1)
                {
                    job++;
                    profit+=arr[i].profit;
                    slot[j]=arr[i].id;
                    break;
                }
            }
        }
        return {job, profit};
    } 
};
