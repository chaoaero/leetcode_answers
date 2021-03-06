/*==================================================================
 *   Copyright (C) 2015 All rights reserved.
 *   
 *   filename:     implement_strstr.cc
 *   author:       Meng Weichao
 *   created:      2015/11/05
 *   description: KMP algorithm  ,   http://www.matrix67.com/blog/archives/115
 *
 ================================================================*/
#include<iostream>
#include<string>
#include<vector>
#include<stdint.h>
#include <climits>
#include<algorithm>

using namespace std;

int strStr(string haystack, string needle) {
    if( needle.size() == 0)
        return 0;
    int pattern_len = needle.size();
    int *next = (int *)malloc(pattern_len * sizeof(int));
    int j = -1;
    int i = 0;
    next[0] = j;
    for(i=1;i<pattern_len; i++) {
        while( j > -1  && (needle[j + 1] != needle[i]))
            j = next[j];
        if(needle[j + 1] == needle[i])
            j++;
        next[i] = j;
    }

    j = -1;
    int str_len = haystack.size();
    for(i =0; i< str_len; i++) {
        while(j > -1 && (needle[j + 1] != haystack[i]))
            j = next[j];
        if(needle[j + 1] == haystack[i])
            j++;
        if(j == pattern_len - 1) {
            delete[] next;
            return i - j;
        }
    }

    delete[] next;
    return -1;
}

// Sunday algorithm

int SundaystrStr(string haystack, string needle) {
    
    int occ[500];
    int p_size = needle.size();
    for(int i = 0;i < 500; i++) {
        occ[i] = p_size + 1;
    }
    for(int j = 0; j< needle.size(); j++) {
        occ[needle[j]] = p_size - j;
    }
    int str_len = haystack.size();
    int i = 0;
    bool match = false;
    int pos = -1;
    while(i <= str_len - p_size) {
        int m = p_size - 1;
        while(m >= 0 && (haystack[i + m] == needle[m]))
            m--;
        if(m < 0) {
            match = true;
            pos = i;
            break;
        }
        i += occ[haystack[i + p_size]];
    }
    return pos;

}

int main() {

    string target, pattern;
    cin>>target>>pattern;
    cout<<target<<"\t"<<pattern<<endl;
    cout<<SundaystrStr(target, pattern)<<endl;
    return 0;
}
