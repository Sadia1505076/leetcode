// Given an array nums containing n distinct numbers in the range [0, n], return the missing number.
// Example:
// Input: [3, 0, 1]
// Output: [2]
// Input: [0, 1]
// Output: [2]
// Constraints: All numbers in the array will be unique.

#include<bits/stdc++.h>

using namespace std;

int missingNumber(vector<int>& nums) {
    set<int> foundNumbers;
    for (int i = 0; i < nums.size(); i++) {
        auto ifExist = foundNumbers.find(nums[i]);
        if (ifExist == foundNumbers.end()) {
            //not found
            foundNumbers.insert(nums[i]);
        }
    }

    for (int i = 0; i < nums.size() + 1; i++) {
        auto ifExist = foundNumbers.find(i);
        if (ifExist == foundNumbers.end()) {
            //not found
            return i;
        }
    }
    return -1;
}

int main() {
    vector<int> input;
    //input.push_back(3);
    input.push_back(0);
    input.push_back(1);
    cout<<"missing number: "<<missingNumber(input)<<endl;
    return 0;
}