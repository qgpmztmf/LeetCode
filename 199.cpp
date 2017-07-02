// 199. Binary Tree Right Side View
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> v;
        rightSideView(root, 0, v);
        return v;
    }
    
    void rightSideView(TreeNode* root, int level, vector<int> &v) {
        if(!root) return;
        if(v.size() == level) {
            v.push_back(root -> val);
        }
        rightSideView(root -> right, level + 1, v);
        rightSideView(root -> left, level + 1, v);
    }
};