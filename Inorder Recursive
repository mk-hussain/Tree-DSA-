class Solution {
public:
    vector<int> ans;
    void inorder(TreeNode* p){
        if(p == NULL)
            return;
        inorder(p->left);
        ans.push_back(p->val);
        inorder(p->right);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        inorder(root);
        return ans;
    }
};
