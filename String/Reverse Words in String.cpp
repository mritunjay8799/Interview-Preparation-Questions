Given an input string s, reverse the order of the words.

A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.

Return a string of the words in reverse order concatenated by a single space.
 
Example 1:
Input: s = "the sky is blue"
Output: "blue is sky the"

Example 2:
Input: s = "  hello world  "
Output: "world hello"

Example 3:
Input: s = "  Bob    Loves  Alice   "
Output: "Alice Loves Bob"

Follow up:
Could you solve it in-place with O(1) extra space?

================================================================================================================================================================================

##### EXTRA SPACE USED-
-----------------------

class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        stack<string>st;
        string word,ans = "";
        while(ss>>word)
            st.push(word);
        while(st.size()!=0)
        {
            ans+=st.top();
            st.pop();
            if(st.size()!=0)
                ans+=" ";
        }
        return ans;
    }
};


WITHOUT EXTRA SPACE-
-------------------

