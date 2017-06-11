// 105. Construct Binary Tree from Preorder and Inorder Traversal 
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=preorder.size();
        if(n==0) return NULL;
        
        stack<TreeNode*> temp; TreeNode* root;
        root = new TreeNode(preorder[0]);
        temp.push(root);
        TreeNode* curr=root;
        int j=0,flag=0;
        
        for (int i=1; i<n;) {
            
            
            if (!temp.empty() && temp.top()->val==inorder[j]) {
                curr=temp.top();
                temp.pop();
                j++;
                flag=1;
            }
            else {
                if (flag==1) {
                    flag=0;
                    curr->right=new TreeNode(preorder[i]);
                    curr=curr->right;
                    temp.push(curr);
                    i++;
                    
                }
                else {
                    curr->left=new TreeNode(preorder[i]);
                    curr=curr->left;
                    temp.push(curr);
                    i++;
                }
            }
            
        }
        return root;
    }
};
*/
 
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode* root = NULL;
        createTreeInt(preorder, inorder, 0, preorder.size(), 0, inorder.size(),root);
        return root;
    }
    
    void createTreeInt(vector<int> &pre, vector<int> &in, int pl, int pr, int il, int ir, TreeNode* &t){
        if(pre.size() == 0) return;
        if(!t){
            t = new TreeNode(pre[pl]);
            vector<int>::iterator ite;
            ite = find(in.begin() + il ,in.begin() + ir ,pre[pl]);

            int lenL = distance(in.begin() + il ,ite);
      
            if(lenL > 0){ 
                createTreeInt(pre, in, pl + 1, pl + lenL + 1, il, il + lenL, t -> left);
            }
      
            int lenR = distance(ite+1 ,in.begin() +ir);
      
            if(lenR > 0){ 
                createTreeInt(pre, in, pr - lenR, pr, ir - lenR, ir, t -> right);
            }
        }
    }
};

/*

void createTreeInt(vector<int> preOrderElms, vector<int> inOrderElms){
    _createTreeInt(preOrderElms,inOrderElms,root);
  }

  void _createTreeInt(vector<int> pre, vector<int> in, binaryTreeNode<int>* &t){
    if(!t){
      t = new binaryTreeNode<int>(pre[0]);
      vector<int>::iterator ite;
      ite = find(in.begin(),in.end(),pre[0]);

      int lenL = distance(in.begin(),ite);
      
      if(lenL > 0){ 
        vector<int> subInLeft(lenL);
        vector<int> subPreLeft(lenL);
        copy(in.begin(), ite, subInLeft.begin());
        copy(pre.begin()+1, pre.begin()+lenL+1, subPreLeft.begin());
        _createTreeInt(subPreLeft,subInLeft,t -> leftChild);
      }
      
      int lenR = distance(ite+1,in.end());
      
      if(lenR > 0){ 
        vector<int> subInRight(lenR);
        vector<int> subPreRight(lenR);
        copy(ite+1, in.end(),subInRight.begin());
        copy(pre.end()-lenR, pre.end(),subPreRight.begin());
        _createTreeInt(subPreRight,subInRight,t -> rightChild);
      }
    }
  }

*/

