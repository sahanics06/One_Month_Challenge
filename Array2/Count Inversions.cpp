/*
Given an array of integers. Find the Inversion Count in the array. 

Inversion Count: For an array, inversion count indicates how far (or close) the array is from being sorted. 
If the array is already sorted then the inversion count is 0.
If an array is sorted in the reverse order then the inversion count is the maximum. 
Formally, two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j.
 
Example 1:

Input: N = 5, arr[] = {2, 4, 1, 3, 5}
Output: 3
Explanation: The sequence 2, 4, 1, 3, 5 
has three inversions (2, 1), (4, 1), (4, 3).
Example 2:

Input: N = 5
arr[] = {2, 3, 4, 5, 6}
Output: 0
Explanation: As the sequence is already 
sorted so there is no inversion count.
Example 3:

Input: N = 3, arr[] = {10, 10, 10}
Output: 0
Explanation: As all the elements of array 
are same, so there is no inversion count.
Your Task:

You don't need to read input or print anything.
Your task is to complete the function inversionCount() which takes the array arr[] and the size of the array as inputs 
and returns the inversion count of the given array.

Expected Time Complexity: O(NLogN).
Expected Auxiliary Space: O(N).

Constraints:
1 ≤ N ≤ 5*105
1 ≤ arr[i] ≤ 1018

*/

// Solution using merge sort 

class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long int ans=0;
    long long int merge(long long arr[], long long N, long long low, long long mid, long long high)
    {
        long long left = low, right = mid+1;
        //long long int ans=0;
        vector<long long> tmp;
        while(left<=mid && right<=high)
        {
            if(arr[left]<=arr[right])
            {
                tmp.push_back(arr[left]);
                left++;
            }
            else
            {
                tmp.push_back(arr[right]);
                ans+=(mid-left+1);
                right++;
            }
        }
        while(left<=mid)
        {
            tmp.push_back(arr[left++]);
        }
        while(right<=high)
        {
            tmp.push_back(arr[right++]);
        }
        for(long long i=low; i<=high; i++)
        {
            arr[i]=tmp[i-low];
        }
        //return ans;
    }
    
    void mergeSort(long long arr[], long long N, long long low, long long high)
    {
        if(low>=high)
            return;
        long long int ans=0;
        int mid = low + (high-low)/2;
        mergeSort(arr, N, low, mid);
        mergeSort(arr, N, mid+1, high);
        merge(arr, N, low, mid, high);
        //return ans;
    }
    
    long long int inversionCount(long long arr[], long long N)
    {
        // Your Code Here
        mergeSort(arr, N, 0, N-1);
        return ans;
    }

};
