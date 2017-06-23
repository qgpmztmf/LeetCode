// 114. Flatten Binary Tree to Linked List 
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
            TreeNode *prev = NULL;
            void flatten(TreeNode* root) {
                if(!root) return;
                flatten(root->right);
                flatten(root->left);
                root->right = prev;
                root->left = NULL;
                prev = root;
            }
        };

/*
class Solution {
public:
    void flatten(TreeNode* root) {
        if(root) {
            TreeNode* tmp = new TreeNode(0);
            TreeNode* head = tmp;
            flatten(root, tmp);
            *root = *((*head).right);
        }
    }
    
    void flatten(TreeNode* root, TreeNode* &tmp) {
        if(root){
            tmp -> right = new TreeNode(root -> val);
            tmp = tmp -> right;
            flatten(root -> left, tmp);
            flatten(root -> right, tmp);
        }
    }
};
*/
