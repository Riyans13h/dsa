/**
 * Problem: Binary Tree Level Order Traversal
 * 
 * Given the root of a binary tree, return the level order traversal of its nodes' values.
 * (i.e., from left to right, level by level).
 *
 * Example:
 * Input: root = [3,9,20,null,null,15,7]
 * Output: [[3],[9,20],[15,7]]
 *
 * Constraints:
 * - The number of nodes in the tree is in the range [0, 2000].
 * - -1000 <= Node.val <= 1000
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root) return ans; // handle empty tree

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int n = q.size();
            vector<int> temp;

            for (int i = 0; i < n; i++) {
                TreeNode* it = q.front();
                q.pop();

                temp.push_back(it->val); // current node value

                if (it->left) q.push(it->left);
                if (it->right) q.push(it->right);
            }

            ans.push_back(temp);
        }
        return ans;
    }
};

/**
 * Time Complexity:
 * - O(N), where N is the number of nodes in the tree.
 *   Each node is visited exactly once.
 *
 * Space Complexity:
 * - O(N), for the queue in the worst case (when the tree is completely full).
 * - O(N) also for the result vector storage.....
 */
