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
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> ans(1,NULL);
        for(int i = 1; i <= n; i++){
            for(int j = 0; j != ans.size(); j++){
                vector<TreeNode*> temp;
                TreeNode* root = new TreeNode(i);
                root -> left = ans[j];
                temp.push_back(root);
                ans = temp;
            }
            if()
        }
        return ans;
    }
    
    TreeNode* copyTreeNode(TreeNode* root) {
        if(root == NULL){
            return NULL;
        }
        else{
            TreeNode *newRoot = new TreeNode(root->val);
            newRoot->left = copyTreeNode(root->left);
            newRoot->right = copyTreeNode(root->right);
            return newRoot;
        }
    }
};