class Solution {
    // try dry running the code
public:
    TreeNode* lca(TreeNode* node,TreeNode* p,TreeNode* q){
        if(node == NULL || node == p || node == q)
            return node;
        TreeNode* left =lca(node->left,p,q);
        TreeNode* right=lca(node->right,p,q);
        if(left == NULL)
            return right;
        if(right == NULL)
            return left;
        else // both left and right not null ie we got our ans
            return node;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return lca(root,p,q);
    }
};