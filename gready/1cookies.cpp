// Problem:
// You are given two integer arrays:
//   - g[]: representing the greed factor of each child
//   - s[]: representing the size of each cookie
// A child will be content if they are given a cookie with a size greater than or equal to their greed factor.
// Each child can receive at most one cookie, and each cookie can be given to at most one child.
// Your task is to find the **maximum number of content children** you can satisfy.

// Example:
// Input: g = [1, 2], s = [1, 2, 3]
// Output: 2
// Explanation: You can satisfy two children by giving cookies of size 1 and 2 to children with greed 1 and 2 respectively.

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());  // Sort greed factors
        sort(s.begin(), s.end());  // Sort cookie sizes

        int n = s.size();
        int m = g.size();
        int l = 0;  // Pointer for cookies
        int r = 0;  // Pointer for children

        // Try to assign smallest sufficient cookie to each child
        while (l < n) {
            if (r < m && g[r] <= s[l]) {
                r++;  // Move to next child if cookie satisfies current child's greed
            }
            l++;  // Move to next cookie
        }

        return r;  // Number of content children
    }
};
