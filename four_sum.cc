/*==================================================================
 *   Copyright (C) 2016 All rights reserved.
 *   
 *   filename:     four_sum.cc
 *   author:       Meng Weichao
 *   created:      2016/03/29
 *   description:  
 *
 ================================================================*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<queue>
using namespace std;
vector<vector<int> > fourSum(vector<int>& nums, int target) {
    vector<vector<int> > result;
    if(nums.size() == 0)
        return result;
    sort(nums.begin(), nums.end());
    vector<int>::iterator iter;
    int size = nums.size();
    int i , j, k;
    for(i = 0; i < size; i++) {
        if( i > 0 && nums[i] == nums[i - 1]) 
            continue;
        for(int j = i + 1; j < size ; j++) {
            for(int k = j + 1; k < size; k++) {
                for(int jj = k + 1; jj < size; jj++) {
                    int temp = nums[i] + nums[j] + nums[jj] + nums[k]; 
                    if(temp == target) {
                        if(!result.empty()) {
                            vector<int> ca = result.back();
                            if(nums[i] == ca[0] && nums[j] == ca[1] && nums[k] == ca[2] && nums[jj] == ca[3])
                                continue;
                        }
                        vector<int> triple;
                        triple.push_back(nums[i]);
                        triple.push_back(nums[j]);
                        triple.push_back(nums[k]);
                        triple.push_back(nums[jj]);
                        result.push_back(triple);
                    }
                }
            } 
        }

    }
    return result;
}

vector<vector<int> > fourSum2(vector<int>& nums, int target) {
    vector<vector<int> > result;
    if(nums.size() == 0)
        return result;
    sort(nums.begin(), nums.end());
    vector<int>::iterator iter;
    map<vector<int>, bool> hash;
    int size = nums.size();
    int i , j, k;
    for(i = 0; i < size; i++) {
        if( i > 0 && nums[i] == nums[i - 1]) 
            continue;
        for(j = i + 1; j < size; j++) {
            int k = j + 1, m = size - 1;
            while( k < m) {
                int temp = nums[i] + nums[j] + nums[k] + nums[m]; 
                if(temp == target) {
                    vector<int> triple;
                    triple.push_back(nums[i]);
                    triple.push_back(nums[j]);
                    triple.push_back(nums[k]);
                    triple.push_back(nums[m]);
                    if(hash.count(triple) > 0) {
                        k++;
                        continue;
                    }
                    result.push_back(triple); 
                    hash[triple] = true;
                    while(k < m && nums[k] == nums[k + 1])
                        k++;
                    while(k < m && nums[m] == nums[m - 1])
                        m--;
                    k++;
                } else if(temp  < target)
                    k++;
                else if(temp > target )
                    m--;
            }
        }
    }
return result;
}
int main() {
    //int nim[] = {-1, 0 ,1, 2, -1, -4};
    //int nim[] = {-2, -2, -1, -1,0, 1, 2,2,3, 3, 4, 5};
    //int nim[] = {-2, -2, 0, 0, -1, 1,2, 2};
    int nim[] = {-497,-481,-481,-472,-471,-465,-422,-420,-413,-405,-388,-381,-366,-361,-359,-348,-334,-334,-318,-310,-305,-280,-273,-272,-262,-254,-248,-223,-208,-202,-196,-192,-189,-167,-165,-165,-156,-143,-136,-122,-120,-120,-108,-77,-50,-44,-34,-26,-17,-5,13,46,46,53,54,56,66,71,72,75,89,115,130,139,149,151,154,196,209,219,230,240,245,246,253,267,277,289,299,302,303,304,342,349,360,361,361,375,392,400,407,408,408,426,427,429,443,451,481};
    vector<int> ko(nim, nim + sizeof(nim)/sizeof(int));
    vector<vector<int> > result = fourSum2(ko, 0);
    for(int i = 0; i< result.size(); i++) {
        vector<int> ttt = result[i];
        for(int j = 0; j < ttt.size(); j++) {
            cout<<ttt[j]<<"\t";
        }
        cout<<endl;
    }
    return 0;
}

