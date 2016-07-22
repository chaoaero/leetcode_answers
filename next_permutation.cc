/*==================================================================
*   Copyright (C) 2016 All rights reserved.
*   
*   filename:     next_permutation.cc
*   author:       Meng Weichao
*   created:      2016/04/01
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
void permute(int k, int n, int c[], int d[], vector<int>& temp,vector<int>& nums, bool* ok, bool* stop) {
    if(k >= n) {
        if(*ok == true) {
            for(int i = 0; i< n; i++) {
                nums[i] = c[i];
            }
            *stop = true;
            return;
        }
        bool equal = true;
        for(int i = 0; i< n; i++) {
            if(c[i] != nums[i]) {
                equal = false;
                break;
            }
        }
        if(equal) {
            *ok = true;
        }
        return;
    }
    for(int i = 0; i < n; i++) {
        if(d[i] == 0) {
            if(i > 0 && temp[i] == temp[i - 1] && d[i - 1] == 1)
                continue;
            d[i] = 1;
            c[k] = temp[i];
            if(*stop == true)
                return;
            permute(k + 1, n, c, d,temp, nums, ok, stop);
            c[k] = 0;
            d[i] = 0;
        }
    }
}

void nextPermutation(vector<int>& nums) {
    if(nums.size() <= 1)
        return;
    vector<int> temp(nums);
    sort(temp.begin(), temp.end());
    bool ok = true;
    for(int i = 0; i < nums.size() - 1; i++) {
        if(nums[i] < nums[i + 1]) {
            ok = false;
            break;
        }
    }
    if(ok) {
        nums = temp;
        return;
    }
    int size = nums.size();
    int c[size];
    int d[size];
    memset(c, 0, sizeof(c));
    memset(d, 0, sizeof(d));
    ok = false;
    bool stop = false;
    permute(0, size, c,d, temp, nums, &ok, &stop);
}

void ccnextPermutation(vector<int>& nums) {
    if(nums.size() <= 1)
        return;
    int size = nums.size();
    int j,k,i;
    for(int i = size - 1; i >= 1; i--) {
       if(nums[i] > nums[i - 1]) {
            j = i - 1;
            break;
       } 
    }
    if(i == 0) {
        sort(nums.begin(), nums.end());
        return;
    }
    for(int i = size - 1; i >=0; i--) {
        if(nums[i] > nums[j]) {
            k = i;
            break;
        }
    }
    int temp = nums[j];
    nums[j] = nums[k];
    nums[k] = temp; 
    sort(nums.begin() +  j + 1, nums.end());
}

int main() {
    //int arr[] = {6,7,5,3,5,6,2,9,1,2,7,0,9};
    int arr[] = {1,2};
    //int arr[] = {3,2,1,5};
    vector<int> tar(arr, arr + sizeof(arr)/sizeof(int));
    ccnextPermutation(tar);
    for(int i = 0; i < tar.size(); i++) {
        cout<<tar[i]<<"\t";
    }
    cout<<endl;
    return 0;
}
