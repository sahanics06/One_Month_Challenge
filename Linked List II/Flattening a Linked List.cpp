/*
Given a Linked List of size N, where every node represents a sub-linked-list and contains two pointers:
(i) a next pointer to the next node,
(ii) a bottom pointer to a linked list where this node is head.
Each of the sub-linked-list is in sorted order.
Flatten the Link List such that all the nodes appear in a single level while maintaining the sorted order. 

Note: The flattened list will be printed using the bottom pointer instead of the next pointer.
For more clarity have a look at the printList() function in the driver code.

Example 1:

Input:
5 -> 10 -> 19 -> 28
|     |     |     | 
7     20    22   35
|           |     | 
8          50    40
|                 | 
30               45
Output:  5-> 7-> 8- > 10 -> 19-> 20->
22-> 28-> 30-> 35-> 40-> 45-> 50.
Explanation:
The resultant linked lists has every 
node in a single level.
(Note: | represents the bottom pointer.)
 
Example 2:

Input:
5 -> 10 -> 19 -> 28
|          |                
7          22   
|          |                 
8          50 
|                           
30              
Output: 5->7->8->10->19->22->28->30->50
Explanation:
The resultant linked lists has every
node in a single level.

(Note: | represents the bottom pointer.)

Your Task:
You do not need to read input or print anything. Complete the function flatten() that takes the head of the linked list as input parameter and returns 
the head of flattened link list.

Expected Time Complexity: O(N*N*M)
Expected Auxiliary Space: O(N)

Constraints:
0 <= N <= 50
1 <= Mi <= 20
1 <= Element of linked list <= 103

*/

// Solution using merge two list. call solve(root->next) and merge.

Node *merge(Node *l1, Node *l2)
{
    if(l2==NULL)
        return l1;
    if(l1==NULL)
        return l2;
    Node *tmp = new Node(0);
    Node *cur=tmp;
    while(l1 && l2)
    {
        if(l1->data<=l2->data)
        {
            cur->bottom=l1;
            cur=l1;
            l1=l1->bottom;
        }
        else
        {
            cur->bottom=l2;
            cur=l2;
            l2=l2->bottom;
        }
        cur->next=NULL;
    }
    if(l1)
        cur->bottom=l1;
    if(l2)
        cur->bottom=l2;
    if(tmp->bottom)
        tmp->next=NULL;
    return tmp->bottom;
}
Node *solve(Node *root)
{
    if(root==NULL|| root->next==NULL)
        return root;
    Node *tmp = solve(root->next);
    Node *ans = merge(root, tmp);
    return ans;
}
Node *flatten(Node *root)
{
   // Your code here
   return solve(root);
}



// Solution using keeping the elements in array and then sorting it. Keep adding the elements in the list by creating new node.


/* Node structure  used in the program

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};
*/

/*  Function which returns the  root of 
    the flattened linked list. */
Node *flatten(Node *root)
{
   // Your code here
   vector<int>arr;
   while(root)
   {
       Node *tmp=root;
       while(tmp)
       {
           arr.push_back(tmp->data);
           tmp=tmp->bottom;
       }
       root=root->next;
   }
   //cout<<arr.size()<<endl;
   if(arr.size()==0)
    return NULL;
   
   Node *ans = new Node(0);
   Node *cur=ans;
   sort(arr.begin(), arr.end());
   for(int i=0; i<arr.size(); i++)
   {
       Node *tmp = new Node(arr[i]);
       cur->bottom=tmp;
       cur=tmp;
   }
   return ans->bottom;
}
