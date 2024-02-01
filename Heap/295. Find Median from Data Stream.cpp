/*
The median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value, 
and the median is the mean of the two middle values.

For example, for arr = [2,3,4], the median is 3.
For example, for arr = [2,3], the median is (2 + 3) / 2 = 2.5.
Implement the MedianFinder class:

MedianFinder() initializes the MedianFinder object.
void addNum(int num) adds the integer num from the data stream to the data structure.
double findMedian() returns the median of all elements so far. Answers within 10-5 of the actual answer will be accepted.
 
Example 1:

Input
["MedianFinder", "addNum", "addNum", "findMedian", "addNum", "findMedian"]
[[], [1], [2], [], [3], []]
Output
[null, null, null, 1.5, null, 2.0]

Explanation
MedianFinder medianFinder = new MedianFinder();
medianFinder.addNum(1);    // arr = [1]
medianFinder.addNum(2);    // arr = [1, 2]
medianFinder.findMedian(); // return 1.5 (i.e., (1 + 2) / 2)
medianFinder.addNum(3);    // arr[1, 2, 3]
medianFinder.findMedian(); // return 2.0
 
Constraints:

-105 <= num <= 105
There will be at least one element in the data structure before calling findMedian.
At most 5 * 104 calls will be made to addNum and findMedian.

*/

// Solution Efficient- Use two priority queue; left as max heap and right as min heap. We maintain two half. 
// So that when median is called we can get the min and max in O(1). While adding number we check that element of left 
// pq is smaller than right pq; if difference between size of left and right becomes greater than 1 then we pop an element 
// from one and puch it to another.

class MedianFinder {
public:
    priority_queue<int>left;
    priority_queue<int, vector<int>, greater<int>>right;
    MedianFinder() {        
    }
    
    void addNum(int num) {
        left.push(num);
        if(left.size() && right.size() && left.top()>right.top())
        {
            int tmp=left.top();
            left.pop();
            right.push(tmp);
        }
        if(left.size()>right.size()+1)
        {
            int tmp=left.top();
            left.pop();
            right.push(tmp);
        }
        if(right.size()>left.size()+1)
        {
            int tmp=right.top();
            right.pop();
            left.push(tmp);
        }
    }
    
    double findMedian() {
        if(left.size()>right.size())
            return left.top();
        if(right.size()>left.size())
            return right.top();
        return (double)((left.top()+right.top()))/2;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
