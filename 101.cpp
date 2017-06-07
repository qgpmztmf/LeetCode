//  101. Symmetric Tree
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
    bool isSymmetric(TreeNode* root) {
        if(!root) {
            return true;
        }
        else{
            return isSymmetric(root -> left, root -> right);
        }
    }
    
    bool isSymmetric(TreeNode* m, TreeNode* n) {
        if(m == NULL && n == NULL){
            return true;
        }
        else if(m == NULL || n == NULL){
            return false;
        }
        else if(m -> val != n -> val){
            return false;
        }
        else{
            return isSymmetric(m -> left, n -> right) && isSymmetric(m -> right, n -> left);
        }
    }
    
};