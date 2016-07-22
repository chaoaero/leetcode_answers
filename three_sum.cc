/*==================================================================
 *   Copyright (C) 2016 All rights reserved.
 *   
 *   filename:     three_sum.cc
 *   author:       Meng Weichao
 *   created:      2016/03/25
 *   description:  
 *
 ================================================================*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
struct Node {
    int a;
    int b;
    int c;
};
typedef struct Node Node;

vector<vector<int> > threeSum(vector<int>& nums) {
    vector<vector<int> > result;
    if(nums.size() == 0)
        return result;
    sort(nums.begin(), nums.end());
    vector<int>::iterator iter;
    int i , j, k;
    for(i = 0; i < nums.size(); i++) {
        if( i > 0 && nums[i] == nums[i - 1])
            continue;
        int temp = 0 - nums[i];
        j = i + 1, k = nums.size() - 1;
        while(j < k) {
            if(nums[j] + nums[k] == temp) {
                vector<int> triple;
                triple.push_back(nums[i]);
                triple.push_back(nums[j]);
                triple.push_back(nums[k]);
                result.push_back(triple);
                while(j < k && nums[j] == nums[j + 1])
                    j++;
                while(j < k && nums[k] == nums[k - 1])
                    k--;
                j++;
                k--;
            }else if(nums[j] + nums[k] < temp)
                j++;
            else if(nums[j] + nums[k] > temp)
                k--;
        }

    }
    return result;

}

int main() {
    //int nim[] = {-1, 0 ,1, 2, -1, -4};
    //int nim[] = {-2, -2, -1, -1,0, 1, 2,2,3, 3, 4, 5};
    int nim[] = {-2, 0, 0, 2, 2};
    vector<int> ko(nim, nim + sizeof(nim)/sizeof(int));
    vector<vector<int> > result = threeSum(ko);
    for(int i = 0; i< result.size(); i++) {
        vector<int> ttt = result[i];
        for(int j = 0; j < ttt.size(); j++) {
            cout<<ttt[j]<<"\t";
        }
        cout<<endl;
    }
    return 0;
}

