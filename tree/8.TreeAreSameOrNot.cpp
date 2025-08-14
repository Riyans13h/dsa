/*
❓ Question:
Given two binary trees, check whether they are the same or not.
Two binary trees are considered the same if they are structurally identical 
and the nodes have the same value.

Example:
Input:
Tree 1:     1          Tree 2:     1
           / \                    / \
          2   3                  2   3

Output: true

Tree 1:     1          Tree 2:     1
           /                      / \
          2                      2   3

Output: false
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
    bool isSameTree(TreeNode* root1, TreeNode* root2) {
        
        // If one is NULL and other is not -> not same
        if ( (root1 == NULL && root2 != NULL) || (root1 != NULL && root2 == NULL) )
            return false;

        // If both NULL -> same
        if (root1 == NULL && root2 == NULL) 
            return true;

        // If values differ -> not same
        if (root1->val != root2->val) 
            return false;

        // Recursively check left and right subtrees
        return isSameTree(root1->left, root2->left) && 
               isSameTree(root1->right, root2->right);
    }
};

/*
✅ Time Complexity: O(n) 
   - We visit each node once, where n = number of nodes in the smaller tree (if both have same size, it's n in both).

✅ Space Complexity: O(h) 
   - h = height of the tree due to recursion stack (O(n) in worst case skewed tree, O(log n) in best case balanced tree).
*/
