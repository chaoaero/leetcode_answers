/*==================================================================
 *   Copyright (C) 2015 All rights reserved.
 *   
 *   filename:     lowest_common_ancestor_binary_tree.cc
 *   author:       Meng Weichao
 *   created:      2015/12/30
 *   description:  
 *
 ================================================================*/
#include<iostream>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
bool hasNode(TreeNode *root, TreeNode *p) {
    if(root == NULL)
        return false;
    if(root->val == p->val)
        return true;
    return hasNode(root->left, p) && hasNode(root->right, p);
}
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(root->val == p->val && root->val == q->val)
        return root;
    else if(hasNode(root->left, p) && hasNode(root->left, q)) 
        return lowestCommonAncestor(root->left, p, q);
    else if(hasNode(root->right, p) && hasNode(root->right, q))
        return lowestCommonAncestor(root->right, p, q);
    else return root;

}
bool isBalanced(TreeNode* root) {

}
