/*
🔹 Problem: 42. Trapping Rain Water
-------------------------------------
Given n non-negative integers representing an elevation map where the width of each bar is 1, 
compute how much water it can trap after raining.

🔸 Examples:

Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6

Input: height = [4,2,0,3,2,5]
Output: 9

🔹 Constraints:
- 1 <= height.length <= 2 × 10⁴
- 0 <= height[i] <= 10⁵
*/


/* ✅ Approach 1: Two Pointers + Constant Space
--------------------------------------------------
Move two pointers from both ends towards the center.
At every step, trap water based on the smaller of leftMax and rightMax.

Time: O(n)
Space: O(1)
*/
class Solution1 {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int l = 0, r = n - 1;
        int lmax = 0, rmax = 0;
        int ans = 0;

        while (l < r) {
            lmax = max(lmax, height[l]);
            rmax = max(rmax, height[r]);

            if (lmax < rmax) {
                ans += (lmax - height[l]);
                l++;
            } else {
                ans += (rmax - height[r]);
                r--;
            }
        }
        return ans;
    }
};


/* ✅ Approach 2: Prefix Max & Suffix Max Arrays
--------------------------------------------------
For each bar, water trapped = min(prefixMax[i], suffixMax[i]) - height[i]

Time: O(n)
Space: O(n)
*/
class Solution2 {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n <= 2) return 0;

        vector<int> prefixMax(n), suffixMax(n);

        // Step 1: Build prefix max array
        prefixMax[0] = height[0];
        for (int i = 1; i < n; i++) {
            prefixMax[i] = max(prefixMax[i - 1], height[i]);
        }

        // Step 2: Build suffix max array
        suffixMax[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            suffixMax[i] = max(suffixMax[i + 1], height[i]);
        }

        // Step 3: Calculate trapped water
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans += min(prefixMax[i], suffixMax[i]) - height[i];
        }

        return ans;
    }
};
