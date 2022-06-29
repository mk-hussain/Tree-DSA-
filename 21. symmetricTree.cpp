class Solution {
public:
    bool mirror(TreeNode* leftT,TreeNode* rightT){
        if(leftT == NULL && rightT == NULL)
            return true;
        if(leftT == NULL || rightT == NULL)
            return false;
        if(leftT->val != rightT->val)
            return false;
        if(mirror(leftT->left,rightT->right) && mirror(leftT->right,rightT->left))
            return true;
        else
            return false;
    }
    bool isSymmetric(TreeNode* root) {
        if(root == NULL)
            return true;
        TreeNode* leftSubtree=root->left;
        TreeNode* rightSubtree = root->right;
        // do euler and reverse euler on both subtree simultaneously
        if(mirror(leftSubtree,rightSubtree))
            return true;
        else
            return false;
    }
};