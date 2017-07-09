// 235. Lowest Common Ancestor of a Binary Search Tree
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return NULL;
        TreeNode* small = p -> val > q -> val ? q : p;
        TreeNode* big = p -> val < q -> val ? q : p;
        if(root -> val > small -> val && root -> val > big -> val)
            return lowestCommonAncestor(root -> left, small, big);
        else if(root -> val < small -> val && root -> val < big -> val)
            return lowestCommonAncestor(root -> right, small, big);
        else
            return root;
    }
};