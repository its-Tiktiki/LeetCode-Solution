class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> result(n, 0);
        stack<int> st;  // stack of indices, temperatures decreasing from bottom to top
        
        for (int i = 0; i < n; i++) {
            // Current temp can resolve the wait for any pending index
            // whose temperature is lower
            while (!st.empty() && temperatures[st.top()] < temperatures[i]) {
                int idx = st.top();
                st.pop();
                result[idx] = i - idx;
            }
            st.push(i);
        }
        
        return result;
    }
};