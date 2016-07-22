/*==================================================================
 *   Copyright (C) 2016 All rights reserved.
 *   
 *   filename:     subsets.cc
 *   author:       Meng Weichao
 *   created:      2016/03/30
 *   description:  
 *
 ================================================================*/
#include<iostream>
#include<string>
#include<vector>
#include<stdint.h>
#include <climits>
#include<stdlib.h>
#include<string.h>
#include <bitset>
#include<stack>
#include<cmath>
#include<cctype>
#include<cctype>
#include<set>

using namespace std;

void generate_result(int c[], int n,  int t, int k, vector<vector<int> >& result) {
    if(t >= k ) {
        vector<int> temp;
        for(int m = 0; m < k ;m++)
            temp.push_back(c[m]);
        result.push_back(temp);
        return;
    }
    bool ok ;
    for(int j = 1 ; j <= n ; j++ ) {
        ok = true;
        for(int i = 0; i < t; i++) {
            if(c[i] == j || j < c[i]) {
                ok = false;
                break;
            }

        }
        if(ok) {
            c[t] = j;
            generate_result(c, n, t + 1, k, result);
        }
    }
}

vector<vector<int> > combine(int n, int k) {
    int c[n];
    memset(c, 0, sizeof(c));
    vector<vector<int> > result;
    for(int i = 1; i<=n; i++) {
        c[0] = i;
        generate_result(c, n, 1, k, result);
    }
    return result;
}

void get_result(int k, int n,vector<int>& nums,  vector<int>& temp,  vector<vector<int> >& result) {
    if(k >=n ) {
        result.push_back(temp);
        return;
    }
    vector<int> ca(temp), ca2(temp);
    get_result(k + 1, n , nums,ca, result);
    ca2.push_back(nums[k]);
    get_result(k + 1, n ,nums, ca2, result);
}

vector<vector<int> > subsets(vector<int>& nums) {
    vector<vector<int> > result;
    vector<int> temp;
    int n = nums.size();
    sort(nums.begin(), nums.end());
    get_result(0, n, nums, temp, result );
    return result;
}

int main() {
    vector<vector<int> > result;
    vector<int> tar;
    tar.push_back(1);
    tar.push_back(2);
    tar.push_back(3);
    result = subsets(tar);
    cout<<"the size of res"<<result.size()<<endl;
    
        cout<<endl;
    }
    return 0;
    
}
