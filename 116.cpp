// 116. Populating Next Right Pointers in Each Node
/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    /*
    void connect(TreeLinkNode *root) {
        if(root==NULL) return;
        if(root->left) {
            root->left->next = root->right;
            if (root->next!=NULL) 
                root->right->next = root->next->left;
            connect(root->left);
            connect(root->right);
        }
    }*/

    void connect(TreeLinkNode *root) {
        queue<pair<int, TreeLinkNode*>> q;
        if(root) q.push({0,root});
        TreeLinkNode* prev = NULL;
        int number = 0;
        while(!q.empty()){
            number = number + 1;
            int index = q.front().first;
            TreeLinkNode* node = q.front().second;
            q.pop();
            if(number == pow(2, index)){
                prev = node;
            }
            else{
                prev -> next = node;
                prev = node;
            }
            if(node -> left) q.push({index + 1,node -> left});
            if(node -> right) q.push({index + 1,node -> right});
        }
    }
};