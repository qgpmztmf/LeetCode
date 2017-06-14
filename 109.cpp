// 109. Convert Sorted List to Binary Search Tree 
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {
        ListNode* tmp = head;
        int length = 0;
        while(tmp){
            tmp = tmp -> next;
            length = length + 1;
        }
        return sortedListToBST(head,0,length);
    }
    
    TreeNode* sortedListToBST(ListNode* &head, int start, int end){
        if(start < end){
            
            int middle = (start + end) / 2;
            TreeNode* parent = new TreeNode(0);
            parent -> left = sortedListToBST(head, start, middle);
        
            parent -> val = head -> val;
            head = head -> next;
            
            parent -> right = sortedListToBST(head, middle + 1, end);
            return parent;
        }
        return NULL;
    }
};
