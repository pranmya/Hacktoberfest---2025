#include <vector>
#include <algorithm> // For std::swap

class Solution {
public:
    std::vector<std::vector<int>> permute(std::vector<int>& nums) {
        std::vector<std::vector<int>> result;
        generatePermutations(nums, 0, result);
        return result;
    }

private:
    void generatePermutations(
        std::vector<int>& nums,
        int start,
        std::vector<std::vector<int>>& result) {
        
        // Base case: If we've fixed all positions, we have a complete permutation.
        if (start == nums.size()) {
            result.push_back(nums);
            return;
        }

        // Recursive step: Iterate through the options for the current position 'start'.
        for (int i = start; i < nums.size(); ++i) {
            // Choose: Place the i-th element at the 'start' position.
            std::swap(nums[start], nums[i]);

            // Explore: Recursively find all permutations for the rest of the list.
            generatePermutations(nums, start + 1, result);

            // Un-choose (Backtrack): Swap back to restore the original order
            // for the next iteration of the loop.
            std::swap(nums[start], nums[i]);
        }
    }
};
