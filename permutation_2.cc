/*==================================================================
 *   Copyright (C) 2016 All rights reserved.
 *   
 *   filename:     permutation_2.cc
 *   author:       Meng Weichao
 *   created:      2016/03/31
 *   description:  
 *
 ================================================================*/
#include<iostream>
#include<string>
#include<vector>
#include<stdint.h>
#include <climits>
#include<algorithm>
#include<stdlib.h>
#include<string.h>
#include <bitset>
#include<stack>
#include<cmath>
#include<cctype>
#include<cctype>
#include<set>

using namespace std;

void perm(int k, int n, vector<int>&nums, vector<vector<int> >& result) {
    if(k >=n) {
        result.push_back(nums);
        return ;
    }
    for(int i = k; i< n; i++) {
        if(i > k && nums[i] == nums[k])
            continue;
        int temp = nums[k];
        nums[k] = nums[i];
        nums[i] = temp;
        perm(k + 1, n, nums, result);
        temp = nums[k];
        nums[k] = nums[i];
        nums[i] = temp;
    } 
}
void permute(int k, int n, int c[], int d[], vector<int>& nums, vector<vector<int> >& result ) {
    if(k >= n) {
        vector<int> temp;
        for(int i = 0; i< n; i++) {
            temp.push_back(c[i]);
        }
        result.push_back(temp);
        return;
    }
    bool ok = true;
    for(int i = 0; i < n; i++) {
        if(d[i] == 0) {
            if(i > 0 && nums[i] == nums[i - 1] && d[i - 1] == 1)
                continue;
            d[i] = 1;
            c[k] = nums[i];
            permute(k + 1, n, c, d, nums, result);
            c[k] = 0;
            d[i] = 0;
        }
    }
}

vector<vector<int> > permuteUnique(vector<int>& nums) {
    vector<vector<int> > result;
    vector<int> temp;
    int size = nums.size();
    if(size == 0)
        return result;
    sort(nums.begin(), nums.end());
    int size = nums.size();
    int c[size];
    int d[size];
    memset(c, 0, sizeof(c));
    memset(d, 0, sizeof(d));
//    permute(0, size, c,d, nums, result);
    perm(0, size, nums, result);
    return result;
}

int main() {
    vector<vector<int> > result;
    vector<int> tar;
    tar.push_back(3);
    tar.push_back(3);
   tar.push_back(0);
   tar.push_back(0);
   tar.push_back(2);
   tar.push_back(2);
   tar.push_back(3);
    result = permuteUnique(tar);
    for(int i = 0; i< result.size(); i++) {
        vector<int> ttt = result[i];
        for(int j = 0; j < ttt.size(); j++) {
            cout<<ttt[j]<<"\t";
        }
        cout<<endl;
    }
    return 0;
}
