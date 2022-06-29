// solution is nothing but a simple dfs or euler tour on tree
// where we perform some backtrack operation
class Solution {
    int height(TreeNode* node){
        // every node contribute 1 to the height
        int ans=1;// atleast 1 will be returned in case of leaf node
        int leftHeight = 0;
        int rightHeight = 0;
        if(node->left) leftHeight = height(node->left);
        if(node->right) rightHeight = height(node->right);
        ans = ans+max(leftHeight,rightHeight);
        return ans;
    }
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL)
            return 0;
        return height(root);
    }
};
// O(N) space and time