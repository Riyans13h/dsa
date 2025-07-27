/*
🔷 Problem: 503. Next Greater Element II
------------------------------------------
Given a circular integer array `nums`, return the next greater number for every element.
The next greater number is the first greater number *after it* in the circular traversal.
If it doesn't exist, return -1 for that element.

🔸 Examples:

Input: nums = [1,2,1]
Output: [2,-1,2]

Input: nums = [1,2,3,4,3]
Output: [2,3,4,-1,4]

🔹 Constraints:
- 1 <= nums.length <= 10⁴
- -10⁹ <= nums[i] <= 10⁹
*/


// ✅ Brute Force Approach (Time: O(n²), Space: O(1))
class BruteForceSolution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1);

        for (int i = 0; i < n; ++i) {
            // Check next n-1 elements in circular fashion
            for (int j = 1; j < n; ++j) {
                int idx = (i + j) % n;
                if (nums[idx] > nums[i]) {
                    ans[i] = nums[idx];
                    break;
                }
            }
        }
        return ans;
    }
};


// ✅ Optimal Approach 1: Monotonic Stack (value-based)
// Time: O(n), Space: O(n)
class StackValueSolution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1);
        stack<int> st;  // stores values

        // Traverse the array twice to simulate circular nature
        for (int i = 2 * n - 1; i >= 0; --i) {
            int val = nums[i % n];

            // Maintain a decreasing stack
            while (!st.empty() && st.top() <= val)
                st.pop();

            if (i < n) {
                ans[i] = st.empty() ? -1 : st.top();
            }

            st.push(val);
        }

        return ans;
    }
};


// ✅ Optimal Approach 2: Monotonic Stack (index-based)
// Time: O(n), Space: O(n)
class StackIndexSolution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1);
        stack<int> st; // stores indices

        for (int i = 0; i < 2 * n; ++i) {
            int idx = i % n;

            // While current value is greater than top-of-stack element
            while (!st.empty() && nums[st.top()] < nums[idx]) {
                ans[st.top()] = nums[idx];
                st.pop();
            }

            if (i < n) st.push(idx);  // Push only original indices (not duplicates)
        }

        return ans;
    }
};
