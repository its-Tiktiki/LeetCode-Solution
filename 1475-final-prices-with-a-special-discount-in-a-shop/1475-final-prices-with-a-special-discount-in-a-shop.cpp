class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        vector<int> result = prices;  // start with original prices
        stack<int> st;  // stack of indices, prices at these indices are increasing
        
        for (int i = 0; i < n; i++) {
            // Current price can provide a discount to any pending index
            // whose price is >= current price
            while (!st.empty() && prices[st.top()] >= prices[i]) {
                int idx = st.top();
                st.pop();
                result[idx] = prices[idx] - prices[i];
            }
            st.push(i);
        }
        
        return result;
    }
};