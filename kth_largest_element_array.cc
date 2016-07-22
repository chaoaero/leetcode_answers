/*==================================================================
 *   Copyright (C) 2016 All rights reserved.
 *   
 *   filename:     kth_largest_element_array.cc
 *   author:       Meng Weichao
 *   created:      2016/07/11
 *   description:  
 *
 ================================================================*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void max_heapify(vector<int>& a, int start, int end) {
    int parent = start;
    int son = start * 2 + 1;
    while(son < end) {
        if(son + 1 < end && a[son] < a[son + 1])
            son++;
        if(a[parent] > a[son])
            return;
        swap(a[son],a[parent]);
        parent = son;
        son = parent * 2 + 1;
    }
}


int findKthLargest(vector<int>& nums, int k) {
    int n = nums.size();
    for(int i = n / 2 - 1; i>=0; i--)
        max_heapify(nums, i, n);
    for(int i = n - 1; i >= n - 1 - k + 1; i--) {
        if(i == n - 1 - k + 1)
            return nums[0];
        swap(nums[0], nums[i]);
        max_heapify(nums, 0, i);
    }
    return nums[0];
}

int main() {
    int arr[6] = {3,2,1,5,6,4};
    vector<int> aaa(arr, arr + sizeof(arr)/sizeof(int));
    int fff = findKthLargest(aaa, 2);
    cout<<fff<<endl;
    return 0;

}
