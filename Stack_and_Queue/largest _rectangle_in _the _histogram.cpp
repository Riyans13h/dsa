/*
🔹 Problem: Largest Rectangle in Histogram
------------------------------------------
Given an array of integers `heights` representing the histogram's bar height where the width of each bar is 1, 
return the area of the largest rectangle in the histogram.

🔹 Example:
Input:  heights = [2,1,5,6,2,3]
Output: 10

Explanation:
The largest rectangle is formed between index 2 and 3 (heights 5 and 6), covering 2 units width:
Area = 5 * 2 = 10
*/

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();   
        stack<int> st;

        // Edge case: if only one bar exists, return its height
        if (n == 1) return heights[0];

        // Next Smaller Element to the right
        vector<int> nse(n, n);  // Default: n (no smaller element on right)
        // Previous Smaller Element to the left
        vector<int> pse(n, -1); // Default: -1 (no smaller element on left)

        // ---- Step 1: Compute NSE (Next Smaller Element) ----
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            nse[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        // Clear stack before computing PSE
        while (!st.empty()) st.pop();

        // ---- Step 2: Compute PSE (Previous Smaller Element) ----
        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            pse[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        int ans = 0;

        // ---- Step 3: Calculate maximum area ----
        for (int i = 0; i < n; i++) {
            int width = nse[i] - pse[i] - 1;
            int area = heights[i] * width;
            ans = max(ans, area);
        }

        return ans;
    }
};
