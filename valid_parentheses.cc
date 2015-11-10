/*==================================================================
 *   Copyright (C) 2015 All rights reserved.
 *   
 *   filename:     valid_parentheses.cc
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

bool isMatch(char s, char t) {
    if((s == '(' && t == ')') || (s == '[' && t == ']') || ( s == '{' && t == '}'))
        return true;
    return false;
}

bool isValid(string s) {
    int str_size = s.size();
    if(str_size % 2 != 0)
        return false;
    stack<char> stk;
    for(int i = 0; i< str_size ; i++) {
        cout<<s[i]<<endl;
        if(stk.empty())
            stk.push(s[i]);
        else {
            char t = stk.top();
            if(isMatch(t, s[i]))
                stk.pop();
            else
                stk.push(s[i]);
        }
    }
    if(stk.empty())
        return true;
    return false;

}

int main() {
    string s;
    cin>>s;
    cout<<isValid(s)<<endl;
    return 0;
}
