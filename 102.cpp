// 102. Binary Tree Level Order Traversal 
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/* 
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<pair<int, TreeNode*>> q;
        if (root) q.push({0, root});
        vector<vector<int>> ans;
        while (!q.empty()) {
            int d = q.front().first;
            auto vtx = q.front().second;
            q.pop();
            if (d==ans.size()) ans.push_back(vector<int>());
            ans[d].push_back(vtx->val);
            if (vtx->left) q.push({d+1, vtx->left});
            if (vtx->right) q.push({d+1, vtx->right});
        }
        return ans;
    }
};
*/ 
class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode* root) {
        vector<vector<int> > ans;
        if(root == NULL) return ans;
        
        
        vector<int> level;
        queue<TreeNode *> q;
        q.push(root);
        q.push(NULL);
        while(q.empty() == false){
            
            if(q.front() == NULL){
                q.pop();
                if(q.size() > 0){
                    q.push(NULL);
                }
            }
            else{
                
                level.push_back(q.front() -> val);
                if(q.front() -> left != NULL){
                    q.push(q.front() -> left);
                }
                if(q.front() -> right != NULL){
                    q.push(q.front() -> right);
                }
                
                q.pop();
                if(q.front() == NULL){
                    ans.push_back(level);
                    level.clear();
                }
            }
        }
        return ans;
    }
};
