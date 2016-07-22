/*==================================================================
 *   Copyright (C) 2015 All rights reserved.
 *   
 *   filename:     basic_calculator.cc
 *   author:       Meng Weichao
 *   created:      2015/11/19
 *   description:  
 *
 ================================================================*/
#include<iostream>
#include<string>
#include<vector>
#include<stdint.h>
#include <climits>
#include <bitset>
#include<stack>
#include<cmath>
#include<cctype>
#include<cctype>
#include<set>

using namespace std;

int calculate(string s) {
    stack<int> oprd;
    stack<int> op;
    int res = 0;
    int sum = 0;
    int sign = 1;
    int i = 0;
    int size = s.size();
    while(i < size) {
        if(isdigit(s[i])) {
            sum = sum * 10 + s[i] - '0';
        } else {
            res += sign * sum;
            sum = 0;
            if(s[i] == '+') {
                sign = 1;
            } else if(s[i] == '-') {
                sign = -1;
            } else if(s[i] == '(') {
                oprd.push(res);
                op.push(sign);
                res = 0;
                sign = 1;
            } else if(s[i] == ')') {
                int  ss = op.top();
                op.pop();
                int tt = oprd.top();
                oprd.pop();
                res = res * ss + tt;
            }
        }
        i++;
    }
    res += sum * sign;
    return res;
}

int calculate_2(string s) {
    int total = 0;
    int sum = 0;
    int sign = 1;
    char prev_op = '+';
    int prev_res = 0;
    int i = 0, size = s.size();
    do {
        if(isdigit(s[i])) {
            sum = sum * 10 + s[i] - '0';
        } else {
            char op = s[i];
            if(prev_op == '+') {
                total += prev_res ;
                prev_res = sum ;
            } else if(prev_op == '-') {
                total += prev_res;
                prev_res = -1 * sum ;
            } else if(prev_op == '*') {
                prev_res *= sum; 
            } else if(prev_op == '/') {
                prev_res /= sum;
            }
            sum = 0;
            prev_op = op;
        }
        i++;
    } while(i < size);
    if(prev_op == '+') {
        total += prev_res ;
        prev_res = sum ;
    } else if(prev_op == '-') {
        total += prev_res;
        prev_res = -1 * sum ;
    } else if(prev_op == '*') {
        prev_res *= sum; 
    } else if(prev_op == '/') {
        prev_res /= sum;
    }
    total +=  prev_res;
    return total;
}

int main() {
    string express;
    cin>>express;
    cout<<"========================="<<endl;
    cout<<calculate_2(express)<<endl;
    return 0;
}
