class Solution {
    public:
        vector<int> twoSum(vector<int> nums, int target) {
            map<int, int> hashed_numbers;
            vector<int> result;
            for(int i = 0; i < nums.size(); i++) {
                auto num = hashed_numbers.find(target-nums[i]);
                if (num != hashed_numbers.end()) {
                    result.push_back(i);
                    result.push_back(num -> second);
                    return result;
                }
                else {
                    hashed_numbers.insert({nums[i], i});
                }
            }
            return result;
        }
};