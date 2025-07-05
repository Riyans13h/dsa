/*
---------------------------------------------------------------------------------------
📝 Problem Statement:

Given an array of integers `arr`, find the sum of `min(b)` for every contiguous subarray `b` of `arr`.
Since the answer may be large, return the answer modulo 10^9 + 7.

📘 Example 1:
Input: arr = [3,1,2,4]
Output: 17
Explanation:
Subarrays are [3], [1], [2], [4], [3,1], [1,2], [2,4], [3,1,2], [1,2,4], [3,1,2,4].
Minimums are 3, 1, 2, 4, 1, 1, 2, 1, 1, 1.
Sum = 17

📘 Example 2:
Input: arr = [11,81,94,43,3]
Output: 444

🔒 Constraints:
- 1 <= arr.length <= 30,000
- 1 <= arr[i] <= 30,000
---------------------------------------------------------------------------------------
*/

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        int mod = 1e9 + 7;
        long long ans = 0;

        // nextLess[i]: index of the next element less than arr[i]
        // prevLess[i]: index of the previous element less than arr[i]
        vector<int> nextLess(n, n);   // Initialized to n for elements with no smaller value to the right
        vector<int> prevLess(n, -1);  // Initialized to -1 for elements with no smaller value to the left
        stack<int> st;

        // Step 1: Compute Next Less Element for each index
        for (int i = n - 1; i >= 0; --i) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            if (!st.empty()) nextLess[i] = st.top();
            st.push(i);
        }

        // Clear the stack before reuse
        while (!st.empty()) st.pop();

        // Step 2: Compute Previous Less Element for each index
        for (int i = 0; i < n; ++i) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            if (!st.empty()) prevLess[i] = st.top();
            st.push(i);
        }

        // Step 3: Compute the contribution of each element to the answer
        for (int i = 0; i < n; ++i) {
            long long left = i - prevLess[i];         // Number of subarrays where arr[i] is the minimum and ends at i
            long long right = nextLess[i] - i;         // Number of subarrays where arr[i] is the minimum and starts at i
            long long contribution = (1LL * left * right % mod) * arr[i] % mod;
            ans = (ans + contribution) % mod;
        }

        return static_cast<int>(ans);
    }
};
