// 230. Kth Smallest Element in a BST
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
    int size(TreeNode* root) {
        if(root == NULL) {
            return 0;
        }
        else{
            return 1 + size(root -> left) + size(root -> right);
        }
    }
    
    int kthSmallest(TreeNode* root, int k) {
        if(root == NULL) return 0;
        int leftSize = size(root -> left);
        int rightSize = size(root -> right);
        
        if (leftSize + 1 == k) return root -> val;
        else if (leftSize + 1 < k) return kthSmallest(root -> right, k - leftSize - 1);
        else return kthSmallest(root -> left, k);
    }
    /*
    int kthSmallest(TreeNode* root, int k) {
        int ans = 0;
        bool stop = false;
        kthSmallest(root, k, ans, stop);
        return ans;
    }
    
    bool kthSmallest(TreeNode* root, int &k, int &ans, bool &stop) {
        
        if(stop == true) return false;
        if(root == NULL) return false;
        kthSmallest(root -> left, k, ans, stop);
        k = k - 1;
        if(k == 0){
            ans = root -> val;
            stop = true;
        }
        kthSmallest(root -> right, k, ans, stop);
        return true;
    }
    */
};