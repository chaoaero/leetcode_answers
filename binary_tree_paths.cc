/*==================================================================
 *   Copyright (C) 2016 All rights reserved.
 *   
 *   filename:     binary_tree_paths.cc
 *   author:       Meng Weichao
 *   created:      2016/03/18
 *   description:  
 *
 ================================================================*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {

    public:
        void dfs(TreeNode* root, string& intermediate, vector<string> result) {
            if(root == NULL) {
                if(!intermediate.empty())
                    result.push_back(intermediate);
                return;
            }   
            string temp;
            string cp_str(intermediate);
            if(intermediate.empty())
                temp.append(std::to_string(root->val));
            else
                temp.append("->").append(std::to_string(root->val));
            dfs(root->left, intermediate.append(temp), result);
            dfs(root->right, cp_str.append(temp), result);
        }
        vector<string> binaryTreePaths(TreeNode* root) {
            vector<string> result;
            string temp;
            dfs(root, temp, result);
            return result;
        }
};
