/*
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.
 
Example 1:

Input: s = "()"
Output: true
Example 2:

Input: s = "()[]{}"
Output: true
Example 3:

Input: s = "(]"
Output: false

Constraints:

1 <= s.length <= 104
s consists of parentheses only '()[]{}'.

  */

// Solution using stack; if(s[i]=='(', '{', '[') then push in stack else check if(st.empty()) return false or check similar closed brackets if matches then pop.

class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        int i=0, n=s.length();
        while(i<n)
        {
            if(s[i]=='(' || s[i]=='[' || s[i]=='{')
            {
                st.push(s[i]);
            }
            else
            {
                if(st.empty())
                    return false;
                if(s[i]==')' && st.top()=='(')
                {
                    st.pop();
                }
                else if(s[i]==']' && st.top()=='[')
                {
                    st.pop();
                }
                else if(s[i]=='}' && st.top()=='{')
                {
                    st.pop();
                }
                else
                {
                    return false;
                }
            }
            i++;
        }
        return st.empty();
    }
};
