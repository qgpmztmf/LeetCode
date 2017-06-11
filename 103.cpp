// 103. Binary Tree Zigzag Level Order Traversal 
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
    vector<vector<int> > zigzagLevelOrder(TreeNode* root) {
        vector<vector<int> > ans;
        queue<pair<TreeNode* ,int> > q;
        if(root){
            q.push({root, 0});
        }
        while(!q.empty()){
            TreeNode* a = q.front().first;
            int b = q.front().second;
            q.pop();
            
            if(b == ans.size()){
                ans.push_back(vector<int>());
            }
            
            if(b % 2 == 0){
                ans[b].push_back(a -> val);
            }
            else{
                ans[b].insert(ans[b].begin(),a -> val);    
            }
            
            if(a -> left){
                q.push({a -> left ,b + 1});
            }
            if(a -> right){
                q.push({a -> right ,b + 1});
            }
        }
        return ans;
    }
};
