/*==================================================================
 *   Copyright (C) 2015 All rights reserved.
 *   
 *   filename:     valid_palindrome.cc
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
#include<cctype>
#include<stack>

using namespace std;

bool isPalindrome(string s) {
    string temp;
    for(int i =0;i< s.size(); i++) {
        if(isalpha(s[i]) || isdigit(s[i])) {
            temp.push_back(tolower(s[i]));
        }
        
    }
    int i = 0, j = temp.size() - 1;
    for(i =0, j = temp.size() -1; i<=j; i++, j--) {
        if(temp[i] != temp[j])
            return false;
    }
    return true;
}

int main()  {
    string w("fwef fwewe ,,fwfw,,fwef,,few");
    isPalindrome(w);
    return 0;
}
