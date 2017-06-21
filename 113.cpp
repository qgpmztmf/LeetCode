// 113. Path Sum II 
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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> ans;
        if(!root) return ans;
        vector<int> tmp;
        pathSum(root, sum, ans, tmp);
        return ans;
    }
    void pathSum(TreeNode* root, int sum, vector<vector<int>> &ans, vector<int> &tmp) {
        if(!root) {
            if(sum == 0){
                ans.push_back(tmp);
            }
        }   
         
        else{
            tmp.push_back(root -> val); 
            
            if(root -> left == NULL && root -> right == NULL){
                pathSum(root -> left, sum - root -> val, ans, tmp);
                tmp.pop_back();
            }
            else if(root -> left != NULL && root -> right == NULL){
                pathSum(root -> left, sum - root -> val, ans, tmp);
                tmp.pop_back();
            }
            else if(root -> left == NULL && root -> right != NULL){
                pathSum(root -> right, sum - root -> val, ans, tmp);
                tmp.pop_back();
            }
            else{
                pathSum(root -> left, sum - root -> val, ans, tmp);
                pathSum(root -> right, sum - root -> val, ans, tmp);
                tmp.pop_back();
            }
        }
    }
};
