bool getPath(TreeNode* node,int b,vector<int> &path){
    if(node == NULL) return false; // didnt get path
    path.push_back(node->val);
    if(node->val == b){
        return true;// got path
    }
    
    if(getPath(node->left,b,path) || getPath(node->right,b,path)){
        return true;// if either of left or right give path return true
    }
    else{
        path.pop_back();// remove this val and return false
        return false;
    }
}
vector<int> Solution::solve(TreeNode* A, int B) {
    vector<int> path;
    getPath(A,B,path); // definately gonna return true
    return path;
}