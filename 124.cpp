// 124. Binary Tree Maximum Path Sum 
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
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        maxPathSum(root, ans);
        return ans;
    }
    
    int maxPathSum(TreeNode* root, int& ans){
        if(root){
            int l = maxPathSum(root -> left, ans);
            int r = maxPathSum(root -> right, ans);
            l = l > 0 ? l : 0;
            r = r > 0 ? r : 0;
            
            int sum = l + r + root -> val;
            ans = sum > ans ? sum : ans;
            
            return root -> val + (l > r ? l : r);
            
        }
        else{
            return 0;
        }
    }
    
    /*
    int maxPathSum(TreeNode* root) {
        if(root) {
            int l = maxPathSum(root -> left);
            int r = maxPathSum(root -> right);
            return maxOfThree(l, r, maxPathSumDown(root));
        }
        else {
            return INT_MIN;
        }
    }
    
    int maxPathSumDown(TreeNode* root) {
        if(root) {
            int l = _maxPathSumDown(root -> left);
            int r = _maxPathSumDown(root -> right);
            return (l > 0 ? l : 0) + (r > 0 ? r : 0) + root -> val;
        }
        else {
            return 0;
        }
    }
    
    int _maxPathSumDown(TreeNode* root) {
        if(root) {
            int l = _maxPathSumDown(root -> left);
            int r = _maxPathSumDown(root -> right);
            l = (l > 0 ? l : 0);
            r = (r > 0 ? r : 0);
            return root -> val + (l > r ? l : r);
        }
        else {
            return 0;
        }
    }
    
    int maxOfTwo(int a, int b) {
        return a > b ? a : b;
    }
    
    int maxOfThree(int a, int b, int c) {
        return maxOfTwo(maxOfTwo(a, b), c);
    }*/
};

