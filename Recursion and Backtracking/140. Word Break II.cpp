/*
Given a string s and a dictionary of strings wordDict, add spaces in s to construct a sentence where each word is a 
valid dictionary word. Return all such possible sentences in any order.

Note that the same word in the dictionary may be reused multiple times in the segmentation.

Example 1:

Input: s = "catsanddog", wordDict = ["cat","cats","and","sand","dog"]
Output: ["cats and dog","cat sand dog"]
Example 2:

Input: s = "pineapplepenapple", wordDict = ["apple","pen","applepen","pine","pineapple"]
Output: ["pine apple pen apple","pineapple pen apple","pine applepen apple"]
Explanation: Note that you are allowed to reuse a dictionary word.
Example 3:

Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
Output: []
 
Constraints:

1 <= s.length <= 20
1 <= wordDict.length <= 1000
1 <= wordDict[i].length <= 10
s and wordDict[i] consist of only lowercase English letters.
All the strings of wordDict are unique.
Input is generated in a way that the length of the answer doesn't exceed 105.

  */

// Solution 

class Solution {
public:
    void solve(string s, int i, string tmp, vector<string>& dict, vector<string>&ans)
    {
        if(i>=s.length())
        {
            tmp.pop_back();
            ans.push_back(tmp);
            return;
        }
        string t="";
        for(int k=i; k<s.length(); k++)
        {
            t+=s[k];
            for(int j=0; j<dict.size(); j++)
            {
                if(t==dict[j])
                {
                    t+=' ';
                    solve(s, k+1, tmp+t, dict, ans);
                    t.pop_back(); // pop the addec blank space
                }
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string>ans;
        string tmp="";
        solve(s, 0, tmp, wordDict, ans);
        return ans;
    }
};
