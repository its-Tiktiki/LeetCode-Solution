class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        // Counting sort approach since 0 <= nums[i] <= 100
        int count[101] = {0};
        
        // Count occurrences of each value
        for (int num : nums) {
            count[num]++;
        }
        
        // Build prefix sum: count[i] becomes the number of elements < i
        for (int i = 1; i <= 100; i++) {
            count[i] += count[i - 1];
        }
        
        // For each num, the answer is count[num - 1] (0 if num == 0)
        vector<int> result;
        result.reserve(nums.size());
        for (int num : nums) {
            result.push_back(num == 0 ? 0 : count[num - 1]);
        }
        
        return result;
    }
};