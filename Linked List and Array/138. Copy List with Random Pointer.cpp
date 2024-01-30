/*
A linked list of length n is given such that each node contains an additional random pointer, which could point to any node 
in the list, or null.

Construct a deep copy of the list. The deep copy should consist of exactly n brand new nodes, where each new node has its 
value set to the value of its corresponding original node. Both the next and random pointer of the new nodes should point 
to new nodes in the copied list such that the pointers in the original list and copied list represent the same list state. 
None of the pointers in the new list should point to nodes in the original list.

For example, if there are two nodes X and Y in the original list, where X.random --> Y, then for the corresponding two 
nodes x and y in the copied list, x.random --> y.

Return the head of the copied linked list.

The linked list is represented in the input/output as a list of n nodes. Each node is represented as a pair of [val, 
random_index] where:

val: an integer representing Node.val
random_index: the index of the node (range from 0 to n-1) that the random pointer points to, or null if it does not 
point to any node.
Your code will only be given the head of the original linked list.

Example 1:

Input: head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
Output: [[7,null],[13,0],[11,4],[10,2],[1,0]]
Example 2:

Input: head = [[1,1],[2,1]]
Output: [[1,1],[2,1]]
Example 3:

Input: head = [[3,null],[3,0],[3,null]]
Output: [[3,null],[3,0],[3,null]]

Constraints:

0 <= n <= 1000
-104 <= Node.val <= 104
Node.random is null or is pointing to some node in the linked list.

*/

// Solution- inserting new node between nodes and in next loop update the random pointer and then remove 
// the inserted nodes and link with new dummy node

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node *cur=head;
        while(cur)
        {
            Node *tmp = new Node(cur->val);
            tmp->next=cur->next;
            cur->next=tmp;
            cur=tmp->next;
        }
        cur=head;
        while(cur)
        {
            Node *tmp = cur->next;
            if(cur->random)
            {
                tmp->random=cur->random->next;
            }
            cur=cur->next->next;
        }
        Node *ans=new Node(0);
        Node *tmp=ans;
        cur=head;
        while(cur)
        {
            tmp->next=cur->next;
            tmp=cur->next;
            cur->next=cur->next->next;
            cur=cur->next;
        }
        return ans->next;
    }
};

// Solution using unordered_map<Node*, Node*>mp
// while(cur) create new node and store in map, then in next loop link the next and random.

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*>mp;
        Node *cur=head;
        while(cur)        
        {
            Node *tmp=new Node(cur->val);
            mp[cur]=tmp;
            cur=cur->next;
        }
        cur=head;
        while(cur)
        {
            Node *tmp=mp[cur];
            tmp->next=mp[cur->next];
            tmp->random=mp[cur->random];
            cur=cur->next;
        }
        return mp[head];
    }
};
