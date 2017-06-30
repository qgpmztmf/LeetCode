// 129. Sum Root to Leaf Numbers 
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
    int sumNumbers(TreeNode* root) {
        int value = 0;
        int ans = 0;
        sumNumbers(root, value, ans);
        return ans;
    }
    void sumNumbers(TreeNode* root, int value, int& ans) {
        if(root) {
            value *= 10;
            value += root -> val;
            sumNumbers(root -> left, value, ans);
            sumNumbers(root -> right, value, ans);
            if(!root -> left && !root -> right){
                ans += value;
            }
        }
    }
};
