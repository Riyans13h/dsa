/*
Question:
Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. 
(i.e., from left to right, then right to left for the next level, and alternate between).

Example:
Input:
    3
   / \
  9  20
     / \
    15  7

Output:
[
  [3],
  [20, 9],
  [15, 7]
]

Constraints:
- The number of nodes in the tree is in the range [0, 2000].
- Node values are integers.
*/

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans; // Final result
        if (!root) return ans;   // If tree is empty, return empty list

        queue<TreeNode*> q;      // Queue for BFS traversal
        q.push(root);
        bool flag = false;       // false = left to right, true = right to left

        while (!q.empty()) {
            int n = q.size();    // Number of nodes at current level
            vector<int> temp;    // Stores nodes for this level
            
            // Process all nodes in the current level
            for (int i = 0; i < n; i++) {
                TreeNode* node = q.front();
                q.pop();
                temp.push_back(node->val); // Store current node's value

                // Push children into queue for the next level
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            // If we are on a "right to left" level, reverse the order
            if (flag) {
                reverse(temp.begin(), temp.end());
            }

            // Store this level's result
            ans.push_back(temp);

            // Toggle direction for next level
            flag = !flag;
        }
        return ans;
    }
};

/*
Time Complexity:
O(n) — Each node is visited exactly once.  
Reversals per level cost O(k), but total reversal cost across all levels is O(n).

Space Complexity:
O(n) — For the queue and result storage.
*/
