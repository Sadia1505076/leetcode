// Given an array of integers nums, calculate the pivot index of this array.
// The pivot index is the index where the sum of all the numbers strictly to the left of the index is equal to the sum of all the numbers strictly to the index's right.
// If the index is on the left edge of the array, then the left sum is 0 because there are no elements to the left. This also applies to the right edge of the array.
// Return the leftmost pivot index. If no such index exists, return -1.

// Example 1:
// Input: nums = [1,7,3,6,5,6]
// Output: 3
// Explanation:
// The pivot index is 3.
// Left sum = nums[0] + nums[1] + nums[2] = 1 + 7 + 3 = 11
// Right sum = nums[4] + nums[5] = 5 + 6 = 11


class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            int left_sum = 0, right_sum = 0;
            if (i != 0) {
                for (int j = 0; j < i; j++) {
                    left_sum += nums[j];
                }
            }
            if (i != nums.size() - 1) {
                for (int j = nums.size() - 1; j > i; j--) {
                    right_sum += nums[j];
                }
            }
            if (left_sum == right_sum) return i;
        }
        return -1;
    }
};