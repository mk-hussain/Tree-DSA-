class Solution {
public:
    // check if in both tree current node is same and then check if both left and right tree are same
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL && q == NULL) return true;
        if(p == NULL || q == NULL) return false;
        // p != NULL and q != NULL check if both value is same
        if(p->val != q-> val) 
            return false;
        
        if(isSameTree(p->left,q->left) && isSameTree(p->right,q->right))
            return true;
        else
            return false;
    }
};
// another approach is to compare any of pre/in/post traversal