/*==================================================================
 *   Copyright (C) 2016 All rights reserved.
 *   
 *   filename:     wiggle_sort.cc
 *   author:       Meng Weichao
 *   created:      2016/07/08
 *   description:  
 *
 ================================================================*/

#include<vector>
#include<algorithm>
#include<iostream>
#include<map>
using namespace std;
class Solution {
public:
    class Com { 
    public:
        bool operator()(const pair<int, int>& m, const pair<int, int>& n) {
            return m.second > n.second;
        }   
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> num_count;
        for(int i = 0; i < nums.size(); i++) {
            num_count[nums[i]]++;
        }   
        vector<pair<int, int> >vec(num_count.begin(), num_count.end() );
        Com oo;
        sort(vec.begin(), vec.end(), oo);
        vector<int> res;
        for(int i = 0; i< vec.size(); i++) {
            cout<<vec[i].first<<"\t"<<vec[i].second<<endl;
            res.push_back(vec[i].first);
        }   
        return res;
    }
};
int main() {
    Solution sol;
    //int mm[6] = {1,1,1,2,2,3};
    int mm[7] = {4, 1, -1, 2, -1, 2,3};
    //int mm[1] = {1};
    vector<int> inp(mm, mm + sizeof(mm)/sizeof(int));
    vector<int> result ;
    result = sol.topKFrequent(inp, 2);
    for(int i = 0; i< result.size(); i++) {
        cout<<result[i]<<"\t";
    }
    cout<<endl;
    return 0;

}
