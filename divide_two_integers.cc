/*==================================================================
 *   Copyright (C) 2015 All rights reserved.
 *   
 *   filename:     divide_two_integers.cc
 *   author:       Meng Weichao
 *   created:      2015/11/12
 *   description:  
 *
 ================================================================*/
//http://blog.csdn.net/wongson/article/details/8036219
#include<iostream>
#include<string>
#include<vector>
#include<stdint.h>
#include <climits>
#include<algorithm>
#include <unordered_map>
#include<cmath>

using namespace std;

// 需要考察计算机补码的相关知识，补码运算，整溢出，负溢出
// INT_MIN - 1 = INT_MAX
int divide(int dividend, int divisor) {

    int result = 0;
    int k = 0;
    int  my_divisor = abs(divisor);
    int my_dividend = abs(dividend);
    if(my_divisor == INT_MIN ) {
        return my_dividend == INT_MIN ? 1:0;
    }
    if(my_dividend == INT_MIN) {
        result += 1;
        my_dividend = INT_MAX  - my_divisor + 1;
    }
    int ff = 0;
    while((my_divisor <<1) < my_dividend && my_divisor << 1 > 0) {
        //        cout<<my_divisor<<"\t"<<my_dividend<<"\t"<<ff++<<endl;
        my_divisor <<= 1;
        k++;
    }

    for(int i=k; i >= 0; i--) {
        while(my_dividend - my_divisor >= 0) {
            my_dividend -= my_divisor;
            result += 1<<i;
        }
        my_divisor >>= 1;
    }


    int flag = (divisor ^ dividend) >>31;
    if(!flag && (result == INT_MIN))
        return INT_MAX;
    return flag ? -result : result;
}

int main() {
    int a,b;
    cin>>a>>b;
    cout<<divide(a,b)<<endl;
    return 0;
}


