/*
Implement a first in first out (FIFO) queue using only two stacks. The implemented queue should support all the functions of a normal queue (push, peek, pop, and empty).

Implement the MyQueue class:

void push(int x) Pushes element x to the back of the queue.
int pop() Removes the element from the front of the queue and returns it.
int peek() Returns the element at the front of the queue.
boolean empty() Returns true if the queue is empty, false otherwise.
Notes:

You must use only standard operations of a stack, which means only push to top, peek/pop from top, size, and is empty operations are valid.
Depending on your language, the stack may not be supported natively. You may simulate a stack using a list or deque (double-ended queue) as long as you use only a 
stack's standard operations.
 

Example 1:

Input
["MyQueue", "push", "push", "peek", "pop", "empty"]
[[], [1], [2], [], [], []]
Output
[null, null, null, 1, 1, false]

Explanation
MyQueue myQueue = new MyQueue();
myQueue.push(1); // queue is: [1]
myQueue.push(2); // queue is: [1, 2] (leftmost is front of the queue)
myQueue.peek(); // return 1
myQueue.pop(); // return 1, queue is [2]
myQueue.empty(); // return false
 

Constraints:

1 <= x <= 9
At most 100 calls will be made to push, pop, peek, and empty.
All the calls to pop and peek are valid.
 

Follow-up: Can you implement the queue such that each operation is amortized O(1) time complexity? In other words, performing n operations will take overall O(n) 
time even if one of those operations may take longer.

  */

// Solution using two stack input and output; In push() we only push in input; In pop() we pop only from output stack, if output is empty then we push all elements 
// from input to output; for peak() or top() we only we top element from output stack only, if output is empty then push all elements from input to output. 
// For empty() return input.empty() && output.empty()

class MyQueue {
public:
    stack<int>input, output;
    MyQueue() {
        
    }
    
    void push(int x) {
        input.push(x);
    }
    
    int pop() {
        if(output.empty())
        {
            while(!input.empty())
            {
                output.push(input.top());
                input.pop();
            }
        }
        int tmp = output.top();
        output.pop();
        return tmp;
    }
    
    int peek() {
        if(output.empty())
        {
            while(!input.empty())
            {
                output.push(input.top());
                input.pop();
            }
        }
        int tmp = output.top();
        return tmp;
    }
    
    bool empty() {
        return input.empty() && output.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */



// Solution using two stack; first and second; push all elements from first to second; push num in first; while(second) push all elements to first.

class MyQueue {
public:
    stack<int>first, second;
    MyQueue() {
        
    }
    
    void push(int x) {
        while(!first.empty())
        {
            second.push(first.top());
            first.pop();
        }
        first.push(x);
        while(!second.empty())
        {
            first.push(second.top());
            second.pop();
        }
    }
    
    int pop() {
        int tmp = first.top();
        first.pop();
        return tmp;
    }
    
    int peek() {
        return first.top();
    }
    
    bool empty() {
        return first.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
