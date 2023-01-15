// Given a string s which consists of lowercase or uppercase letters, return the length of the longest palindrome that can be built with those letters.
// Letters are case sensitive, for example, "Aa" is not considered a palindrome here.

// Example 1:
// Input: s = "abccccdd"
// Output: 7
// Explanation: One longest palindrome that can be built is "dccaccd", whose length is 7.

class Solution {
public:
    int longestPalindrome(string s) {
        int oneSingleChar = 0;
        int totalLength = 0;
        map<char, int> charCount;
        for (int i = 0; i < s.length(); i++) {
            auto keyValue = charCount.find(s[i]);
            if (keyValue == charCount.end()) charCount.insert({s[i], 1});
            else keyValue -> second += 1;
        }
        for (auto const& [key, val] : charCount)
        {
           if (val == 1 && oneSingleChar == 0) oneSingleChar = 1;
           else if(val != 1) {
               if (val % 2 == 0) totalLength += val;
               else if(oneSingleChar == 0) {
                   totalLength += val -1;
                   oneSingleChar = 1;
               }
               else totalLength += val - 1;
           }
        }
        return totalLength + oneSingleChar;
    }
};