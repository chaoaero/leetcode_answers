/*==================================================================
 *   Copyright (C) 2015 All rights reserved.
 *   
 *   filename:     longest_substring_without_repeating_letters.cc
 *   author:       Meng Weichao
 *   created:      2015/11/13
 *   description:  
 *
 ================================================================*/
#include<iostream>
#include<string>
#include<vector>
#include<stdint.h>
#include <climits>
#include<algorithm>
#include <unordered_map>

using namespace std;

int lengthOfLongestSubstring(string s) {
    if(s.empty())
        return 0;
    int i = 0,j = 0;
    int max = 0;
    int sub_len = 0;
    unordered_map<char, int> alpha_map;
    while( i < s.size()) {
        if(alpha_map.find(s[i]) == alpha_map.end()) {
            alpha_map[s[i]] = i;
            sub_len += 1;
            if(sub_len > max)
                max = sub_len;
        } else {
            int index = alpha_map[s[i]];
            alpha_map[s[i]] = i;
            if(index < j) {
                sub_len += 1;
                if(sub_len > max )
                    max = sub_len;
            } else {
                j = index + 1;
                sub_len = i - j + 1;    
            }
        }
        i++;
    }
    
    return max;
}

int main() {
    string s;
    cin>>s;
    cout<<lengthOfLongestSubstring(s)<<endl;
    return 0;
}
