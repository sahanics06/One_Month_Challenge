/*
Given the head of a linked list, remove the nth node from the end of the list and return its head.

Example 1:

Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]
Example 2:

Input: head = [1], n = 1
Output: []
Example 3:

Input: head = [1,2], n = 1
Output: [1]
 
Constraints:

The number of nodes in the list is sz.
1 <= sz <= 30
0 <= Node.val <= 100
1 <= n <= sz

  */

// Solution using one pass.

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* cur=head;
        int i=0;
        while(i<n)
        {
            i++;
            cur=cur->next;
        }
        ListNode* prev=head;
        if(cur==NULL) 
            return head->next;
        while(cur->next)
        {
            prev=prev->next;
            cur=cur->next;
        }
        prev->next=prev->next->next;
        return head;

    }
};


// Solution

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int c=0;
        ListNode* cur=head;
        while(cur)
        {
            c++;
            cur=cur->next;
        }
        int rem=c-n;
        if(rem==0)
            return head->next;
        cur=head;
        while(rem)
        {
            rem--;
            if(rem==0)
            {
                cur->next=cur->next->next;
            }
            cur=cur->next;
        }
        return head;
    }
};
