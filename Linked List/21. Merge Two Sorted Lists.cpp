/*
You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.

Example 1:

Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]
Example 2:

Input: list1 = [], list2 = []
Output: []
Example 3:

Input: list1 = [], list2 = [0]
Output: [0]
 
Constraints:

The number of nodes in both lists is in the range [0, 50].
-100 <= Node.val <= 100
Both list1 and list2 are sorted in non-decreasing order.

  */

// Solution using merge sort concept.
// we keep l1 and smaller and l2 as the list with greater value.
// we iterate while(l1 && l1->val<=l2->val) we keep l1 in tmp for every iteration and once it gets out of while we make tmp->next=l2(because now l2->val<l1->val)
// Then swap(l1,l2) to again keep l1 as small.

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1==NULL)
            return l2;
        if(l2==NULL)
            return l1;
        if(l1->val>l2->val)
            swap(l1,l2);
        
        ListNode *res=l1;
        while(l1 && l2)
        {
            ListNode* tmp=NULL;
            while(l1 && l1->val<=l2->val)
            {
                tmp=l1;
                l1=l1->next;
            }
            tmp->next=l2;
            swap(l1,l2);
        }
        return res;
    }
};

// Solution using normal checking 

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==NULL)
            return list2;
        if(list2==NULL)
            return list1;
        ListNode *head = new ListNode(0);
        ListNode *cur=head;
        // cur->next = (list1->val<=list2->val)?list1:list2;
        // cur=cur->next;
        while(list1 && list2)
        {
            if(list1->val<=list2->val)
            {
                cur->next=list1;
                list1=list1->next;
            }
            else
            {
                cur->next=list2;
                list2=list2->next;
            }
            cur=cur->next;
        }
        if(list1)
            cur->next=list1;
        if(list2)
            cur->next=list2;
        return head->next;
    }
};
