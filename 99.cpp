// 99. Recover Binary Search Tree 
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
    void helper(TreeNode *r, TreeNode* &pre, TreeNode* &error1, TreeNode* &error2){
    	if (r){
    		helper(r->left, pre, error1, error2);
    		if (pre){
    			if (pre->val > r->val){
    				//为了防止两个相邻节点的情况在第一次遇到错误节点的时候
    				//将两个错误节点均分别为pre和r,第二个错误节点在后面会更新
    				if (error1 == NULL){ 
    					error1 = pre;
    					error2 = r;
    				}
    				else
    					error2 = r;
    			}
    		}
    		pre = r;
    		helper(r->right, pre, error1, error2);
    	}
    }
    void recoverTree(TreeNode* root) {
    	TreeNode *pre = NULL, *error1 = NULL, *error2 = NULL;
    	helper(root, pre, error1, error2);
    	swap(error1->val, error2->val);
    }
};*/

class Solution {
public:
    TreeNode* small = NULL;
    TreeNode* big = NULL;
    TreeNode* lastNode = new TreeNode(INT_MIN);
    
    void recoverTree(TreeNode* root) {
        traverse(root);
        int tmp = big -> val;
        big -> val = small -> val;
        small -> val = tmp;
    }
    
    void judge(TreeNode* root){
        if(lastNode -> val > root -> val){
            if(small == NULL){
                small = lastNode;
                big = root;
            }
            else{
                big = root;
            }
        }
        lastNode = root;
    }
    
    void traverse(TreeNode* root){
        if(root == NULL){
            return;
        }
        else{
            traverse(root -> left);
            judge(root);
            traverse(root -> right);
        }
    }
};
