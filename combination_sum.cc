/*==================================================================
 *   Copyright (C) 2016 All rights reserved.
 *   
 *   filename:     combination_sum.cc
 *   author:       Meng Weichao
 *   created:      2016/07/19
 *   description:  
 *
 ================================================================*/
#include<iostream>
#include<vector>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;
void backtracking(vector<vector<int> >& res, vector<int>& tmp, vector<int>& candidates, int target, int index){
    if(target < 0) return;
    if(target == 0) {
        res.push_back(tmp);
        return;
    }
    for(int i = index; i < candidates.size(); i++){
        tmp.push_back(candidates[i]);
        backtracking(res, tmp, candidates, target - candidates[i], i);
        tmp.pop_back();
    }
}

void gen_res(vector<vector<int> >&result, vector<int>& candidates,vector<int>& temp, int k, int current) {
    if(current <0)
        return;
    if(current == 0) {
        result.push_back(temp);
        return;
    }

    for(int i = k; i < candidates.size(); i++) {
        temp.push_back(candidates[i]);
        gen_res(result, candidates, temp, i, current - candidates[i]);
        temp.pop_back();
    }
}


vector<vector<int> > combinationSum(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end());
    vector<vector<int> > res;
    vector<int> tmp;
    backtracking(res, tmp, candidates, target, 0);
    return res;
}

void generate_result(vector< vector<int> >& result, vector<int>& candidates, int c[], int k, int current, int target) {
    if(current > target) {
        return;
    }
    if(current == target) {
        vector<int> temp;
        for(int i = 0; i < candidates.size(); i++) {
            for(int j = 1; j <= c[i]; j++)
                temp.push_back(candidates[i]);
        }
        result.push_back(temp);
        return ;
    }

    for(int i = k ; i < candidates.size(); i++  ) {
        if(i > k && candidates[i] == candidates[i - 1])
            continue;
        c[i] += 1;
        generate_result(result, candidates, c, i + 1, current + candidates[i]  , target);
        c[i]  -= 1;
    }

}


vector<vector<int> > combinationSum2(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end());
    vector<int> temp;
    vector<vector<int> > result;
    if(candidates.size() == 0)
        return result;
    int c[candidates.size()];
    memset(c, 0, sizeof(c));
    int current = 0;

    generate_result(result, candidates, c, 0, 0, target); 
    //gen_res(result, candidates, temp, 0, target);
    // backtracking(result, temp, candidates, target , 0);
    return result;
}

vector<vector<int> > combinationSum_unique(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end());
    vector<int> temp;
    vector<vector<int> > result;
    if(candidates.size() == 0)
        return result;
    int c[candidates.size()];
    memset(c, 0, sizeof(c));
    int current = 0;

    generate_result(result, candidates, c, 0, 0, target); 
    //gen_res(result, candidates, temp, 0, target);
    // backtracking(result, temp, candidates, target , 0);
    return result;
}

int main() {
    int arr[7] = {10, 1, 2, 7, 6, 1, 5}; 
    vector<int> vec(arr, arr + sizeof(arr)/sizeof(int));
    //vector<vector<int> > result = combinationSum(vec, 7);
    vector<vector<int> > result = combinationSum_unique(vec, 8);
    for(int i = 0; i < result.size(); i++) {
        cout<<"[";
        for(vector<int>::iterator itt = result[i].begin(); itt != result[i].end(); itt++) {
            cout<<*itt<<", ";
        }
        cout<<"]"<<endl;
    }
    return 0;
}
