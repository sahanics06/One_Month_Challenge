/*
Given a string s, partition s such that every 
substring
 of the partition is a 
palindrome
. Return all possible palindrome partitioning of s.


Example 1:

Input: s = "aab"
Output: [["a","a","b"],["aa","b"]]
Example 2:

Input: s = "a"
Output: [["a"]]
 

Constraints:

1 <= s.length <= 16
s contains only lowercase English letters.

  */

// Solution -> check if substring idx to i is palinfrome or not if yes then check for later index.

class Solution {
public:
    bool isPalindrome(string &s, int i, int j)
    {
        while(i<j)
        {
            if(s[i]!=s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    void solve(string &s, vector<vector<string>>&ans, vector<string> tmp, int idx)
    {
        if(idx>=s.length())
        {
            ans.push_back(tmp);
        }
        for(int i=idx; i<s.length(); i++)
        {
            if(isPalindrome(s, idx, i))
            {
                tmp.push_back(s.substr(idx, i-idx+1));
                solve(s, ans, tmp, i+1);
                tmp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>tmp;
        solve(s, ans, tmp, 0);
        return ans;
    }
};
