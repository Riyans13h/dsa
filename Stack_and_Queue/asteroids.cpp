/*
🔹 Problem: 735. Asteroid Collision
-----------------------------------
We are given an array `asteroids` of integers representing asteroids in a row. 
Each integer represents an asteroid:
  - The **absolute value** is its **size**
  - The **sign** represents its **direction**:
      🔸 Positive → moving right
      🔸 Negative → moving left

All asteroids move at the same speed. If two asteroids meet:
  - The smaller one explodes
  - If both are same size, both explode
  - Two asteroids moving in the same direction will never collide

🔹 Objective:
Return the final state of the asteroids after all collisions.

🔹 Examples:

Input: asteroids = [5,10,-5]
Output: [5,10]
Explanation: 10 and -5 collide → 10 survives.

Input: asteroids = [8,-8]
Output: []
Explanation: 8 and -8 are equal → both explode.

Input: asteroids = [10,2,-5]
Output: [10]
Explanation: 2 and -5 collide → -5 survives, then -5 collides with 10 → 10 survives.

🔹 Constraints:
- 2 <= asteroids.length <= 10⁴
- -1000 <= asteroids[i] <= 1000
- asteroids[i] ≠ 0
*/

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        int n = asteroids.size();

        // Traverse each asteroid
        for (int i = 0; i < n; i++) {
            // Current asteroid is moving right → just push it
            if (asteroids[i] > 0) {
                st.push(asteroids[i]);
            }
            // Current asteroid is moving left
            else {
                // Resolve all smaller right-moving asteroids
                while (!st.empty() && st.top() > 0 && st.top() < abs(asteroids[i])) {
                    st.pop(); // right asteroid explodes
                }

                // If they are equal → both explode
                if (!st.empty() && st.top() == abs(asteroids[i])) {
                    st.pop(); // both destroyed
                }
                // If no right-moving asteroid is left or top is left-moving → current survives
                else if (st.empty() || st.top() < 0) {
                    st.push(asteroids[i]);
                }
                // Else, the current left asteroid is destroyed implicitly (do nothing)
            }
        }

        // Collect result from stack (LIFO → reverse needed)
        vector<int> ans;
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
