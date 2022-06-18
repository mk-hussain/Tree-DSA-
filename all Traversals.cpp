// Inorder Recursive
class Solution {
public:
    vector<int> ans;
    void inorder(TreeNode* p){
        if(p == NULL)
            return;
        inorder(p->left);
        ans.push_back(p->val);
        inorder(p->right);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        inorder(root);
        return ans;
    }
};


// Preorder Recursive
class Solution {
public:
    vector<int> ans;
    void preorder(TreeNode* p){
        if(p==NULL)
            return;
        ans.push_back(p->val);
        preorder(p->left);
        preorder(p->right);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        preorder(root);
        return ans;
    }
};

// postorder recursive
class Solution {
public:
    void postorder(TreeNode* p,vector<int> &ans){
        if(p == NULL)
            return;
        postorder(p->left,ans);
        postorder(p->right,ans);
        ans.push_back(p->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        postorder(root,ans);
        return ans;
    }
};

// level order
class Solution {
public:
    // TC- O(n) SC - O(N)
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        if(root != NULL) //  very very important otherwise give runtime error
        q.push(root); // queue me null nhi jana chahiye
        while(!q.empty()){
            vector<int> level; // single level of nodes
            int k = q.size(); // all nodes in queue will be having same level
            for(int i=0;i<k;i++){ // pop exactly k nodes
                TreeNode* node = q.front();
                q.pop();
                level.push_back(node->val);
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }
            ans.push_back(level);
        }
        return ans;
    }
};

// preorder iterative
class Solution {
public:
    // iterative solution
    // O(N) time and space
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> s;
        vector<int> ans;
        if(root == NULL)
            return ans;
        // root is not null
        s.push(root);
        // algorithm :- take top of the stack and print it after push right node then push left node
        // which will ensure left one is processed before right
        while(!s.empty()){
            TreeNode* node  = s.top();
            s.pop();
            ans.push_back(node->val);
            // first push right then push left
            if(node->right)
                s.push(node->right);
            if(node->left)
                s.push(node->left);
        }
        return ans;
    }
};

// way 2 like recursion

class Solution {
public:
    // iterative solution like recursion
    
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> s;
        vector<int> ans;
        TreeNode* node=root;
        while(true){
            if(node != NULL){
                ans.push_back(node->val);
                s.push(node);
                node=node->left;
            }
            else{
                if(s.empty())
                    break;
                node=s.top();
                s.pop();
                node=node->right;
            }
        }
        return ans;
    }
};

// inorder Iterative
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> s;
        TreeNode* node = root;
        while(true){
            // implement like recursion infinite loop
            if(node != NULL){
                s.push(node);
                node=node->left;
            }
            else{
                // pop and get a node and print it and go right
                if(s.empty())
                    break;
                node = s.top();
                s.pop();
                ans.push_back(node->val);
                node=node->right;
            }
        }
        return ans;
    }
};


// postorder Important

class Solution {
public:
    /**
    2 stack solution
    Algorithm :-
    Take two stack s1 and s2
    push root into s1
    while(s1 is not empty){
    remove top element of s1 and put it into s2
    then push its left and right in s1
    }
    **/
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> s1;
        stack<int> s2;
        vector<int> ans;
        if(root == NULL)
            return ans;
        s1.push(root);
        while(!s1.empty()){
            TreeNode* node=s1.top();
            s2.push(node->val);
            s1.pop();
            if(node->left)
                s1.push(node->left);
            if(node->right)
                s1.push(node->right);     
        }
        while(!s2.empty()){
            int n =s2.top();
            s2.pop();
            ans.push_back(n);
        }
        return ans;
    }
};

// 1 stack

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> s;
        TreeNode* node = root;
        while(true){
            if(node != NULL){
                s.push(node);
                node=node->left;
            }
            else{
                if(s.empty()) break;
                TreeNode* temp = s.top()->right;
                if(temp != NULL){
                    node=temp;
                }
                else{
                    // visit the node on the top of stack 
                    temp = s.top();
                    s.pop();
                    ans.push_back(temp->val);
                    while(!s.empty() && s.top()->right == temp){
                        // copy paste
                         temp = s.top();
                         s.pop();
                         ans.push_back(temp->val);
                    }
                }
            }
        }
        return ans;
    }
};


// Inorder + preorder + postorder in 1 traversal

vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root){
    // Write your code here.
    stack<pair<BinaryTreeNode*,int>> s;
    vector<vector<int>> ans();
    vector<int> inorder,preorder,postorder;
    if(root == NULL)
        return ans;
    s.push({root,1});
    while(!s.empty()){
        pair<BinaryTreeNode*,int> p=s.top();
        s.pop();
        if(p.second == 1){
            preorder.push_back((p.first)->data);
            s.push({p.first,p.second+1});
            if((p.first)->left != NULL){
                s.push({(p.first)->left,1});
            }
        }
        if(p.second == 2){
            inorder.push_back((p.first)->data);
            s.push({p.first,p.second+1});
            if((p.first)->right != NULL){
                s.push({(p.first)->right,1});
            }
        }
        if(p.second == 3){
            postorder.push_back((p.first)->data);
        }
    }
    ans.push_back(inorder);
    ans.push_back(preorder);
    ans.push_back(postorder);
    return ans;
}

