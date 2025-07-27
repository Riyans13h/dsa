/*
🔹 Problem: 402. Remove K Digits
----------------------------------
Given a non-negative integer `num` represented as a string and an integer `k`, 
remove exactly `k` digits from the number so that the new number is the smallest possible.

🔹 Example 1:
Input: num = "1432219", k = 3
Output: "1219"
Explanation: Remove digits 4, 3, and 2 to get 1219.

🔹 Example 2:
Input: num = "10200", k = 1
Output: "200"
Explanation: Remove leading 1 → "0200" → final result is "200" (no leading zeros).

🔹 Example 3:
Input: num = "10", k = 2
Output: "0"
Explanation: Remove all digits → return "0".

🔹 Constraints:
- 1 <= num.length <= 10⁵
- num consists of only digits.
- 0 <= k <= num.length
*/

class Solution {
public:
    string removeKdigits(string num, int k) {
        // If we remove all digits, return "0"
        if (k == num.size()) return "0";

        stack<char> st;
        string ans = "";

        // Monotonic stack: build the smallest possible number
        for (int i = 0; i < num.size(); i++) {
            // Remove larger digits from stack if current digit is smaller and k > 0
            while (!st.empty() && st.top() > num[i] && k > 0) {
                st.pop();
                k--;
            }
            st.push(num[i]);
        }

        // If still digits need to be removed, pop from top
        while (k > 0) {
            st.pop();
            k--;
        }

        // Pop stack into string
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }

        // Reverse the string (since stack was LIFO)
        reverse(ans.begin(), ans.end());

        // Remove leading zeros
        while (ans.size() > 0 && ans[0] == '0') {
            ans.erase(ans.begin());
        }

        // If string is empty after removing leading zeros, return "0"
        if (ans.size() == 0) return "0";
        return ans;
    }
};
