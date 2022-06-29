// level order makes sense as for every level node visible will be the right most node of that level
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(root == NULL) 
            return ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                TreeNode* node = q.front();
                q.pop();
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
                if(i==size-1) ans.push_back(node->val);
            }
        }
        return ans;
    }
};
// for left view make traverse level right to left and do same

// but recursive solution uses O(H) space which may be lesser
// than space of level order O(N)
// we go for recursive