class Solution {
public:
    int singleNumber(vector<int>& nums) {

        unordered_map<int, int> f;

        for(int n : nums){
            f[n]++;
        }

        for(auto& n : f){
            if(n.second == 1){
                return n.first;
            }
        }

        return -1;
        
    }
};