
// reversing row explicitly takes additional O(n) time so avoid it using index like p
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL)
            return ans;
        
        queue<TreeNode*> q;
        q.push(root);
        int flag=0; // left to right 
        while(!q.empty()){
            int size = q.size();
            vector<int> row(size);
            int p = flag ? size-1 : 0;
            for(int i=0;i<size;i++){
                TreeNode* node = q.front();
                q.pop();
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
                row[p]=node->val;
                flag ? p--:p++;
            }
            flag = !flag;
            ans.push_back(row);
        }
        return ans;
    }
};