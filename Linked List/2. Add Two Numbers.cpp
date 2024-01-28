/*
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, 
and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example 1:

Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.
Example 2:

Input: l1 = [0], l2 = [0]
Output: [0]
Example 3:

Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1] 

Constraints:

The number of nodes in each linked list is in the range [1, 100].
0 <= Node.val <= 9
It is guaranteed that the list represents a number that does not have leading zeros.

*/

// Solution

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int c=0;
        ListNode *a, *b, *pt; // pt point to current node of answer
        a=l1;
        b=l2;
        while(a && b)
        {
            int t = a->val+b->val+c;
            c=t/10;
            t%=10;
            a->val=t;
            pt=a;
            a=a->next;
            b=b->next;
            //cout<<t<<endl;
        }
        // here pt will be at last node and not NULL
        if(a==NULL && b==NULL)
        { // 5+5=10
            if(c)
            {
                pt->next = new ListNode(1);
            }
            return l1;
        }
        cout<<pt->val<<endl;
        ListNode *last=NULL; // to keep pointer to last node to add new node in case of carry
        if(a)
        {
            pt->next=a;
            if(c)
            {
                while(a && c)
                {
                    int t= c+a->val;
                    a->val = t%10;
                    c=t/10;
                    last=a;
                    a=a->next;
                }
            }
            else
            {
                pt->next=a;
            }
        }
        if(b)
        {
            pt->next=b;
            
            if(c)
            {
                while(b && c)
                {
                    int t= c+b->val;
                    b->val = t%10;
                    c=t/10;
                    last=b;
                    b=b->next;
                }
            }
            else
            {
                pt->next=b;
            }
        }
        if(c)
        {
            last->next = new ListNode(1);
        }
        return l1;
    }
};
