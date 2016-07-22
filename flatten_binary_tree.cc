/*==================================================================
 *   Copyright (C) 2016 All rights reserved.
 *   
 *   filename:     flatten_binary_tree.cc
 *   author:       Meng Weichao
 *   created:      2016/07/21
 *   description:  
 *
 ================================================================*/
vector<int> preorderTraversal(TreeNode* root) {
    vector<int> res;
    if(root == NULL)
        return res;
    TreeNode *p = root, *q;
    stack<TreeNode *> stk;
    stk.push(p);
    res.push_back(p->val);
    while(p->left != NULL) {
        p = p->left;
        stk.push(p);
        res.push_back(p->val);
    }
    while(!stk.empty()) {
        q = stk.top();
        stk.pop();
        //res.push_back(q->val);
        if(q->right != NULL) {
            p = q->right;
            stk.push(p);
            res.push_back(p->val);
            while(p->left != NULL) {
                p = p->left;
                stk.push(p);
                res.push_back(p->val);
            }
        }
    }
    return res;
}

void flatten(TreeNode* root) {
    if(root == NULL)
        return;
    vector<TreeNode*> res;
    TreeNode *p = root, *q;
    stack<TreeNode *> stk;
    stk.push(p);
    res.push_back(p);
    while(p->left != NULL) {
        p = p->left;
        stk.push(p);
        res.push_back(p);
        //res.push_back(p->val);
    }
    while(!stk.empty()) {
        q = stk.top();
        stk.pop();
        //res.push_back(q->val);
        if(q->right != NULL) {
            p = q->right;
            stk.push(p);
            //res.push_back(p->val);
            res.push_back(p);
            while(p->left != NULL) {
                p = p->left;
                stk.push(p);
                res.push_back(p);
            }
        }
    }
    root->left = NULL;
    root->right = NULL;
    p = root;
    for(int i = 1; i < res.size(); i++) {
        res[i]->left = NULL;
        res[i]->right = NULL;
        p->right = res[i];
        p = res[i];
    }



}

