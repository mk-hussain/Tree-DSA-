class Solution {
public:
    map<int,map<int,multiset<int>>> m;
    // so that we get every column easily
    void dfs(TreeNode* node , int x,int y){
        m[x][y].insert(node->val);
        if(node->left) dfs(node->left,x-1,y+1);
        if(node->right) dfs(node->right,x+1,y+1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL) 
            return ans;
        dfs(root,0,0);
        for(auto pr : m){
            vector<int> col;
            for(auto p : pr.second){
                for(auto val : p.second){
                    col.push_back(val);
                }
            }
            ans.push_back(col);
        }
        return ans;
    }
};