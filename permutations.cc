/*==================================================================
 *   Copyright (C) 2016 All rights reserved.
 *   
 *   filename:     permutations.cc
 *   author:       Meng Weichao
 *   created:      2016/02/18
 *   description:  
 *
 ================================================================*/
#include<iostream>
#include<string>
#include<vector>
#include<stdint.h>
#include <climits>
#include <bitset>
#include<stack>
#include<cmath>
#include<cctype>
#include<cctype>
#include<set>

using namespace std;

vector<vector<int> > permute(vector<int>& nums) {
    vector<vector<int> > result;
    vector<int> woca(nums);
    perm(woca, 0);
    return result;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void print() {
    for(int i = 1; i<= n; i++) {
        cout<<a[i]<<"\t";
    }
    cout<<endl; 
}

void perm(vector<int>& nums,int temp) {
    if(temp >= nums.size() - 1) {
    //    print(a, n);   
        result.push_back(nums);
        return;
    }
    perm(nums, temp + 1);
    for(int i = temp + 1; i < n; i++) {
        swap(&a[temp], &a[i]);
        perm(a, temp + 1, n);
        swap(&a[temp], &a[i]);
    }
}

int main() {
    int a[6] = {0,1,2,3,4};
    perm(a, 1, 3);
    return 0;
}
