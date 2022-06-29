void dfs(BinaryTreeNode < int > * node){
    if(node->left == NULL && node->right == NULL)
        return;// for leaf node no need of child sum property
    int sum = 0;
    if(node->left) sum+=node->left->data;
    if(node->right) sum+=node->right->data;
    if(sum < node->data){
        // if sum is less then increase both left and right to node->val so that we are never shortage
        if(node->left) node->left->data = node->data;
        if(node->right) node->right->data = node->data;
    }
    if(node->left) dfs(node->left);// do this for left
    if(node->right) dfs(node->right);// do this for right
    sum=0;
    if(node->left) sum+=node->left->data;
    if(node->right) sum+=node->right->data;
    node->data = sum;// finally update node
}
void changeTree(BinaryTreeNode < int > * root) {
    // Write your code here.
    if(root == NULL)
        return ;
    dfs(root);
}  