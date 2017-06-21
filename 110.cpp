// 110. Balanced Binary Tree 
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
    bool isBalanced(TreeNode* root) {
        return isBalanced(root, 0);
    }
    
    bool isBalanced(TreeNode* root, int &depth) {
        if(root == NULL){
            depth = 0;
            return true;
        }
        else{
            int left = 0;
            int right = 0;
            if(isBalanced(root -> left, left) && isBalanced(root -> right, right)){
                depth = 1 + (left > right ? left : right);
                int diff = left - right;
                
                if(diff <= 1 && diff >= -1){
                    return true;
                }
                else{
                    return false;
                }
            }
            else{
                return false;
            }
        }
    }
};
