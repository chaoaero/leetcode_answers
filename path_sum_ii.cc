/*==================================================================
 *   Copyright (C) 2016 All rights reserved.
 *   
 *   filename:     path_sum_ii.cc
 *   author:       Meng Weichao
 *   created:      2016/03/18
 *   description:  
 *
 ================================================================*/
class Solution {
    private:
        vector<string> result;
    public:
        vector<string> binaryTreePaths(TreeNode* root) {

            string temp;
            addSub(root, temp );
            return result;
        }
        void addSub(TreeNode *root, string& str) {
            if(root == NULL)
                return;
            if(root->left == NULL && root->right == NULL) {
                str += to_string(root->val);
                result.push_back(str);
                return ;
            }
            str += to_string(root->val);
            str += "->";
            if(root->left) {
                string woca(str);
                addSub(root->left, woca);
            }
            if(root->right) {
                string shit(str);
                addSub(root->right, shit);
            }

        }
        void path_sum(TreeNode* root, vector<int> inter_res, int sum, int temp_res) {
            if(root == NULL)
                return;
            if(root->left == NULL && root->right == NULL) {
                inter_res.push_back(root->val); 
                temp_res += root->val;
                if(temp_res == sum)
                    result.push_back(inter_res);
                return;
            }
            inter_res.push_back(root->val);
            temp_res += root->val;
            if(root->left) {
                vector<int> nim(inter_res);
                path_sum(root->left, nim, sum, temp_res);
            }
            if(root->right) {
                vector<int> woca(inter_res);
                path_sum(root->right, woca, sum, temp_res);
            }
            
        }
        vector<vector<int>> pathSum(TreeNode* root, int sum) {
            vector<vector<int>> result;
            vector<int> nnn;
            path_sum(root, nnn, sum, 0 );
            return result;
        }
};

