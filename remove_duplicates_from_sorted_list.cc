/*==================================================================
 *   Copyright (C) 2015 All rights reserved.
 *   
 *   filename:     remove_duplicates_from_sorted_list.cc
 *   author:       Meng Weichao
 *   created:      2015/10/20
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
        ListNode* deleteDuplicates(ListNode* head) {
            if(head == NULL || head->next == NULL)
                return head;
            ListNode *p, *q;
            p  = head;
            q = head->next;
            while(q != NULL) {
                if(p->val == q->val) {
                    if(q->next == NULL) {
                        p->next = NULL;
                        delete q;
                        return head;
                    } else {
                        deleteNode(q);                        
                        q = p->next;
                    }
                } else {
                    p = q;
                    q = q->next;
                }
            }
            return head;

        }
        void deleteNode(ListNode* node) {
            ListNode *p = node->next;
            node->val = node->next->val;
            node->next = node->next->next;
            delete p;

        }
};
