/*==================================================================
 *   Copyright (C) 2015 All rights reserved.
 *   
 *   filename:     divide_two_integers.cc
 *   author:       Meng Weichao
 *   created:      2015/11/12
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
#include<cmath>

using namespace std;

int divide(int dividend, int divisor) {

    int result = 0;
    int k = 0;
    unsigned long my_divisor = abs(divisor);
    unsigned long my_dividend = abs(dividend);
    while(my_divisor < my_dividend && my_divisor < (LONG_MAX >> 1)) {
       my_divisor <<= 1; 
       k++;
    }
    my_divisor >>= 1;
    k--;

    for(int i=k; i >= 0; i--) {
        cout<<my_dividend<<"\t"<<my_divisor<<"\t"<<i<<endl;
        while(my_dividend - my_divisor >= 0) {
            cout<<my_dividend<<"\t"<<my_divisor<<endl;
            my_dividend -= my_divisor;
            result += 1<<i;
        }
        my_divisor >>= 1;
    }
    
    cout<<"==="<<endl;
    return (divisor ^ dividend) >> 31 ? -result : result;
}

int main() {
    int a,b;
    cin>>a>>b;
    cout<<divide(a,b)<<endl;
    return 0;
}


