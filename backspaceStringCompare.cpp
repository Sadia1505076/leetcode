// Given two strings s and t, return true if they are equal when both are typed into empty text editors. '#' means a backspace character.
// Note that after backspacing an empty text, the text will continue empty.

 
// Example 1:
// Input: s = "ab#c", t = "ad#c"
// Output: true
// Explanation: Both s and t become "ac".

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<int> stackS;
        stack<int> stackT;
        for(int i = 0; i < s.length(); i++) {
            if (s[i] != '#') stackS.push(s[i]);
            else {
                if (!stackS.empty()) stackS.pop();
            }
        }
        for(int i = 0; i < t.length(); i++) {
            if (t[i] != '#') stackT.push(t[i]);
            else {
                if (!stackT.empty()) stackT.pop();
            }
        }

        while (!stackS.empty()) {
            if(stackT.empty() || stackS.top() != stackT.top()) return false;
            stackS.pop();
            stackT.pop();
        }
        if (!stackS.empty() || !stackT.empty()) return false;
        return true;
    }
};