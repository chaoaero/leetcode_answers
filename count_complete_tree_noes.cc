/*==================================================================
 *   Copyright (C) 2016 All rights reserved.
 *   
 *   filename:     count_complete_tree_noes.cc
 *   author:       Meng Weichao
 *   created:      2016/07/22
 *   description:  
 *
 ================================================================*/
int countNodes(TreeNode* root) {
    if(root == NULL)
        return 0;
    int num_leaves = 0;
    int height = get_height(root);
    if(root->right == NULL) {
        if(root->left == NULL)
            return 1;
        else 
            return 2;
    }
    int r_height = get_height(root->right);
    int answer = 0;
    if(r_height == height - 1) {
        answer = pow(2, h) + countNodes(root->right);
    } else {
        answer = pow(2, h - 1) + countNodes(root->left);
    }
    return answer;
}

int get_height(TreeNode* root) {
     int height = 0;
    TreeNode *p = root;
    while(p) {
        height++;
        p = p->left;
    }
    return height - 1;  
}

