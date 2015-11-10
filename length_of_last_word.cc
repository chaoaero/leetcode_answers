/*==================================================================
 *   Copyright (C) 2015 All rights reserved.
 *   
 *   filename:     length_of_last_word.cc
 *   author:       Meng Weichao
 *   created:      2015/11/10
 *   description:  
 *
 ================================================================*/
#include<iostream>
#include<string>
#include<vector>
#include<stdint.h>
#include <climits>
#include<algorithm>
#include<stack>

using namespace std;

int lengthOfLastWord(string s) {
    int i = 0, j = 0;
    vector<string> woca;
    while(i < s.size()) {
        if(s[i] != ' ') {
            j = i;
            while(s[j] != ' ' && j < s.size() ) 
                j++;
            woca.push_back(s.substr(i, j - i));
            i = j -1;
        } 
        i++;
    }
    if(woca.size() == 0)
        return 0;
    return woca.back().size();
}
int main() {
    string m("     a    ");
    cout<<lengthOfLastWord(m)<<endl;
    return 0;
}
