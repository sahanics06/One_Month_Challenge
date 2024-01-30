/*
Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should 
remain as it is.

You may not alter the values in the list's nodes, only nodes themselves may be changed.

Example 1:

Input: head = [1,2,3,4,5], k = 2
Output: [2,1,4,3,5]
Example 2:

Input: head = [1,2,3,4,5], k = 3
Output: [3,2,1,4,5]

Constraints:

The number of nodes in the list is n.
1 <= k <= n <= 5000
0 <= Node.val <= 1000

  */

// Optimsed using loop and using dummy node and prev to track the correct link

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dum = new ListNode (0);
        dum->next=head;
        int c=0;
        ListNode *current=head;
        while(current)
        {
            c++;
            current=current->next;
        }
        ListNode *prev=dum, *cur=dum, *tmp=dum;
        while(c>=k)
        {
            cur=prev->next;
            tmp=cur->next;
            for(int i=1; i<k; i++) // we have to change k-1 link
            {
                cur->next=tmp->next;
                tmp->next=prev->next;
                prev->next=tmp;
                tmp=cur->next;
            }
            prev=cur;
            c-=k;
        }
        return dum->next;
    }
};

// Solution using reverse function

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
    ListNode* reverse(ListNode* head)
    {
        ListNode *cur=head, *prev=NULL;
        while(cur)
        {
            ListNode* tmp=cur->next;
            cur->next=prev;
            prev=cur;
            cur=tmp;
        }
        return prev;
    }
    ListNode* findkthNode(ListNode* head, int k)
    {
        k--;
        while(head && k>0)
        {
            head=head->next;
            k--;
        }
        return head;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL || head->next==NULL)
            return head;
        ListNode *tmp=head, *nextNode, *prev=NULL;
        while(tmp)
        {
            ListNode* kthNode = findkthNode(tmp, k);
            if(kthNode==NULL)
            {
                if(prev)
                    prev->next=tmp;
                break;
            }
            ListNode *nextNode = kthNode->next;
            kthNode->next=NULL;
            reverse(tmp);
            if(tmp==head)
            {
                head=kthNode;
            }
            else
            {
                prev->next=kthNode;
            }
            prev=tmp;
            tmp=nextNode;
        }
        return head;
    }
};
