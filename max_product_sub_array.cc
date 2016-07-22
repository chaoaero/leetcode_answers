/*==================================================================
 *   Copyright (C) 2016 All rights reserved.
 *   
 *   filename:     max_product_sub_array.cc
 *   author:       Meng Weichao
 *   created:      2016/02/14
 *   description:  
 *
 ================================================================*/
#include<iostream>
#include<vector>
#include <algorithm> 
#include<limits.h>
using namespace std;

int maxProduct(vector<int>& nums) {
    int max = INT_MIN;
    int pos = 1;
    int neg = 1;
    int size = nums.size();
    for(int i = 0; i< size; i++) {
        int temp_pos = pos * nums[i];
        int temp_neg = neg * nums[i];
        pos = std::max(temp_neg, temp_pos);
        neg = std::min(temp_pos, temp_neg);
        if(pos > max)
            max = pos;
        if(pos < 1)
            pos = 1;
    }
    return max;
}

int main() {
   const int arr[5] = {2, -5, -2, -4 ,3};
   vector<int> vec(arr, arr + sizeof(arr)/ sizeof(arr[0])); 
   cout<<maxProduct(vec)<<endl;
   return 0;
}
