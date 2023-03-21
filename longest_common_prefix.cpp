// Write a function to find the longest common prefix string amongst an array of strings.
// If there is no common prefix, return an empty string "".

// Example 1:
// Input: strs = ["flower","flow","flight"]
// Output: "fl"

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string longestPrefix = "";
        for(int i = 0; i < strs[0].size(); i++) {
            char c = strs[0][i];
            int flag = 0;
            for (int j = 1; j < strs.size(); j++) {
                if (strs[j].size() < i || strs[j][i] != c) {
                    flag = 1;
                }
            }
            if (flag) break;
            longestPrefix += c;
        }
        return longestPrefix;
    }
};