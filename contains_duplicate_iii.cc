/*==================================================================
 *   Copyright (C) 2015 All rights reserved.
 *   
 *   filename:     contains_duplicate_iii.cc
 *   author:       Meng Weichao
 *   created:      2015/11/17
 *   description:  
 *
 ================================================================*/
#include<iostream>
#include<string>
#include<vector>
#include<stdint.h>
#include <climits>
#include <bitset>
#include<set>
#include<cmath>

using namespace std;
bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
    if(nums.size() <= 1|| k < 0 || t < 0)
        return false;
    int i,j;
    multiset<int> num_set;
    multiset<int>::iterator iter, iter_low, iter_up;
    for(i = 0; i< nums.size(); i++) {
        if(num_set.size() == k + 1)  
            num_set.erase(num_set.find(nums[i - k - 1])); 
        int temp = nums[i];
        iter_low = num_set.lower_bound(temp);
        iter_up = num_set.upper_bound(temp);
        if(iter_low != num_set.end() && abs( temp - *iter_low ) <= t)
            return true;
        if(iter_up != num_set.begin() && abs(temp - *(--iter_up))<= t)
            return true;
        num_set.insert(nums[i]);
    }   
    return false;
}

    bool ffcontainsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
   multiset<long long> bst;
        for (int i = 0; i < nums.size(); ++i) {
            if (bst.size() == k + 1) bst.erase(bst.find(nums[i - k - 1]));
            auto lb = bst.lower_bound(nums[i]);
            if (lb != bst.end() && abs(*lb - nums[i]) <= t) return true;
            auto ub = bst.upper_bound(nums[i]);
            if (ub != bst.begin() && abs(*(--ub) - nums[i]) <= t) return true;
            bst.insert(nums[i]);
        }
        return false;
    }

int main() {
    vector<int> num;
    num.push_back(-3);
    num.push_back(3);
    std::set<int> myset;
    std::set<int>::iterator itlow,itup;
    cout<<"================"<<endl;
    cout<<containsNearbyAlmostDuplicate(num, 2, 4)<<endl;
    return 0;
}
