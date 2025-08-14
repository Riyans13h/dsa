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
Given a binary tree, determine if it is height-balanced.

A height-balanced binary tree is defined as:
For every node in the tree, the absolute difference between the height 
of the left subtree and the height of the right subtree is at most 1.

Example:
---------
Input:  root = [3,9,20,null,null,15,7]
Output: true

Input:  root = [1,2,2,3,3,null,null,4,4]
Output: false

Constraints:
-------------
- The number of nodes in the tree is in the range [0, 5000].
- -10^4 <= Node.val <= 10^4

Approach:
----------
We use a recursive DFS function `check` that returns:
- The height of the subtree if it is balanced
- -1 if the subtree is unbalanced

At each node:
1. Recursively find the height of the left subtree.
2. Recursively find the height of the right subtree.
3. If any subtree is unbalanced, propagate -1 upward immediately.
4. If the height difference > 1, return -1.
5. Otherwise, return 1 + max(leftHeight, rightHeight).

Time Complexity:
-----------------
O(N), where N = number of nodes.
Each node is visited once, and height is computed in the same pass.

Space Complexity:
------------------
O(H), where H = height of the tree (recursion stack space).
In worst case (skewed tree), O(N). In best case (balanced tree), O(log N).
*/

class Solution {
public:
    // Returns height if subtree is balanced, otherwise returns -1
    int check(TreeNode* root) {
        if (root == NULL) return 0; // height of empty tree is 0

        int left = check(root->left);
        if (left == -1) return -1; // left subtree not balanced

        int right = check(root->right);
        if (right == -1) return -1; // right subtree not balanced

        if (abs(left - right) > 1) return -1; // current node not balanced

        return 1 + max(left, right); // return height
    }

    bool isBalanced(TreeNode* root) {
        return check(root) != -1;
    }
};
