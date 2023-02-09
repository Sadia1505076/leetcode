// Write a program that takes in a string as input and determines whether it is a palindrome (i.e. a word or phrase that reads the same forwards and backwards).
// Challenge: Can you solve it without reversing the string?
// Example:
// Input: “abbc”
// Output: false
// Input: “abba”
// Output: true
// Input: “a”
// Output: true
// Input: “”
// Output: true



#include<bits/stdc++.h>

using namespace std;

bool palindrome(string s) {
    stack<char> singleChars;
    for(int i = 0; i < s.length(); i++) {
        singleChars.push(s[i]);
    }
    int i = 0;
    while (!singleChars.empty()) {
        char top = singleChars.top();
        if (s[i] != top) return false;
        singleChars.pop();
        i++;
    }
    return true;
}

int main() {
    string input = "";
    cout<<"is palindrome: "<<palindrome(input)<<endl;
    return 0;
}