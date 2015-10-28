/*==================================================================
 *   Copyright (C) 2015 All rights reserved.
 *   
 *   filename:     remove_linked_list_elements.cc
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
        ListNode* removeElements(ListNode* head, int val) {
            ListNode *virt = new ListNode(-1);
            virt->next = head;
            ListNode *p = head;
            ListNode *pre = virt;
            while(p != NULL) {
                if(p->val == val) {
                    if(p->next == NULL) {
                        pre->next = NULL;
                        break;
                    } else {
                        deleteNode(p);
                        p = pre->next;
                    }
                } else {
                    p = p->next;
                    pre = pre->next;
                }
            }
            if(virt->next == NULL) {
                delete virt, p, pre;
                return NULL;    
            } else {
                delete virt, p, pre;
                return head;
            }


        }
        void deleteNode(ListNode* node) {
            ListNode *p = node->next;
            node->val = node->next->val;
            node->next = node->next->next;
            delete p;

        }
};

