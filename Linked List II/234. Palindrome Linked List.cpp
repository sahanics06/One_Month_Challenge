/*
Given the head of a singly linked list, return true if it is a 
palindrome
 or false otherwise. 

Example 1:

Input: head = [1,2,2,1]
Output: true
Example 2:

Input: head = [1,2]
Output: false
 
Constraints:

The number of nodes in the list is in the range [1, 105].
0 <= Node.val <= 9

  */

// Solution using reversing the half of the link list. To find half we use slow and fast pointer.

class Solution {
public:
    ListNode * reverse(ListNode *head)
    {
        ListNode *cur=head, *prev=NULL;
        while(cur)
        {
            ListNode *tmp=cur->next;
            cur->next=prev;
            prev=cur;
            cur=tmp;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        if(head->next==NULL)
            return true;
        ListNode *slow=head, *fast=head->next;
        while(fast && fast->next)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode *t=slow;
        slow=slow->next;
        t->next=NULL; // make the node at middle as NULL
        cout<<t->val<<" "<<slow->val<<endl;
        fast=head;
        ListNode *tmp= reverse(slow);
        while(tmp)
        {
            if(tmp->val!= fast->val)
                return false;
            tmp=tmp->next;
            fast=fast->next;
        }
        return true;
    }
};

// Solution using pushing the stack till half of the link list

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        stack<int>st;
        ListNode *cur=head;
        int c=0;
        while(cur)
        {
            c++;
            cur=cur->next;
        }
        cur=head;
        for(int i=0; i<c/2; i++)
        {
            st.push(cur->val);
            cur=cur->next;
        }
        //cout<<cur->val<<endl;
        if(c%2)
        {
            cur=cur->next;
        }
        while(!st.empty())
        {
            int tmp= st.top();
            st.pop();
            if(tmp!=cur->val)
            {
                return false;
            }
            cur=cur->next;
        }
        return true;
    }
};
