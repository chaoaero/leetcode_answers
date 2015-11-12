/*==================================================================
 *   Copyright (C) 2015 All rights reserved.
 *   
 *   filename:     multiply_strings.cc
 *   author:       Meng Weichao
 *   created:      2015/11/11
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

vector<int> str2int(string num) {
    vector<int> result;
    for(int i = num.size() - 1; i>=0; i--)
        result.push_back(num[i] - '0');
    return result;
}

string multiply(string num1, string num2) {

    vector<int> v_num1 = str2int(num1);
    vector<int> v_num2 = str2int(num2);
    int len = num1.size() + num2.size();
    vector<int> result(len, 0);
    int i,j;
    for(i = 0; i< v_num1.size(); i++) {
        for(j = 0; j< v_num2.size() ; j++) {
            result[i + j] += v_num2[j] * v_num1[i];
            if(result[i + j] >= 10) {
                result[i + j + 1] += result[i + j] / 10;
                result[i + j] %= 10;
            }
        }
    }
     
    string str_res;
    int k = 0;
    bool flag = false;
    // this should be len -1 for skipping leading zeros. len would be wrong answer
    for(i = len -1; i>=0; i--) {
        if(result[i] != 0){
            k = i;
            flag = true;
            break;
        }
    }
    if(flag == false)
        return "0";
    for(j = k; j>= 0;j--) {
        char m = result[j] + '0';
        str_res += m;
    }
    return str_res;
}

int main() {
    
    string m,n;
    cin>>m>>n;
    vector<int> sss = str2int(m);
    for(vector<int>::const_iterator iter = sss.begin(); iter != sss.end(); iter++) {
        cout<<*iter<<endl;
    }
    cout<<"=========="<<endl;
    cout<<multiply(m,n)<<endl;

    return 0;
}
