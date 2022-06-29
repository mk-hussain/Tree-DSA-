class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(root == NULL) return 0;
            
        int width = 0;
        queue<pair<TreeNode*,int>> q;
        q.push({root,0}); // 0 based indexing
        while(!q.empty()){
            int size = q.size();
            int leftIndex,rightIndex; // every time subtract with leftIndex
            for(int i=0;i<size;i++){
                int index = q.front().second;
                TreeNode* node = q.front().first;
                q.pop();
                if(i==0)  {
                    leftIndex = index;
                }
                if(i== size -1){
                    rightIndex = index;
                }
                if(node->left) {
                    q.push({node->left , 2ll*(index - leftIndex)+1}); // maybe overflow therefore 2ll
                }
                if(node->right) {
                    q.push({node->right , 2ll*(index - leftIndex)+2});
                }
            }
            width = max(width,rightIndex - leftIndex + 1);
        }
        return width;
        
    }
};