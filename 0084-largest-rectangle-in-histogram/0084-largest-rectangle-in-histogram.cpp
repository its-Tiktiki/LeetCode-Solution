class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;  // stack of indices, heights increasing from bottom to top
        int maxArea = 0;
        
        for (int i = 0; i <= n; i++) {
            // Use height 0 as a sentinel when i == n to flush remaining bars
            int currHeight = (i == n) ? 0 : heights[i];
            
            while (!st.empty() && heights[st.top()] >= currHeight) {
                int height = heights[st.top()];
                st.pop();
                // Width extends from the element after the new stack top
                // to the current index (exclusive)
                int width = st.empty() ? i : i - st.top() - 1;
                maxArea = max(maxArea, height * width);
            }
            st.push(i);
        }
        
        return maxArea;
    }
};