// 107. Binary Tree Level Order Traversal II 
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        queue<pair<int, TreeNode*>> q;
        if (root) q.push({0, root});
        vector<vector<int>> ans;
        while (!q.empty()) {
            int d = q.front().first;
            auto vtx = q.front().second;
            q.pop();
            if (d==ans.size()) ans.push_back(vector<int>());
            if (vtx->left) q.push({d+1, vtx->left});
            if (vtx->right) q.push({d+1, vtx->right});
            ans[d].push_back(vtx->val);
        }
        reverse(ans.begin(),ans.end());
        return ans; 
    }
    /*
    vector<vector<int>> reverse(vector<vector<int>> v){
        if(v.empty()) return v;
        vector<vector<int>> ans;
        for(vector<vector<int>>::iterator i = v.end() - 1; i >= v.begin(); i--){
            ans.push_back(*i);
        }
        return ans;
    }*/
};
