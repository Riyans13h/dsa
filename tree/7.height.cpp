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
 int  depth ( TreeNode*root ){
    if ( root ==  0 ) return 0;
    int left =  depth ( root ->left);
    int right = depth ( root->right);
    return 1+ max ( left , right );
 }
    int maxDepth(TreeNode* root) {

       return depth ( root );  
 
    }
};



/*Time Complexity:
-----------------
O(N²) in the worst case (skewed tree) because at each node we recompute heights for its subtrees.

Space Complexity:
------------------
O(H), where H = height of the tree (recursion stack space).
Worst case: O(N), Best case: O(log N).
*/

class Solution {
public:
    // Function to compute height of a subtree
    int height(TreeNode* root) {
        if (!root) return 0;
        return 1 + max(height(root->left), height(root->right));
    }

    // Function to check if tree is balanced
    bool check(TreeNode* root) {
        if (!root) return true;

        int leftHeight = height(root->left);
        int rightHeight = height(root->right);

        if (abs(leftHeight - rightHeight) > 1) return false;

        return check(root->left) && check(root->right);
    }

    bool isBalanced(TreeNode* root) {
        return check(root);
    }
};