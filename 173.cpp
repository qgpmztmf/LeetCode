// 173. Binary Search Tree Iterator 
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class BSTIterator {
public:
    TreeNode* node;
    stack<TreeNode*> s;
    
    BSTIterator(TreeNode* root) {
        node = root;
        while(node){
            s.push(node);
            node = node -> left;
        }
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !s.empty();
    }

    /** @return the next smallest number */
    int next() {
        node = s.top();
        int ans = s.top() -> val;
        s.pop();
        if(node -> right) {
            s.push(node -> right);
            node = node -> right;
            while(node -> left) {
                s.push(node -> left);
                node = node -> left;
            }
        }
        return ans;
    }
};

/*
class BSTIterator {
public:
    vector<int> v;
    int currentIndex = -1;
    
    BSTIterator(TreeNode *root) {
        init(root);
        //if(!v.empty()) currentIndex = 0;
    }
	
    void init(TreeNode* root) {
        if(!root) return;
        init(root -> left);
        v.push_back(root -> val);
        init(root -> right);
    }
    
    bool hasNext() {
        if(currentIndex == v.size() - 1)
            return false;
        return true;
    }

    int next() {
        return v[++currentIndex];
    }
};
*/

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
