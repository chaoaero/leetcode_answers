/*==================================================================
 *   Copyright (C) 2015 All rights reserved.
 *   
 *   filename:     integer_to_english_words.cc
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

string transformNumToWord(int num);

string numberToWords(int num) {
    vector<string> v = {""," Thousand", " Million", " Billion"};
    string result;
    if(num == 0)
        return "Zero";
    int residual =0;
    int index = 0;
    int prev_resi = 0;
    while(num != 0) {
        residual = num % 1000;
        num /= 1000;
        string temp  = transformNumToWord(residual);
        if(temp.size() != 0)
            temp.append(v[index]);
        if(temp.size() != 0) {
            if(prev_resi != 0 ) {
                temp.append(" ");
            }
            result = temp + result;
            prev_resi = residual;
        } else {
           result  = temp + result; 
        }
        index++;
    }
    return result;
}

string transformNumToWord(int num) {
    unordered_map<int, string> num_words = {{0, ""}, {1, "One"}, {2, "Two"}, {3, "Three"}, {4, "Four"}, {5, "Five"}, 
        {6, "Six"}, {7, "Seven"}, {8, "Eight"}, {9, "Nine"}, {10, "Ten"}, {11,"Eleven"},  
        {12, "Twelve"}, {13, "Thirteen"}, {14, "Fourteen"}, {15, "Fifteen"}, {16, "Sixteen"}, 
        {17, "Seventeen"}, {18, "Eighteen"}, {19,"Nineteen"} };
    vector<string> v2 = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};

    if(num < 20)
        return num_words[num];
    else {
        int temp = num / 100;
        int sec = (num - temp * 100) / 10;
        int last = num % 10;
        string result;
        if(temp >= 1)
            result.append(num_words[temp]).append(" Hundred");
        if(num  - temp * 100 < 20){
            if(num - temp * 100 != 0)
                result.append(" ");
            return result.append(num_words[num - temp * 100]);
        }
        if(sec != 0) {
            if(temp >= 1)
                result.append(" ");
            result.append(v2[sec]);
        }
        if(last != 0) {
            if(temp != 0 || sec != 0)
                result.append(" ");
            result.append(num_words[last]);
        }
        return result;
    }
}

int main() {
    int num;
    cin>>num;
    cout<<"========="<<endl;
    cout<<numberToWords(num)<<endl;
    return 0;
}
