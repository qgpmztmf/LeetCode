// 112. Path Sum 
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
    bool hasPathSum(TreeNode* root, int sum) {
        if(!root){
            return false;
        }
        else{
            return _hasPathSum(root,sum);
        }
    }

    bool _hasPathSum(TreeNode* root, int sum) {
        if(!root) {
            if(sum == 0){
                return true;
            }
            else{
                return false;
            }
        }   
        
        else{
            bool leftValue = _hasPathSum(root -> left, sum - root -> val);
            bool rightValue = _hasPathSum(root -> right, sum - root -> val);
            if(root -> left == NULL && root -> right == NULL){
                return leftValue || rightValue;
            }
            else if(root -> left != NULL && root -> right == NULL){
                return leftValue;
            }
            else if(root -> left == NULL && root -> right != NULL){
                return rightValue;
            }
            else{
                return leftValue || rightValue;
            }
        }
    }
};
