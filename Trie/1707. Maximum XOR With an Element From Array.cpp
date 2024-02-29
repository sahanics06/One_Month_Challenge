/*
You are given an array nums consisting of non-negative integers. You are also given a queries array, where queries[i] = [xi, 
mi].

The answer to the ith query is the maximum bitwise XOR value of xi and any element of nums that does not exceed mi. 
In other words, the answer is max(nums[j] XOR xi) for all j such that nums[j] <= mi. If all elements in nums are larger 
than mi, then the answer is -1.

Return an integer array answer where answer.length == queries.length and answer[i] is the answer to the ith query.

Example 1:

Input: nums = [0,1,2,3,4], queries = [[3,1],[1,3],[5,6]]
Output: [3,3,7]
Explanation:
1) 0 and 1 are the only two integers not greater than 1. 0 XOR 3 = 3 and 1 XOR 3 = 2. The larger of the two is 3.
2) 1 XOR 2 = 3.
3) 5 XOR 2 = 7.
Example 2:

Input: nums = [5,2,4,6,6,3], queries = [[12,4],[8,1],[6,3]]
Output: [15,-1,5]
 

Constraints:

1 <= nums.length, queries.length <= 105
queries[i].length == 2
0 <= nums[j], xi, mi <= 109
  */


// Solution
/*
  This problem is same as finding the maximum XOR we have done with slight difference, 
  Here we have to find maximum of XOR of query with any number in num having value less than m. 
For this we break this problem such that if the trie contains only elements which are less than m then the question 
boils down to the one where we can solve by inserting those needed value in trie and then finding 
the maximum XOR with query. So for this we create a vector of pairs where we put values as {m, {query, index}}. 
  We need the index because we are sorting the vector in  increasing order so to put the ans in order wise of index 
we need index.
  */

struct Node
{
    Node *links[2];

    Node *get(int bit)
    {
        return links[bit];
    }

    void put(int bit, Node *node)
    {
        links[bit] = node;
    }

    bool containsKey(int bit)
    {
        return (links[bit]!=NULL);
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
        int ans = 0;
        for(int i=31; i>=0; i--)
        {
            int bit = (num>>i) & 1;
            if(node->containsKey(1-bit))
            {
                ans = ans | (1<<i);
                node = node->get(1-bit);
            }
            else
            {
                node = node->get(bit);
            }
        }
        return ans;
    }
};



class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        vector<pair<int, pair<int,int>>>tmp;
        for(int i=0; i<queries.size(); i++)
        {
            tmp.push_back({queries[i][1], {queries[i][0], i}});
        }
        sort(tmp.begin(), tmp.end());
        sort(nums.begin(), nums.end());
        vector<int>ans(queries.size(), -1);

        Trie trie;
        int j=0;

// T.C-> Nums + Queries for iterating through nums and queries
// T.C-> Total-> 32*Queries( for finding the maximum XOR i.e getMax) + 32*nums(for inserting in Trie)
        for(int i=0; i<tmp.size(); i++)
        {
            int m = tmp[i].first;
            int query = tmp[i].second.first;
            int index = tmp[i].second.second;

            while(j<nums.size() && nums[j]<=m)
            {
                trie.insert(nums[j]);
                j++;
            }
            if(j==0)
            {
                ans[index]=-1;
            }
            else
            {                
                ans[index] = trie.getMax(query);
            }
        }
        return ans;
    }
};


// Solution Brute Force

class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int>ans;
        for(int i=0; i<queries.size(); i++)
        {
            int mx = -1;
            int t = queries[i][0];
            int m = queries[i][1];
            for(int i=0; i<nums.size(); i++)
            {
                if(nums[i]<=m)
                {
                    int tmp = nums[i]^t;
                    mx = max(mx, tmp);
                }
            }
            ans.push_back(mx);
        }
        return ans;
    }
};
