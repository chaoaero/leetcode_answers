/*==================================================================
 *   Copyright (C) 2015 All rights reserved.
 *   
 *   filename:     balance_tree.cc
 *   author:       Meng Weichao
 *   created:      2015/12/30
 *   description:  
 *
 ================================================================*/
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

unordered_map<TreeNode *, int> node_depth;
bool isBalanced(TreeNode* root) {
    if(root == NULL)
        return true;
    int left_depth = maxDepth(root->left);
    int right_depth = maxDepth(root->right);
    if(abs(left_depth - right_depth) <= 1) {
        return isBalanced(root->left) && isBalanced(root->right);
    } else
        return false;
}

int maxDepth(TreeNode* root) {
    if(root != NULL) {
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    } else {
        return 0;
    }
}

int max(int a, int b) {
    return a > b ? a : b;
}

bool isSymmetric(TreeNode* root) {
    if(root == NULL)
        return true;
    return checkSymmetric(root->left, root->right);

}
bool checkSymmetric(TreeNode *p, TreeNode *q) {
    if(p == NULL && q != NULL || p != NULL && q == NULL)
        return false;
    if(p == NULL && q== NULL)
        return true;
    if(p->val != q->val)
        return false;
    return checkSymmetric(p->left, q->right ) && checkSymmetric(p->right , q->left);

}
