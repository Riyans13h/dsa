/*
🔹 Problem: 907. Sum of Subarray Minimums
------------------------------------------
Given an array of integers `arr`, find the sum of `min(b)` for all contiguous subarrays `b` of `arr`.

🔸 Since the result can be large, return the answer modulo 1e9 + 7.

🔹 Examples:

Input: arr = [3,1,2,4]
Output: 17
Explanation:
Subarrays → [3], [1], [2], [4], [3,1], [1,2], [2,4], [3,1,2], [1,2,4], [3,1,2,4]
Minimums →   3    1    2    4    1       1      2       1        1       1
Sum = 17

Input: arr = [11,81,94,43,3]
Output: 444

🔹 Constraints:
- 1 <= arr.length <= 3 × 10⁴
- 1 <= arr[i] <= 3 × 10⁴

🔹 Approach:
We calculate:
- `pse[i]`: Previous Smaller Element index for arr[i]
- `nse[i]`: Next Smaller Element index for arr[i]

Then, for each arr[i], the number of subarrays where it is the minimum = (i - pse[i]) * (nse[i] - i)

Each element contributes `arr[i] * left * right` to the final answer
*/

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        long long ans = 0;
        int mod = 1e9 + 7;

        vector<int> pse(n, -1);  // Previous Smaller Element index
        vector<int> nse(n, n);   // Next Smaller Element index
        stack<int> st;

        // 🔸 Finding NSE (Next Smaller Element)
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            nse[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        // Clear the stack to reuse
        while (!st.empty()) st.pop();

        // 🔸 Finding PSE (Previous Smaller Element)
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            pse[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        // 🔸 Calculate total contribution
        for (int i = 0; i < n; i++) {
            long long left = i - pse[i];
            long long right = nse[i] - i;
            long long contrib = (left * right) % mod;
            contrib = (contrib * arr[i]) % mod;
            ans = (ans + contrib) % mod;
        }

        return (int)ans;
    }
};
