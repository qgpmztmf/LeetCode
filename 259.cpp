// 257. Binary Tree Paths
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
    vector<string> binaryTreePaths(TreeNode* root) {
        string tmp;
        vector<string> ans;
        binaryTreePaths(root, tmp, ans);
        return ans;
    }
    
    void binaryTreePaths(TreeNode* root, string tmp, vector<string> &ans) {
        if(!root) return;
        tmp = tmp + to_string(root -> val) + "->";
        binaryTreePaths(root -> left, tmp, ans);
        binaryTreePaths(root -> right, tmp, ans);
        
        if(!root -> left && !root -> right) {
            tmp.pop_back();
            tmp.pop_back();
            ans.push_back(tmp);
        }
    }
};