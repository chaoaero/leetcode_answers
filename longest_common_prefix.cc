/*==================================================================
 *   Copyright (C) 2015 All rights reserved.
 *   
 *   filename:     longest_common_prefix.cc
 *   author:       Meng Weichao
 *   created:      2015/11/05
 *   description:  
 *
 ================================================================*/
#include<iostream>
#include<string>
#include<vector>
#include<stdint.h>
#include <climits>

using namespace std;
string longestCommonPrefix(vector<string>& strs) {
    if(strs.size() == 0)
        return "";
    else if(strs.size() == 1)
        return strs[0];
    int min = INT_MAX;
    string target;
    for(vector<string>::const_iterator iter = strs.begin() ; iter != strs.end(); iter++){
        if((*iter).size() < min) {
            min = (*iter).size();
            target = *iter;
        }
    }

    string result("");
    bool flag = true;
    for(int i =0;i < target.size(); i++) {
        char s = target[i];
        for(int j = 0; j < strs.size(); j++) {
            if(strs[j][i] != s) {
                flag = false;
                break;
            }
        }
        if(flag == false) {
            break;
        }
        result += s;
    }

    return result;
}

int main() {
    vector<string> woca;
    string temp;
    for(int i=0;i<2;i++){
        cin>>temp;
        woca.push_back(temp);

    }
    cout<<longestCommonPrefix(woca);

    return 0;
}
