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
#include<unordered_map>

using namespace std;


enum my_operator { o_plus, o_minus, o_left_p, o_right_p , o_equal};

int get_operator(char c) {
    switch(c) {
        case '+':
            return o_plus;
            break;
        case '-':
            return o_minus;
            break;
        case '(':
            return o_left_p;
            break;
        case ')':
            return o_right_p;
            break;
        case '=':
            return o_equal;
            break;
    };    
}

int cmp_mat[5][5] = { {1, 1, 0, 1, 1},
                {1, 1, 0, 1, 1},
                {1, 1, 0, 1, 1},
                {0, 0, 0, 0, 1},};

int get_value(int a, int b, char c) {
    switch(c) {
        case '+':
            return a + b;
            break;
        case '-':
            return a - b;
            break;
    };
}

int calculate(string s) {
    int len = s.size();
    int i,j;
    if(len == 0)
        return 0;
    if(len == 1 && isdigit(s[0]))
        return s[0] - '0';
    char op_arr[5] = {'+', '-', '(', ')', '='};
    set<char> op(op_arr, op_arr + 5);;
    stack<int> operand;
    stack<char> oper;
    int num = 0;
    s += '=';
    for(i = 0, j = 1; i < s.size() - 1; i++, j++) {
        char c = s[i];
        char next_c = s[j];
        if(isspace(c))
            continue;
        if(isdigit(c)) {
            num = num * 10 + c - '0';
            if(!isdigit(next_c)) {
                operand.push(num);
                num = 0;
            }
            continue;
        }
        if(op.find(c) != op.end()) {
            if(oper.empty())
                oper.push(c);
            else {
                char prev_op = oper.top();
                if(cmp_mat[get_operator(prev_op)][get_operator(c)]) {
                    int latter = operand.top();
                    operand.pop();
                    int former = operand.top();
                    operand.pop();
                    oper.pop();
                    if(!oper.empty() && oper.top() == '(' && c == ')')
                        oper.pop();
                    else
                        oper.push(c);
                    operand.push(get_value(former, latter, c));
                } else {
                    oper.push(c);
                }

            }

        }
    }

    return oper.top();
}

int main() {
    string express;
    cin>>express;
    cout<<"========================="<<endl;
    cout<<calculate(express)<<endl;
    return 0;
}
