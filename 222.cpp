// 222. Count Complete Tree Nodes
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
    int countNodes(TreeNode* root) {
        
        if(root == NULL) {
            return 0;
        }
        
        int lh = getHeight(root -> left);
        int rh = getHeight(root -> right);
        
        if(lh == rh) {
            return (1 << lh) + countNodes(root -> right);
        }
        else {
            return (1 << rh) + countNodes(root -> left);
        }
    }
    
    int getHeight(TreeNode* root) {
        int height = 0;
        while(root) {
            root = root -> left;
            height = height + 1;
        }
        return height;
    }
};