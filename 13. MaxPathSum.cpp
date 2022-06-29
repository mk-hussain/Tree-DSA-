class Solution {
public:
    int max_path_sum = INT_MIN; // during backtrack try to maximize this
    
    // this function returns from any particular node either moving down and going
    // left or right at any
    // instant what max sum you can get 
    // knowing both max left sum and max right sum at every node
    // i can find the curved diameter like sum for every node
    // return 0 if any time -ve value is encountered so to maximize sum
    
    int maxPathDown(TreeNode* node){
        int sum = node->val; // add max left and max right later
        int maxLeft = 0 , maxRight = 0;
        if(node->left) maxLeft = max(0,maxPathDown(node->left));
        if(node->right) maxRight  = max(0 ,maxPathDown(node->right));
        
        max_path_sum=max(max_path_sum,sum+maxLeft+maxRight);
        
       // return max(0,sum+max(maxLeft,maxRight)); // maybe overall sum is -ve so this reject entire subtree // this will handle single 
        // node with -ve value so no path but path should exist so this solution is not accepted
        return sum + max(maxLeft,maxRight); 
    }
    int maxPathSum(TreeNode* root) {
        if(root == NULL)
            return 0;
        
        maxPathDown(root);
        return max_path_sum;
    }
};