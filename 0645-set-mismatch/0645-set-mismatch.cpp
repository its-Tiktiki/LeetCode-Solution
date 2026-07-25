class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        int duplicate = -1, missing = -1;
        
        // Mark visited numbers by negating the value at their corresponding index
        for (int i = 0; i < n; i++) {
            int idx = abs(nums[i]) - 1;
            if (nums[idx] < 0) {
                duplicate = abs(nums[i]);
            } else {
                nums[idx] = -nums[idx];
            }
        }
        
        // The index whose value is still positive corresponds to the missing number
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) {
                missing = i + 1;
                break;
            }
        }
        
        return {duplicate, missing};
    }
};