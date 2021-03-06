/*==================================================================
*   Copyright (C) 2015 All rights reserved.
*   
*   filename:     contains_duplicate_II.cc
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
bool containsNearbyDuplicate(vector<int>& nums, int k) {
    int res = 0;
    if(nums.size() <=1)
        return false;
    int size = nums.size();
    unordered_map<int, int> num_map;
    for(int i = 0; i< size;i++) {
        if(num_map.find(nums[i]) == num_map.end()) 
            num_map[nums[i]] = i;
        else {
            if(i - num_map[nums[i]] <=k)
                return true;
            else {
                num_map[nums[i]] = i;
            }
        }
    }
    return false;
}
