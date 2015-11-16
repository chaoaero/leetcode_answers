/*==================================================================
 *   Copyright (C) 2015 All rights reserved.
 *   
 *   filename:     contains_duplicate.cc
 *   author:       Meng Weichao
 *   created:      2015/11/16
 *   description:  
 *
 ================================================================*/
#include<iostream>
#include<string>
#include<vector>
#include<stdint.h>
#include <climits>
#include <bitset>
#include<unordered_map>

using namespace std;
bool containsDuplicate(vector<int>& nums) {
    int res = 0;
    if(nums.size() <=1)
        return false;
    int size = nums.size();
    unordered_map<int, int> num_map;
    for(int i = 0; i< size;i++) {
       if(num_map.find(nums[i]) == num_map.end()) 
           num_map[nums[i]] = 1;
       else
           return true;
    }
    return false;
}
