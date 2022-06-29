class Solution
{
    public:
    map<int,pair<int,int>> m; //vertical x, {y,data}
    void dfs(Node* node,int x,int y){
        if(m.find(x) == m.end()){// vertical x is not present 
            m[x] = {y,node->data}; 
        }
        else if(m[x].first > y){// if x is present check if current y < m[x] then this is upper
            m[x] = {y,node->data};
        }
        if(node->left) dfs(node->left,x-1,y+1);
        if(node->right) dfs(node->right,x+1,y+1);
    }
    vector<int> topView(Node *root)
    {
        vector<int> ans;
        if(root == NULL) return ans;
        dfs(root,0,0);
        for(auto val : m){
            ans.push_back(val.second.second);
        }
        return ans;
    }

};