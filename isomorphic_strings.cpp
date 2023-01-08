// Given two strings s and t, determine if they are isomorphic.
// Two strings s and t are isomorphic if the characters in s can be replaced to get t.
// All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.

// Example 1:
// Input: s = "egg", t = "add"
// Output: true

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char, char> s_replacements;
        map<char, char> replacement_uniqueness_checker;
        if (s.length() == t.length()) {
            for (int i = 0; i < s.length(); i++) {
                auto t_for_s = s_replacements.find(s[i]);
                if (t_for_s == s_replacements.end()) {
                    if (replacement_uniqueness_checker.find(t[i]) == replacement_uniqueness_checker.end()) {
                        s_replacements.insert({s[i], t[i]});
                        replacement_uniqueness_checker.insert({t[i], t[i]});
                        s[i] = t[i];
                    }
                    else return false;   
                }
                else {
                    s[i] = t_for_s -> second;
                }
            }
            if (s == t) return true;
            return false; 
        }
        return false;
    }
};