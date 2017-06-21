// 111. Minimum Depth of Binary Tree
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
    int minDepth(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        else{
            int leftMinDepth = minDepth(root -> left);
            int rightMinDepth = minDepth(root -> right);
            return 1 + (leftMinDepth > rightMinDepth ? (rightMinDepth > 0 ? rightMinDepth : leftMinDepth) : (leftMinDepth > 0 ? leftMinDepth : rightMinDepth));  
        }
    }
};