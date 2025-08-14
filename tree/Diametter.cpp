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

/*
Problem:
---------
Given the root of a binary tree, return the maximum path sum of any path.

A path is defined as any sequence of nodes from some starting node to any node in the tree along the parent-child connections. 
The path must contain at least one node and does not need to go through the root.

Example:
---------
Input: root = [1,2,3]
Output: 6
Explanation: The optimal path is 2 -> 1 -> 3, sum = 6.

Input: root = [-10,9,20,null,null,15,7]
Output: 42
Explanation: The optimal path is 15 -> 20 -> 7, sum = 42.

Constraints:
-------------
- The number of nodes in the tree is in the range [1, 3 * 10^4].
- -1000 <= Node.val <= 1000
*/

/* ==========================================================
   OPTIMIZED SOLUTION — O(N)
   ==========================================================
   Approach:
   - Use DFS to compute, for each node, the maximum path sum starting from it
     and going down in one direction.
   - While computing, update a global maximum with:
        leftContribution + rightContribution + root->val
   - Return the maximum single-branch sum (max(left, right) + root->val)
     so parent can extend path in one direction.

   Time Complexity:  O(N) — each node is visited once.
   Space Complexity: O(H) — recursion stack, H = height of tree.
   ==========================================================
*/
class Solution {
public:
    int sum(TreeNode* root, int &maxi) {
        if (root == NULL) return 0;

        int l = max(0, sum(root->left, maxi));  // ignore negative paths
        int r = max(0, sum(root->right, maxi));

        // Update maximum path sum considering current node as highest point
        maxi = max(maxi, l + r + root->val);

        // Return max path starting at root, going in one direction
        return max(l, r) + root->val;
    }

    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        sum(root, maxi);
        return maxi;
    }
};

/* ==========================================================
   O(N²) SOLUTION — Using height calculation separately
   ==========================================================
   Idea:
   - For every node, compute:
       maxPathThroughNode = leftHeight + rightHeight + node->val
   - Update global maximum with this.
   - Then recursively compute for left and right subtrees.
   - This is O(N²) because height() is called for each node and
     traverses subtrees repeatedly.

   Time Complexity:  O(N²) worst case (skewed tree).
   Space Complexity: O(H) recursion stack.
   ==========================================================
*/
class Solution_N2 {
public:
    int height(TreeNode* root) {
        if (!root) return 0;
        return max(height(root->left), height(root->right)) + root->val; // returns sum not levels
    }

    void compute(TreeNode* root, int &maxi) {
        if (!root) return;
        int l = max(0, height(root->left));
        int r = max(0, height(root->right));
        maxi = max(maxi, l + r + root->val);
        compute(root->left, maxi);
        compute(root->right, maxi);
    }

    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        compute(root, maxi);
        return maxi;
    }
};
