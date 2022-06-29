// doing a level order traversal makes sense because we need rightmost node if same x and y
// in level order we can simply update our ans to get desired result
class Solution {
  public:
    vector <int> bottomView(Node *root) {
        vector<int> ans;
        map<int,int> m;// x , bottommost value
        if(root == NULL) return ans;
        queue<pair<Node*,int>> q;// node,x 
        q.push({root,0});
        // bottommost and rightmost update hota jayega
        while(!q.empty()){
            Node* node=q.front().first;
            int x = q.front().second;
            q.pop();
            m[x] = node->data;
            if(node->left) q.push({node->left,x-1});
            if(node->right) q.push({node->right,x+1});
        }
        for(auto pr : m){
            ans.push_back(pr.second);
        }
        return ans;
    }
};