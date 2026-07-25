class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> result;
        int current = 1;  // next number from the stream
        
        for (int num : target) {
            // Push and pop for every number we skip (not in target)
            while (current < num) {
                result.push_back("Push");
                result.push_back("Pop");
                current++;
            }
            // Push the number that belongs in target
            result.push_back("Push");
            current++;
        }
        
        return result;
    }
};