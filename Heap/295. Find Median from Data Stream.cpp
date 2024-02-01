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


// Follow up

// If input is too large then how can we optimise
/*
If the input size becomes very large, you may need to optimize the MedianFinder class implementation to ensure efficient 
performance. Here are some strategies you can consider:

Use a Balanced Binary Search Tree (BST): Instead of using heaps, you can use a self-balancing binary search tree (BST) 
like Red-Black Tree or AVL Tree. This allows you to maintain the order of elements while inserting and finding the median 
efficiently. However, implementing a balanced BST from scratch can be complex, so you might want to use a library such as 
std::set in C++ which provides a red-black tree implementation.

Use MultiSet (C++ STL): If you're using C++, you can utilize std::multiset from the C++ Standard Library. It maintains a 
sorted list of elements with duplicates allowed. You can use two multiset containers to store the smaller half and larger 
half of the numbers separately. This approach simplifies the implementation compared to maintaining two heaps.

Approximation Techniques: For extremely large datasets where exact median calculation might be impractical, consider using 
approximation techniques. For example, you can use sampling methods to estimate the median with a certain level of 
confidence.

Batch Processing: If you have the flexibility to process data in batches, you can perform operations on smaller subsets 
of the data at a time, reducing memory requirements and improving performance.

Parallel Processing: If you have access to multiple cores or machines, you can parallelize the processing to distribute 
the workload and speed up the calculation of the median.

Stream Processing: If the data is coming from a stream or can be processed incrementally, you can update the median 
dynamically as new data arrives, rather than storing all data in memory. This approach is memory-efficient and suitable 
for real-time applications.

External Memory Algorithms: For extremely large datasets that cannot fit into memory, consider using external memory 
algorithms that operate directly on disk storage. These algorithms efficiently process data in chunks, minimizing the 
need for loading the entire dataset into memory.

Choose the optimization strategy based on your specific requirements, available resources, and constraints. 
Depending on the characteristics of your dataset and the platform you're working with, different approaches may 
be more suitable.
 */


//If 99% of all integer numbers from the stream are in the range [0, 100], how would you optimize your solution?
/*
If 99% of all integer numbers from the stream are in the range [0, 100], you can optimize the solution by focusing only on the numbers within this range. Here's how you can modify the MedianFinder class to take advantage of this information:

Counting Occurrences: Keep track of the count of each integer within the range [0, 100] using an array or a hashmap. This allows you to efficiently determine the median based on the frequency distribution of the numbers.

Dynamic Median Calculation: As new numbers arrive in the stream, update the count of each integer accordingly. You don't need to store all the numbers in memory, only their counts.

Compute Median: Based on the count of each integer, calculate the median dynamically without sorting the entire dataset. You can efficiently find the middle value or interpolate between two middle values if the count is even.

Here's a C++ implementation incorporating these optimizations:

cpp
Copy code

*/

#include <iostream>
#include <unordered_map>

class OptimizedMedianFinder {
public:
    OptimizedMedianFinder() : totalNumbers(0) {
        counts.resize(101, 0); // Initialize counts for integers in range [0, 100]
    }
    
    void addNum(int num) {
        if (num >= 0 && num <= 100) {
            counts[num]++;
            totalNumbers++;
        }
    }
    
    double findMedian() {
        int middle1 = (totalNumbers + 1) / 2; // Middle position for odd count
        int middle2 = totalNumbers / 2 + 1;    // Middle position for even count
        
        int count = 0;
        int num1 = -1, num2 = -1;
        for (int i = 0; i <= 100; ++i) {
            count += counts[i];
            if (num1 == -1 && count >= middle1) {
                num1 = i;
            }
            if (num2 == -1 && count >= middle2) {
                num2 = i;
            }
            if (num1 != -1 && num2 != -1) {
                break; // Found both middle numbers
            }
        }
        
        if (totalNumbers % 2 == 0) {
            return (num1 + num2) / 2.0; // Even count, return average of two middle numbers
        } else {
            return num1; // Odd count, return middle number
        }
    }

private:
    std::vector<int> counts; // Count of numbers in the range [0, 100]
    int totalNumbers;        // Total number of elements processed so far
};

int main() {
    OptimizedMedianFinder finder;

    // Example usage:
    finder.addNum(50);
    finder.addNum(25);
    finder.addNum(75);
    std::cout << "Median: " << finder.findMedian() << std::endl;

    return 0;
}
/*
This optimized solution efficiently handles the scenario where 99% of the integer numbers from the stream are within the 
range [0, 100] without storing all the numbers in memory. Instead, it maintains counts for each integer in the range 
and dynamically calculates the median based on the frequency distribution of the numbers.

 */

