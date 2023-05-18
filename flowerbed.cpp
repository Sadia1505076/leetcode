// You have a long flowerbed in which some of the plots are planted, and some are not. However, flowers cannot be planted in adjacent plots.
// Given an integer array flowerbed containing 0's and 1's, where 0 means empty and 1 means not empty, and an integer n, return true if n new flowers can be planted in the flowerbed without violating the no-adjacent-flowers rule and false otherwise.

// Example 1:
// Input: flowerbed = [1,0,0,0,1], n = 1
// Output: true

// Example 2:
// Input: flowerbed = [1,0,0,0,1], n = 2
// Output: false


class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int size = flowerbed.size();
        set <int> forbiddenPlots;
        for (int i = 0; i < size; i++) {
            if (flowerbed[i] == 1) {
                forbiddenPlots.insert(i);
                if (i - 1 >= 0) forbiddenPlots.insert(i - 1);
                if (i + 1 < size) forbiddenPlots.insert(i + 1);
            }
        }
        for (int i = 0; i < size; i++) {
            auto it = forbiddenPlots.find(i);
            if (it == forbiddenPlots.end()) {
                flowerbed[i] = 1;
                n -= 1;
                if (i + 1 < size) forbiddenPlots.insert(i + 1);
            }
        }
        if (n <= 0) return true;
        return false;
    }
};