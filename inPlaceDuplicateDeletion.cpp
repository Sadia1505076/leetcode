// You are given a sorted array of integers in non-decreasing order. You have to remove the duplicates in-place such that each unique element appears only once. The relative order of the elements should be kept the same.
// In-place operation indicates you cannot use any extra space, memory or array to perform the task.
// [NOTE: YOU CAN NOT PERFORM ANY REMOVE OPERATION ON THE ARRAY. YOU CANNOT USE ANY EXTRA MEMORY]
// After you do some operation on the array, the duplicates can only remain at the rightmost end of
// the array.
// Example:-
// Input:    [1, 1, 2, 3, 3, 3, 4, 4, 5, 6]
// Output: [1, 2, 3, 4, 5, 6, 4, 4, 5, 6]
// Input: [1, 1, 2]
// Output: [1, 2, 2]
// Input: [1, 2, 2]
// Output: [1, 2, 2]
// Input: [1, 2, 2, 3]
// Output: [1, 2, 3, 3]


#include<bits/stdc++.h>

using namespace std;

vector<int> removingDuplicate(vector<int>& nums) {
    for(int i = 0; i < nums.size(); i++) {
        if (i != nums.size() - 1 && (nums[i + 1] == nums[i] || nums[i + 1] < nums[i])) {
            for(int j = i + 2; j < nums.size(); j++) {
                if (nums[j] != nums[i] && nums[j] > nums[i]) {
                    nums[i + 1] = nums[j];
                    break;
                }
            }
        }
    }
    return nums;
}

int main() {
    vector<int> input;
    input.push_back(1);
    input.push_back(1);
    input.push_back(2);
    input.push_back(3);
    input.push_back(3);
    input.push_back(3);
    input.push_back(4);
    input.push_back(4);
    input.push_back(5);
    input.push_back(6);
    vector<int> result = removingDuplicate(input);
    for(int i = 0; i < result.size(); i++) {
        cout<<"array element is: "<<result[i]<<endl;
    }
    return 0;
}