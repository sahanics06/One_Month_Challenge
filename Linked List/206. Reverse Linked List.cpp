/*
Given the head of a singly linked list, reverse the list, and return the reversed list.

Example 1:

Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]
Example 2:

Input: head = [1,2]
Output: [2,1]
Example 3:

Input: head = []
Output: []

Constraints:

The number of nodes in the list is the range [0, 5000].
-5000 <= Node.val <= 5000

  */

// Solution optimised using recursion

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==NULL || head->next==NULL)
        {
            return head;
        }
        ListNode* newHead = reverseList(head->next);
        ListNode *front= head->next;
        front->next = head;
        head->next=NULL;
        return newHead;
    }
};

// Solution optimised using iteration

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *cur=head, *prev=NULL, *tmp=NULL;
        while(cur)
        {
            tmp=cur->next;
            cur->next=prev;
            prev=cur;
            cur=tmp;
        }
        return prev;
    }
};

// Solution using stack and then putting the top element in head and go next
// T.C- O(N), S.C- O(N)

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *cur=head;
        stack<int>st;
        while(cur)
        {
            st.push(cur->val);
            cur=cur->next;
        }
        cur=head;
        while(cur)
        {
            cur->val=st.top();
            st.pop();
            cur=cur->next;
        }
        return head;
    }
};
