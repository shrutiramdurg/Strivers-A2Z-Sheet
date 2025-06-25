class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;                     
        int maxArea = 0;

        for (int i = 0; i <= n; ++i) {
           
            int curHeight = (i == n ? 0 : heights[i]);

            while (!st.empty() && curHeight < heights[st.top()]) {
                int h = heights[st.top()];
                st.pop();
                int leftSmaller  = st.empty() ? -1 : st.top();
                int width = i - leftSmaller - 1;
                maxArea = max(maxArea, h * width);
            }
            st.push(i);
        }
        return maxArea;
    }
};