/*==================================================================
 *   Copyright (C) 2016 All rights reserved.
 *   
 *   filename:     h_index_2.cc
 *   author:       Meng Weichao
 *   created:      2016/07/21
 *   description:  
 *
 ================================================================*/
int hIndex(vector<int>& citations) {
    int size = citations.size();
    int left = 0, right = size - 1;
    while(left <= right) {
        int mid = left + (right - left ) / 2;
        if(citations[mid] >= size - mid ) 
            right = mid - 1;
        else
            left =  mid + 1;
            
    }
    return size - left;

}
