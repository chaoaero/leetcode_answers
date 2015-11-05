/*==================================================================
 *   Copyright (C) 2015 All rights reserved.
 *   
 *   filename:     add_binary.cc
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
#include<algorithm>

using namespace std;

string addBinary(string a, string b) {
    string c(a);
    string d(b);
    reverse(c.begin(), c.end());
    reverse(d.begin(), d.end());
    int len = (a.size() > b.size() ? b.size() : a.size());
    int carry = 0;
    string result("");
    for(int i = 0;i< len ; i++) {
        char temp = c[i] - '0' + d[i] - '0' + carry;
        carry = temp / 2;
        result.push_back(temp % 2 + '0'); 
    }
    if(c.size() > d.size()) {
        for(int i = d.size(); i< c.size(); i++) {
            char temp = c[i] - '0' +  carry;
            carry = temp / 2;
            result.push_back(temp % 2 + '0');    
        }
    } else if (c.size() < d.size()) {
        for(int i = c.size(); i< d.size(); i++) {
            char temp = d[i] - '0' +  carry;
            carry = temp / 2;
            result.push_back(temp % 2 + '0');    
        }
    }
    if(carry == 1)
        result += "1";
    reverse(result.begin(), result.end());
    return result;
}

int main() {
    vector<string> woca;
    string temp;
    string nimei;
        cin>>temp;
        cin>>nimei;

    cout<<addBinary(temp, nimei);

    return 0;
}
