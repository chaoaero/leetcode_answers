/*==================================================================
*   Copyright (C) 2015 All rights reserved.
*   
*   filename:     Palindrome_link_list.cc
*   author:       Meng Weichao
*   created:      2015/10/19
*   description:  
*
================================================================*/
#include<iostream>
using namespace std;
typedef struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
} ListNode;
class Solution {
    public:
        ListNode *detectCycle(ListNode *head) {
            ListNode *p = new ListNode(0);
            ListNode *q = new ListNode(0);
            ListNode *sta = new ListNode(0);
            ListNode *end = new ListNode(0);
            p = head;
            q = head;
            if(head == NULL)
                return NULL;
            while(q != NULL && p != NULL) {
                p = p->next;
                q = q->next;
                if(q == NULL) {
                    return NULL;
                }
                q = q->next;
                if(p == q) {
                    sta = p;
                    end = p->next;
                    break;
                }
            }
            return getIntersectionNode(head, end, sta);
        }
        int length(ListNode *head, ListNode *target) {
            int count = 0;
            ListNode *p = head;
            while(p != target) {
                count++;
                p = p->next;
                if(p == NULL )
                    return -1;
            }
            return count;
        }

        ListNode *getIntersectionNode(ListNode *headA, ListNode *headB, ListNode *target ) {
            int lena = length(headA, target);
            int lenb = length(headB, target);
            ListNode *p = headA;
            ListNode *q = headB;
            int count = 0;
            int diff = 0;
            if(lena > lenb ) {
                diff = lena - lenb;
                while(p != NULL && count < diff) {
                    count++;
                    p = p->next;
                }
            } else if(lena < lenb) {
                diff = lenb - lena;
                while(q != NULL && count < diff) {
                    count++;
                    q = q->next;
                }
            }
            while(p != NULL && q != NULL) {
                if(p == q)
                    return p;
                p = p->next;
                q = q->next;
            }
            return NULL;
        }
        
};
