/*
Given a string s, find the length of the longest 
substring without repeating characters.
Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
 
Constraints:

0 <= s.length <= 5 * 104
s consists of English letters, digits, symbols and spaces.

  */

// Solution . Best approach. T.C- O(N), Space O(N) for hashing

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int>mp(256,-1);
        int n=s.length();
        int left=0, right=0, len=0;
        while(right<n)
        {
            if(mp[s[right]]!=-1)
            {
                left = max(mp[s[right]]+1, left);
            }
            mp[s[right]]= right;
            len = max(right-left+1, len);
            right++;
        }
        return len;
    }
};
