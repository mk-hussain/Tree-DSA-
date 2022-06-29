// my way of implementation little easier !!

class Solution {
public:
    // just make a boolean flag isBalanced and do a normal
    // euler tour dfs of the tree so that you know at every node
    // what is the left heigt and what is the right height and at 
    // any node if you find the difference bw left and right is
    //  > 1 you change isBalanced to false // but to know height at every 
    // node you need to keep track of height
    
    bool is_balanced = true;
    
    int height(TreeNode* node){
        int ans = 1;
        int leftHeight=0,rightHeight=0;
        if(node->left) leftHeight = height(node->left);
        if(node->right) rightHeight = height(node->right);
        
        if(abs(leftHeight-rightHeight) > 1) is_balanced = false; // this is the check 
        
        ans = ans + max(leftHeight,rightHeight);
        return ans;
    }
    bool isBalanced(TreeNode* root) {
        if(root == NULL)
            return true;
        height(root); // not keeping the returned value
        return is_balanced;
    }
};



class Solution {
public:
    // this function return the height of a tree if only the 
    // tree is balanced else it return -1
    int height(TreeNode* node){
        if(node == NULL){
            return 0;
        }
        
        int leftHeight = height(node->left);
        int rightHeight = height(node->right);
        if(leftHeight == -1 || rightHeight == -1)
            return -1;
        // left and right subtree are balanced now
        // check if this node is balanced
        if(abs(leftHeight-rightHeight) > 1)
            return -1;
        return 1 + max(leftHeight,rightHeight);
    }
    bool isBalanced(TreeNode* root) {
        int h= height(root);
        if(h==-1)
            return false;
        return true;
    }
};

