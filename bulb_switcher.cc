/*==================================================================
 *   Copyright (C) 2016 All rights reserved.
 *   
 *   filename:     bulb_switcher.cc
 *   author:       Meng Weichao
 *   created:      2016/02/16
 *   description:  
 *
 ================================================================*/
#include<iostream>
#include<stdlib.h>
using namespace std;

int bulbSwitch(int n) {
    // 因子分解 只有完全平方数有奇数个因子，所以灯亮，其余round偶数个因子，所以灭
    return sqrt(n);
}

int main() {

cout<<bulbSwitch(99999999)<<endl;
return 0;

}
