/*
Given the head of a linked list, rotate the list to the right by k places.

Example 1:

Input: head = [1,2,3,4,5], k = 2
Output: [4,5,1,2,3]
Example 2:

Input: head = [0,1,2], k = 4
Output: [2,0,1]

Constraints:

The number of nodes in the list is in the range [0, 500].
-100 <= Node.val <= 100
0 <= k <= 2 * 109

  */

// Solution - Point the tail of the linked list to head; Find the length of the linked list and then point to len-k node; then make head = node->next and node->next=NULL

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL)
            return head;
        int len=1;
        ListNode *cur=head;
        while(cur->next)
        {
            len++;
            cur=cur->next;
        }
        k%=len;
        cur->next=head;
        cur=head;
        while((len-k)>1)
        {
            cur=cur->next;
            len--;
        }
        head=cur->next;
        cur->next=NULL;
        return head;
    }
};

// Using two vector to keep the values and then keeping the rotated values and using this array to fill in the linked list

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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL)
            return head;
        int c=0;
        ListNode *cur=head;
        while(cur)
        {
            c++;
            cur=cur->next;
        }
        k%=c;
        cur=head;
        vector<int>arr(c), tmp(c);
        for(int i=0; i<c; i++)
        {
            arr[i]=cur->val;
            cur=cur->next;
        }
        for(int i=0; i<c; i++)
        {
            tmp[i]=arr[(c-k+i)%c];
        }
        cur=head;
        int i=0;
        while(cur)
        {
            cur->val=tmp[i];
            cur=cur->next;
            i++;
        }
        return head;
    }
};
