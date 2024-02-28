/*
Given an integer array nums, return the maximum result of nums[i] XOR nums[j], where 0 <= i <= j < n.

Example 1:

Input: nums = [3,10,5,25,2,8]
Output: 28
Explanation: The maximum result is 5 XOR 25 = 28.
Example 2:

Input: nums = [14,70,53,83,49,91,36,80,92,51,66,70]
Output: 127

Constraints:

1 <= nums.length <= 2 * 105
0 <= nums[i] <= 231 - 1
  */

// Solution

struct Node
{
    Node *links[2];
    bool containsKey(int bit)
    {
        return (links[bit]!=NULL);
    }
    Node *get(int bit)
    {
        return links[bit];
    }
    void put(int bit, Node *node)
    {
        links[bit] = node;
    }
};

class Trie
{
    private: Node *root;
    public:
    Trie()
    {
        root = new Node();
    }

    void insert(int num)
    {
        Node *node = root;
        for(int i=31; i>=0; i--)
        {
            int bit = (num>>i) & 1;
            if(!node->containsKey(bit))
            {
                node->put(bit, new Node());
            }
            node = node->get(bit);
        }
    }

    int getMax(int num)
    {
        Node *node = root;
        int maxNum=0;
        for(int i=31; i>=0; i--)
        {
            int bit = (num>>i) & 1;  // finding the bit
            if(node->containsKey(1-bit))  // For max Xor we need to XOR with opposite bits
            {
                maxNum = maxNum | (1<<i);
                node = node->get(1-bit);
            }
            else
            {
                node = node->get(bit);
            }
        }
        return maxNum;
    }
};


class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie trie;
        int ans=0;
        for(int i=0; i<nums.size(); i++)
        {
            trie.insert(nums[i]);
        }
        for(int i=0; i<nums.size(); i++)
        {
            ans = max(ans, trie.getMax(nums[i]));
        }
        return ans;
    }
};
