/*==================================================================
 *   Copyright (C) 2015 All rights reserved.
 *   
 *   filename:     longest_palindromic_substring.cc
 *   author:       Meng Weichao
 *   created:      2015/11/13
 *   description:  longest common substring 
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

bool isPalindrome(string s, int start, int end) {
    int i = start, j = end;
    while(start < end) {
       if(s[start] == s[end]) {
            start++;
            end--;
       } else
           return false;
    }
    return true;
}

string longestPalindrome(string s) {
    int len = s.size();
    if(len == 0)
        return "";
    string reverse_s;
    reverse_s.assign(s.rbegin(), s.rend());
    int a[len+1][len+1];
    memset(a, 0, sizeof(a));
    int i,j;
    int max = 0;
    int start , end;
    for(i = 0; i < len; i ++) {
        for(j = 0 ; j < len ; j++) {
            if(i == 0|| j == 0) {
                if(s[i] == reverse_s[j]) {
                    a[i][j] = 1;
                    if(a[i][j] > max ) {
                        start = i;
                        max = a[i][j];
                    }
                } else
                    a[i][j] = 0;
            } else {
                if(s[i] == reverse_s[j]) {
                    a[i][j] = a[i-1][j-1] + 1;
                    if(a[i][j] > max  && isPalindrome(s, i + 1 - a[i][j] , i)) {
                        start  = i + 1 - a[i][j];
                        max = a[i][j];
                        //cout<<s.substr(i + 1 - a[i][j], a[i][j])<<endl;
                    }
                } else {
                    a[i][j] = 0;
                }
            }
        }
    }
    return s.substr(start, max);
}

string another_palidrom(string s) {
    if(s.size() <= 1)
        return s;
    int len = s.size(), i,j , start, end;
    bool flag[len][len];
    for(i = 0; i< len; i++) {
        for(j = 0; j< len; j++) {
            if(i >= j) 
                flag[i][j] = true;
            else
                flag[i][j] = false;
        }
    }
    int max = 0;
    for(i = 1; i< len; i++) {
        for(j  = 0; j< i ; j++) {
            if(s[i] == s[j]) {
                flag[j][i] = flag[j + 1][i-1];
                if(flag[j][i] && i - j + 1 > max) {
                    start = j;
                    end = i;
                    max = i - j +1;
                }
            } else
                flag[j][i] = false;
        }
    }
    return s.substr(start, max);
}

int main() {

    string s;
    string m;
    cin>>s;
    cout<<another_palidrom(s)<<endl;
    return 0;
}
