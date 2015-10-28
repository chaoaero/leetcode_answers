/*==================================================================
 *   Copyright (C) 2015 All rights reserved.
 *   
 *   filename:     intersection_two_lists.cc
 *   author:       Meng Weichao
 *   created:      2015/10/16
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
        ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
            int lena = length(headA);
            int lenb = length(headB);
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
        int length(ListNode *head) {
            int count = 0;
            ListNode *p = head;
            while(p != NULL) {
                count++;
                p = p->next;
            }
            return count;
        }

};

int main() {

    
}
