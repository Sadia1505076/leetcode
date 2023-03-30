// Given a string s consisting of words and spaces, return the length of the last word in the string.
// A word is a maximal 
// substring
//  consisting of non-space characters only.

// Example 1:
// Input: s = "Hello World"
// Output: 5
// Explanation: The last word is "World" with length 5.




class Solution {
public:
    int lengthOfLastWord(string s) {
        string word;
        int index = 0;
        string lowerS = "";
        for (int i = 0 ; i < s.length(); i++) {
            lowerS += tolower(s[i]);
        }
        while (index < lowerS.length()) {
            int spaceIndex = lowerS.find_first_not_of("abcdefghijklmnopqrstuvwxyz", index);
            if (spaceIndex != string::npos) {
                string substring = lowerS.substr(index, spaceIndex - index);
                if (substring != "") word = substring;
                index = spaceIndex + 1;
            }
            else break;
        }
        if (index < lowerS.length() && s.substr(index, lowerS.length() - index) != "") {
            return lowerS.length() - index;
        }
        else {
            return word.length();
        }
    }
};