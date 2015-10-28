/*==================================================================
 *   Copyright (C) 2015 All rights reserved.
 *   
 *   filename:     sort_list.cc
 *   author:       Meng Weichao
 *   created:      2015/10/19
 *   description:  
 *
 ================================================================*/
#include<iostream>
#include<climits>
using namespace std;
typedef struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
} ListNode;

class Solution {
    public:
        ListNode* insertionSortList(ListNode* head) {
            if(head == NULL || head->next == NULL)
                return head;
            ListNode *virt_head = new ListNode(INT_MIN);
            ListNode *pre = virt_head;
            ListNode *cur = head, *next;
            while(cur) {
                next = cur->next; 
                pre = virt_head;
                while(pre->next != NULL && pre->next->val <= cur->val ) 
                    pre = pre->next;
                cur->next = pre->next;
                pre->next = cur;
                cur = next;
            }
            return virt_head->next;

        }
};


