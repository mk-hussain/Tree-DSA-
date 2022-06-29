// exactly similar to height and balanced check code
// just in every node before backtrack try to maximize
// diameter by max(diameter, leftHeight+rightHeight)
// in all of these leftHeight and rightHeight is required
// nothing else
class Solution {
public:
    int diameter  = 0;
    
    int height(TreeNode* node){
        int ans = 1;
        int leftHeight=0,rightHeight=0;
        if(node->left) leftHeight = height(node->left);
        if(node->right) rightHeight = height(node->right);
        
        diameter = max(diameter,leftHeight+rightHeight);
        
        ans = ans + max(leftHeight,rightHeight);
        return ans;
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL) 
            return 0;
        height(root);
        return diameter;
    }
};