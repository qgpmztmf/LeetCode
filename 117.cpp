
// 117. Populating Next Right Pointers in Each Node II
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
    void connect(TreeLinkNode *root) {
        if(root){
            if(root -> left || root -> right){
                if(root -> right && root -> left){
                    root -> left ->next = root -> right;
                }
                
                if(root -> next) {
                    TreeLinkNode* t = root -> next;
                    TreeLinkNode* rc = root -> right ? root -> right : root -> left;
                    while(t){
                        if(t -> left){
                            rc -> next = t -> left;
                            rc = rc -> next;
                        }
                        if(t -> right){
                            rc -> next = t -> right;
                            rc = rc -> next;
                        }
                        t = t -> next;
                    }
                }
            }
            connect(root -> left);
            connect(root -> right);
        }
    }
    /*
        void connect(TreeLinkNode *root) {
        if(root == NULL || (root->left == NULL && root->right == NULL)){
            return;
        }
        TreeLinkNode* head = root;

        while(head != NULL){

            TreeLinkNode* dummy = new TreeLinkNode(0);
            TreeLinkNode* ptr = dummy;
            while(head != NULL){
                if(head->left != NULL){
                    ptr->next = head->left;
                    ptr = ptr->next;
                }
                if(head->right != NULL){
                    ptr->next = head->right;
                    ptr = ptr->next;
                }
                head = head->next;
            }
            head = dummy->next;
        }
        
        return ;
    }
};
    */
    
};