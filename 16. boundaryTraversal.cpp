void inorder(TreeNode<int>* node,vector<int>&ans){
    if(node == NULL) 
        return;
    inorder(node->left,ans);
    if(node->left == NULL && node->right == NULL){// leaf
        ans.push_back(node->data);
    }
    inorder(node->right,ans);
}
vector<int> traverseBoundary(TreeNode<int>* root){
    vector<int> ans;
    if(root == NULL) 
        return ans;
    // root
    ans.push_back(root->data);
    if(root->left == NULL && root->right == NULL){
        return ans;
    }
    // left boundary
    TreeNode<int>* node = root->left;
    while(node != NULL){
        if(node->left==NULL && node->right == NULL)
            break;// dont include any leaf here
        ans.push_back(node->data);
        if(node->left)
            node=node->left;
        else
            node = node->right;
    }
    inorder(root,ans);// root is not a leaf node now
    stack<int> s;// for reversing right boundary
    
    node = root->right;
    while(node != NULL){
         if(node->left==NULL && node->right == NULL)
            break;// dont include any leaf here
        s.push(node->data);
        if(node->right)
            node=node->right;
        else
            node=node->left;
    }
    while(!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }
    return ans;
}