/*==================================================================
 *   Copyright (C) 2016 All rights reserved.
 *   
 *   filename:     longest_increasing_sequence.cc
 *   author:       Meng Weichao
 *   created:      2016/03/16
 *   description:  
 *
 ================================================================*/
#include<iostream>
#include<stdlib.h>
#include<algorithm>
#include<string>
#include<memory.h>
#include<vector>
using namespace std;

int lengthOfLIS(vector<int>& nums) {
    int size = nums.size();
    int c[size];
    memset(c, 0, sizeof(c));
    c[0] = 1;
    for(int i = 1; i < size ; i++) {
    //    cout<<nums[i]<<endl;
        int max = 1;
        for(int j = 0; j <= i - 1; j++) {
            if(nums[i] > nums[j]) {
                int temp = c[j] + 1;
                if(temp > max)
                    max = temp;
            }
        }
        c[i] = max;
    }
}

int main() {
    //int arr[] = {10, 9, 2, 5, 3, 7, 101, 18};
    int arr[] = {1,3,6,7,9,4,10,5,6};
    vector<int> aa(arr, arr + sizeof(arr) /  sizeof(int));
    cout<<lengthOfLIS(aa)<<endl;
    return 0;
}
