// 95. Unique Binary Search Trees II 
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
  vector<TreeNode*> generateTrees(int n) {
        
    if(n == 0){
      vector<TreeNode*> empty;
      return empty;
    }
        
        
    vector<TreeNode*> ans(1,NULL);
    for(int i = 1; i <= n; i++){
      vector<TreeNode*> temp;
      for(int j = 0; j != ans.size(); j++){
                
	TreeNode* root = new TreeNode(i);
	root -> left = ans[j];
	temp.push_back(root);                    //将原树接到新节点的左侧
                
	TreeNode* oldRoot = ans[j];
	TreeNode* insert = ans[j];
	if(insert != NULL){
	  while(insert -> right != NULL){
	    TreeNode* newHead = oldRoot;
	    TreeNode* value = new TreeNode(i);
	    value -> left = insert -> right;
	    insert -> right = value;
	    temp.push_back(copyTreeNode(newHead));
                        
	    insert -> right = value -> left;
	    insert = insert -> right;
	    delete[] value;　　　　　　　　　　　//将新节点接到原树的某一节点的右侧，之后这一节点原来的右侧接到新节点的左侧
          }                                       　//之后复原原来的树，继续遍历，寻找新的结点插入位置，直到树的最右侧    
	  TreeNode* value = new TreeNode(i);
	  insert -> right = value;
	  temp.push_back(copyTreeNode(oldRoot));
	  insert -> right = NULL;
	  delete[] value;
	}
      }
      ans = temp;
    }
    return ans;
  }
    
  TreeNode* copyTreeNode(TreeNode* root) {
    if(root == NULL){
      return NULL;
    }
    else{
      TreeNode *newRoot = new TreeNode(root->val);
      newRoot->left = copyTreeNode(root->left);
      newRoot->right = copyTreeNode(root->right);
      return newRoot;
    }
  }
};
