// 106. Construct Binary Tree from Inorder and Postorder Traversal 
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        TreeNode* root = NULL;
        createTreeInt(postorder, inorder, 0, postorder.size(), 0, inorder.size(),root);
        return root;
    }
    
    void createTreeInt(vector<int> &post, vector<int> &in, int pl, int pr, int il, int ir, TreeNode* &t){
        if(post.size() == 0) return;
        if(!t){
            t = new TreeNode(post[pr - 1]);
            vector<int>::iterator ite;
            ite = find(in.begin() + il, in.begin() + ir, post[pr - 1]);
            int lenL = distance(in.begin() + il ,ite);
               
            if(lenL > 0){ 
                createTreeInt(post, in, pl, pl + lenL, il, il + lenL, t -> left);
            }
      
            int lenR = distance(ite+1 ,in.begin() + ir);
      
            if(lenR > 0){ 
                
                createTreeInt(post, in, pr - lenR - 1, pr - 1, ir - lenR, ir, t -> right);
            }
        }
    }
};
