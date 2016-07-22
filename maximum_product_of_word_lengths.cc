/*==================================================================
*   Copyright (C) 2016 All rights reserved.
*   
*   filename:     maximum_product_of_word_lengths.cc
*   author:       Meng Weichao
*   created:      2016/02/16
*   description:  
*
================================================================*/
#include<iostream>
#include<vector>
#include<string>
using namespace std;
int maxProduct(vector<string>& words) {
        vector<int> words_bit(words.size(), 0);
        for(int i = 0; i< words.size(); i++) {
            for(int j = 0; j < words[i].size(); j++)
            {
                words_bit[i] |= 1<<(words[i][j] - 'a');
            }
             
        }
        
        int max = -1;
        for(int i = 0; i < words.size(); i++) {
            for(int j = i + 1; j < words.size(); j++) {
                if(words_bit[i] & words_bit[j] == 0) {
                    int len = words[i].size() * words[j].size();
                    if(len > max)
                        max = len;
                }

            }
        }
        
        return max;
    }
int main() {
    return 0;
}
