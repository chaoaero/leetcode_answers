/*==================================================================
 *   Copyright (C) 2016 All rights reserved.
 *   
 *   filename:     remove_duplicates_letters.cc
 *   author:       Meng Weichao
 *   created:      2016/02/17
 *   description:  
 *
 ================================================================*/
#include<iostream>
#include<string>
#include<vector>
#include<stdint.h>
#include <climits>
#include<algorithm>
#include<cctype>
#include<stack>

using namespace std;

string removeDuplicateLetters(string s) {
    int a[30];
    stack<char> stk, stk2;
    for(int i = 0; i< 30; i++)
        a[i] = 0;
    for(int i = 0; i< s.size(); i++) {
        a[s[i] - 'a'] += 1;
    }
    for(int i = 25; i >=0; i--) {
        int count = a[i];
        char temp = i + 'a';
        for(int j = 0; j < s.size(); j++) {
            if
        }

    }

}

int main() {
    return 0;
}
