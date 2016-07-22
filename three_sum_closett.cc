/*==================================================================
*   Copyright (C) 2016 All rights reserved.
*   
*   filename:     three_sum_closett.cc
*   author:       Meng Weichao
*   created:      2016/03/28
*   description:  
*
================================================================*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<stdlib.h>
#include<climits>
#include<stdint.h>
#include<queue>
using namespace std;
int three_sum_closett(vector<int>& nums, int target) {
    if(nums.size() == 0)
        return 0;
    sort(nums.begin(), nums.end());
    int j,k;
    int closest_result = nums[0] + nums[1] + nums[2];
    for(int i = 0; i< nums.size() - 1; i++) {
        cout<<nums[i]<<endl;
        j = i + 1, k = nums.size() - 1;
        while(j < k) {
            int temp = nums[j] + nums[k] + nums[i];
            if(abs(temp - target) < abs(closest_result - target))
                closest_result = temp;
            else if(temp <= target)
                j++; 
            else if(temp > target)
                k--;
        }
    }
    return closest_result;
}
int main() {
    //int nim[] = {-1, 0 ,1, 2, -1, -4};
    //int nim[] = {-2, -2, -1, -1,0, 1, 2,2,3, 3, 4, 5};
    int nim[] = {0, 2, 1 };
    vector<int> ko(nim, nim + sizeof(nim)/sizeof(int));
    cout<<three_sum_closett(ko, 3);
    cout<<endl;
    return 0;
}

